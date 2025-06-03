import torch
import torch.nn as nn
import socket
import numpy as np
from collections import deque

SEQ_LEN = 10
INPUT_SIZE = 58
OUTPUT_SIZE = 7

MAX_POS = 8200.0
MAX_TIMER = 180.0

class LSTMModel(nn.Module):
    def __init__(self, input_size=INPUT_SIZE, hidden_size=64, output_size=OUTPUT_SIZE):
        super(LSTMModel, self).__init__()
        self.lstm = nn.LSTM(input_size, hidden_size, batch_first=True)
        self.fc = nn.Linear(hidden_size, output_size)
        self.sigmoid = nn.Sigmoid()

    def forward(self, x):
        _, (hn, _) = self.lstm(x)
        out = self.fc(hn.squeeze(0))
        return self.sigmoid(out)

model = LSTMModel()
model.load_state_dict(torch.load("trained_model.pt"))
model.eval()

HOST = '127.0.0.1'
PORT = 5005

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((HOST, PORT))
server.listen(1)
print(f"Model server beží na {HOST}:{PORT}...")

conn, addr = server.accept()
print(f"Pripojený klient z {addr}")

history = deque(maxlen=SEQ_LEN)

while True:
    data = conn.recv(4096)
    print("Received input of size:", len(data))
    if not data:
        print("Prijatý prázdny vstup, ignorujem.")
        continue

    input_array = np.frombuffer(data, dtype=np.float32).copy()

    if len(input_array) < INPUT_SIZE:
        padding = np.full(INPUT_SIZE - len(input_array), -2.0, dtype=np.float32)
        input_array = np.concatenate([input_array, padding])
    elif len(input_array) > INPUT_SIZE:
        input_array = input_array[:INPUT_SIZE]

    input_array[input_array == -2.0] = 0.0
    input_array[input_array == -1.0] = 0.0

    input_array[0] /= MAX_TIMER
    input_array[1:5] /= MAX_POS
    input_array[5:13] /= MAX_POS
    input_array[14:16] /= MAX_POS
    input_array[16] = (input_array[16] + 180.0) / 360.0
    input_array[24:26] /= MAX_POS
    input_array[26] = (input_array[26] + 180.0) / 360.0
    input_array[48:52] /= MAX_POS

    history.append(input_array)

    if len(history) < SEQ_LEN:
        output = np.zeros(OUTPUT_SIZE, dtype=np.float32)
    else:
        seq_input = np.array(history, dtype=np.float32).reshape(1, SEQ_LEN, INPUT_SIZE)
        input_tensor = torch.from_numpy(seq_input)
        with torch.no_grad():
            output = model(input_tensor).numpy().astype(np.float32)
            output = output.flatten()

        if output[0] > output[2]:
            output[2] = 0.0
        else:
            output[0] = 0.0

        if output[1] > output[3]:
            output[3] = 0.0
        else:
            output[1] = 0.0

        if output[4] > output[5]:
            output[5] = 0.0
        else:
            output[4] = 0.0

    conn.sendall(output.tobytes())

conn.close()
