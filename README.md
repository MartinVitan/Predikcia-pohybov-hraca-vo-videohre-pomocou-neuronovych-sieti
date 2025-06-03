# Predikcia pohybov hráča vo videohre pomocou neurónových sietí

Tento projekt implementuje systém na predikciu správania hráča v splitscreen videohre pomocou neurónových sietí. Cieľom je vytvoriť natrénovaný model UI, ktorý dokáže na základe zaznamenaných dát predvídať akcie protihráča. Projekt bol vytvorený v Unreal Engine 5 a využíva modely trénované v Pythone.

Na trénovanie boli použité dve architektúry neurónových sietí:

- **Učenie s učiteľom** – model predikuje kombináciu vstupov na základe predchádzajúcej sekvencie stavov
- **Učenie posilňovaním** – model dostáva odmeny za akcie

Oba modely využívajú architektúru **LSTM (Long Short-Term Memory)** a sú implementované v **PyTorch**.

## Štruktúra projektu

TrainingModel/
├── convert_data.py # CSV -> HDF5 (supervised model)
├── convert_data_rewards.py # HDF5 -> HDF5 s odmenami (reward model)
├── training_script.py # Tréning modelu (supervised model)
├── training_script_reward.py # Tréning modelu (reward model)
├── inference_server.py # Inferencia modelu (supervised model)
├── inference_server_reward.py # Inferencia modelu (reward model)
├── trained_model.pt # Natrénovaný model učenia s učiteľom
├── trained_model_reward.pt # Natrénovaný model učenia posilňovaním

Data/
├── Game_YYYY-MM-DD-HH-MM-SS.csv # Zaznamenané dáta zo zápasov vo formáte CSV

Source/MyProject/
├── DataCollector.cpp # Implementácia komponentu ADataCollector
├── DataCollector.h # Deklarácia triedy ADataCollector

README.md
requirements.txt # Zoznam použitých knižníc

## Návod na použitie

### 1. Inštalácia závislostí
pip install -r requirements.txt

### 2. Konverzia dát
python convert_data.py
python convert_data_rewards.py

### 3. Trénovanie modelov
python training_script.py
python training_script_reward.py

### 4. Spustenie inferencie
Inferenčný server musí byť manuálne spustený pred zapnutím herného módu P1 vs AI.

python inference_server.py
alebo
python inference_server_reward.py
