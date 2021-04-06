import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel file
dataFrame = pd.read_excel('data_set_train.xlsx')

dataFrame[dataFrame['Yongpae(용적률)'].isnull()] = dataFrame['Yongpae(용적률)'].mean()
print(dataFrame.info())