import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel file
dataFrame = pd.read_excel('data_set_train.xlsx')

# ex5 solution part
dong = dataFrame['dong(동)'].unique()
plt.figure(figsize=(75, 50)) # 그래프를 출력하기 위한 figure에 대한 설정
count = 1 # 각 subpolt의 위치를 지정하기 위한 변수
data = [] # 각 data를 저장하기 위한 list
for i in dong:
    tmp = dataFrame[dataFrame['dong(동)'] == i]
    tp = tmp.groupby('yyyyqrt(거래년도 분기별)').mean().copy()
    ls = []
    for j in range(2, len(tp)-2):
        ls.append(tp['price(가격)'].iloc[j-2:j+2].mean()) # 5-MA를 산출
    plt.subplot(6, 2, count) # 그래프를 그려낼 subplot에 대한 설정
    d = pd.DataFrame({'Time' : tp.index.values[2:len(tp)-2], 'Mean_price' : ls})
    # plt.title(i) # 한글 폰트 문제 발생으로 인하여 주석문 처리
    plt.plot(d['Time'], d['Mean_price']) # plot을 그림
    count = count + 1 # count값을 1증가 - 다음위치의 subplot에 plot을 그리기 위함

# 그래프를 출력
plt.show()