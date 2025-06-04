import os
import pandas as pd
import h5py
import numpy as np

def get_max_columns(csv_dir):

    max_col = 0

    for f in os.listdir(csv_dir):
        if f.endswith('.csv'):
            f_path = os.path.join(csv_dir, f)
            with open(f_path, 'r') as f:
                for l in f:
                    num_col = l.count(',') + 1
                    max_col = max(max_col, num_col)
    return max_col

def multiple_cvs_to_hdf5(csv_dir, hdf5_file_path, DS_name = "train_model_data"):

    max_col = get_max_columns(csv_dir)

    rows = []

    for f in os.listdir(csv_dir):
        if f.endswith('.csv'):
            f_path = os.path.join(csv_dir, f)
            with open(f_path, 'r') as file:
                for line in file:
                    vals = []
                    for i in line.strip().split(','):
                        vals.append(float(i))
                    if len(vals) < max_col:
                        vals.extend([-2.0] * (max_col - len(vals)))
                    rows.append(vals)
    
    data_array = np.array(rows, dtype = np.float32)

    with h5py.File(hdf5_file_path, 'w') as h5f:
        h5f.create_dataset(DS_name, data = data_array)

if __name__ == "__main__":
    csv_dir = os.path.join(os.path.dirname(__file__), '..', 'Data')
    hdf5_file_path = os.path.join(os.path.dirname(__file__), 'training_data.h5')
    multiple_cvs_to_hdf5(csv_dir, hdf5_file_path)