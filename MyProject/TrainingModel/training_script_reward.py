import torch
import torch.nn as nn
from torch.utils.data import DataLoader, TensorDataset
import h5py
import numpy as np

INPUT_SIZE = 65
OUTPUT_SIZE = 7
SEQ_LEN = 10
BATCH_SIZE = 128
EPOCHS = 10

class RewardLSTM(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super().__init__()
        self.lstm = nn.LSTM(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        _, (hn, _) = self.lstm(x)
        return self.sigmoid(self.fc(hn.squeeze(0)))

with h5py.File("training_data_rewards.h5", "r") as f:
    data = f["train_model_data_rewards"][:]
    print("Načítaný reward dataset. Shape:", data.shape)

input_data = data[:, :INPUT_SIZE]
target_data = data[:, INPUT_SIZE:]
target_data = np.clip(target_data, 0.0, 1.0)

X, y = [], []
for i in range(len(input_data) - SEQ_LEN):
    X.append(input_data[i:i+SEQ_LEN])
    y.append(target_data[i+SEQ_LEN-1])

X = np.array(X, dtype=np.float32)
y = np.array(y, dtype=np.float32)

dataset = TensorDataset(torch.from_numpy(X), torch.from_numpy(y))
loader = DataLoader(dataset, batch_size=BATCH_SIZE, shuffle=True)

model = RewardLSTM(INPUT_SIZE, 64, OUTPUT_SIZE)
optimizer = torch.optim.Adam(model.parameters(), lr=0.001)
criterion = nn.BCELoss()

print("\nZačiatok tréningu reward modelu...")

for epoch in range(EPOCHS):
    total_loss = 0
    for batch_x, batch_y in loader:
        optimizer.zero_grad()
        outputs = model(batch_x)
        loss = criterion(outputs, batch_y)
        loss.backward()
        optimizer.step()
        total_loss += loss.item()
    print(f"Epoch {epoch+1}/{EPOCHS} - Loss: {total_loss:.4f}")

torch.save(model.state_dict(), "trained_model_reward.pt")
print("Reward model uložený.")