import h5py
import numpy as np
import os

input_hdf5_path = os.path.join(os.path.dirname(__file__), "training_data.h5")
output_hdf5_path = os.path.join(os.path.dirname(__file__), "training_data_rewards.h5")

input_dataset = "train_model_data"
output_dataset = "train_model_data_rewards"

def angle_to_target(p2_yaw, p2_x, p2_y, target_x, target_y):
    desired_yaw = np.degrees(np.arctan2(target_y - p2_y, target_x - p2_x))
    delta = (desired_yaw - p2_yaw + 540) % 360 - 180
    return delta

with h5py.File(input_hdf5_path, "r") as h5in:
    data = h5in[input_dataset][:]

    reward_data = []

    for i in range(1, len(data)):
        inputs = data[i]
        prev = data[i - 1]

        reward = np.zeros(7, dtype=np.float32)
        p2_sees_p1 = inputs[13]
        p2_x, p2_y, p2_yaw = inputs[14], inputs[15], inputs[16]
        p1_x, p1_y = inputs[24], inputs[25]
        flag_states = inputs[34:38]
        flag_positions = inputs[5:13].reshape(4, 2)
        wall_rays = inputs[38:46]

        moves = inputs[17:21]
        rotates = inputs[21:23]
        shoot = inputs[23]

        prev_pos = np.array([prev[14], prev[15]])
        cur_pos = np.array([p2_x, p2_y])
        pos_change = np.linalg.norm(cur_pos - prev_pos)
        if pos_change < 5 and np.any(moves > 0.1):
            reward[:4] -= 0.3
        
        if p2_sees_p1:
            angle_diff = angle_to_target(p2_yaw, p2_x, p2_y, p1_x, p1_y)
            if abs(angle_diff) < 10:
                if shoot > 0.5:
                    reward[6] = 1.0
                reward[4:6] = 0.0
            elif angle_diff > 10:
                reward[5] = 0.2
            elif angle_diff < -10:
                reward[4] = 0.2
            else:
                reward[6] = -0.2
        else:
            closest = None
            best_dist = float("inf")
            for idx, state in enumerate(flag_states):
                if state == 1:
                    fx, fy = flag_positions[idx]
                    dist = np.linalg.norm([fx - p2_x, fy - p2_y])
                    if dist < best_dist:
                        best_dist = dist
                        closest = (fx, fy)

            if closest:
                fx, fy = closest
                dist = np.linalg.norm([fx - p2_x, fy - p2_y])
                factor = (1.0 - min(dist, 500) / 500.0)
                reward[0] += 0.3 + factor * 0.3
                reward[3] -= 0.2
                angle_diff = angle_to_target(p2_yaw, p2_x, p2_y, fx, fy)
                if abs(angle_diff) > 15:
                    reward[4 if angle_diff < 0 else 5] += 0.15

        if not p2_sees_p1 and np.sum(wall_rays[:3]) < 1.0:
            if rotates[0] > 0.5 and rotates[1] < 0.1:
                reward[4] -= 0.4
            if rotates[1] > 0.5 and rotates[0] < 0.1:
                reward[5] -= 0.4

        if np.sum(wall_rays[:3]) > 1.5:
            reward[0] -= 0.4
        if np.sum(wall_rays[5:]) > 1.5:
            reward[3] -= 0.3

        real_output = inputs[17:24]
        final_output = np.clip(np.maximum(real_output, reward), 0.0, 1.0)
        reward_data.append(np.concatenate((inputs, final_output)))

reward_data = np.array(reward_data, dtype=np.float32)
with h5py.File(output_hdf5_path, "w") as f:
    f.create_dataset(output_dataset, data=reward_data)
