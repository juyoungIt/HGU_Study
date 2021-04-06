import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel file
dataFrame = pd.read_excel('data_set_train.xlsx')

# ex4 solution part
dong = dataFrame['dong(동)'].unique()
plt.figure(figsize=(70,40))
count = 1

for i in dong:
    tmp = dataFrame[dataFrame['dong(동)'] == i]
    tp = tmp.groupby('yyyyqrt(거래년도 분기별)').mean()
    plt.subplot(6, 2, count) # 그래프를 그려낼 subplot에 대한 설정
    plt.plot(tp['price(가격)'])
    count = count + 1

# 그래프를 출력
plt.show()