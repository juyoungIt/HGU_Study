import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel file
dataFrame = pd.read_excel('data_set_train.xlsx')

# ex6_1
df2006Q1 = dataFrame[dataFrame['yyyyqrt(거래년도 분기별)'] == '2006Q1']
print(df2006Q1)