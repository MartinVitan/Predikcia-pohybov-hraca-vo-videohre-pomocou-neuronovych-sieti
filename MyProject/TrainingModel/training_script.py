import h5py
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import Dataset, DataLoader
import os

SEQ_LEN = 10
hdf5_path = os.path.join(os.path.dirname(__file__), "training_data.h5")
dataset_name = "train_model_data"

with h5py.File(hdf5_path, 'r') as h5f:
    data = h5f[dataset_name][:]
    print("Dataset načítaný. Shape:", data.shape)

MAX_POS = 8200.0
MAX_TIMER = 180.0

data[data == -2.0] = 0.0
data[data == -1.0] = 0.0

data[:, 0] /= MAX_TIMER

data[:, 1:5] /= MAX_POS

data[:, 5:13] /= MAX_POS

data[:, 14:16] /= MAX_POS

data[:, 16] = (data[:, 16] + 180.0) / 360.0

data[:, 24:26] /= MAX_POS
data[:, 26] = (data[:, 26] + 180.0) / 360.0

if data.shape[1] >= 49:
    data[:, 46:48] /= 4.0
    data[:, 48] /= 2.0

    for i in range(49, data.shape[1], 4):
        if i + 1 < data.shape[1]:
            data[:, i] /= MAX_POS
            data[:, i + 1] /= MAX_POS
        if i + 2 < data.shape[1]:
            data[:, i + 2] /= 2.0

output_indices = list(range(17, 24))
input_indices = [i for i in range(data.shape[1]) if i not in output_indices]

X_all = data[:, input_indices]
y_all = data[:, output_indices]

X_seq = []
y_seq = []
for i in range(len(X_all) - SEQ_LEN):
    X_seq.append(X_all[i:i+SEQ_LEN])
    y_seq.append(y_all[i+SEQ_LEN - 1])

X_seq = np.array(X_seq, dtype=np.float32)
y_seq = np.array(y_seq, dtype=np.float32)

class SequenceDataset(Dataset):
    def __init__(self, X, y):
        self.X = torch.tensor(X, dtype=torch.float32)
        self.y = torch.tensor(y, dtype=torch.float32)

    def __len__(self):
        return len(self.X)

    def __getitem__(self, idx):
        return self.X[idx], self.y[idx]

dataset = SequenceDataset(X_seq, y_seq)
dataloader = DataLoader(dataset, batch_size=64, shuffle=True)

class LSTMModel(nn.Module):
    def __init__(self, input_size, hidden_size=64, output_size=7):
        super(LSTMModel, self).__init__()
        self.lstm = nn.LSTM(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        _, (hn, _) = self.lstm(x)
        out = self.fc(hn.squeeze(0))
        return self.sigmoid(out)

model = LSTMModel(input_size=X_seq.shape[2])

criterion = nn.BCELoss()
optimizer = optim.Adam(model.parameters(), lr=0.001)
num_epochs = 50

print("\nZačiatok tréningu LSTM modelu...")
for epoch in range(num_epochs):
    total_loss = 0.0
    for batch_X, batch_y in dataloader:
        outputs = model(batch_X)
        loss = criterion(outputs, batch_y)

        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        total_loss += loss.item()

    print(f"Epoch {epoch+1}/{num_epochs} - Loss: {total_loss/len(dataloader):.4f}")

save_path = os.path.join(os.path.dirname(__file__), "trained_model.pt")
torch.save(model.state_dict(), save_path)
print(f"\nModel uložený: {save_path}")