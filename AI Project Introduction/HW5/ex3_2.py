import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel file
dataFrame = pd.read_excel('data_set_train.xlsx')

# data와 관련된 세팅
dong = ['Chungdam', 'Apgujeong', 'Dogok', 'Samsung', 'Daechi', 'Gaepo', 'Yeocksam', 'Suseo']
lon = [127.0487, 127.0303, 127.0438, 127.0565, 127.0611, 127.0609, 127.0374, 127.1052]
lat = [37.5232, 37.5317, 37.4898, 37.5140, 37.4995, 37.4790, 37.4999, 37.4890]
data = {'Dong':dong, 'Lat':lat, 'Lng':lon}
dong_data = pd.DataFrame(data=data)

# data1과 관련된 세팅
data1 = dataFrame[['yyyyqrt(거래년도 분기별)', 'price(가격)', 'dong(동)', 'Latitude(위도)', 'Longtitude(경도)', 'Seoul_l.rate(지가상승률)', 'dis_subway(지하철역과의 거리)']]

# data2와 관련된 세팅
data2 = data1.copy()
data2.columns = ['yearqrt', 'price', 'dong', 'Lat', 'Lng', 'rate', 'station_dist']

# data_gaepo와 관련된 세팅
data_gaepo = data2[data2['dong'] == '개포동']
data_gaepo_time = data_gaepo.groupby('yearqrt').mean()
print(data_gaepo_time)

# data_gaepo_time을 그래프로 그리는 부분
plt.figure(figsize=(60,30))
plt.plot(data_gaepo_time['price'])


'''
# 그래프를 그리는 부분
plt.figure(figsize=(25, 15))
plt.scatter(x=data2['Lng'], y=data2['Lat'], c=data2['price'], cmap=plt.cm.Reds)
plt.colorbar(label='color')
for i in range(8):
    plt.text(dong_data['Lng'][i], dong_data['Lat'][i], dong_data['Dong'][i], fontsize=12)
plt.scatter(dong_data['Lng'], dong_data['Lat'], edgecolors='black', c='None', s=15000, alpha=0.3)
plt.xlabel('Longtitude')
plt.ylabel('Latitude')
'''


'''
# scatter plot을 그림
plt.scatter(dataFrame['Longtitude(경도)'], dataFrame['Latitude(위도)'], alpha=0.1)
plt.xlabel('Longtitude')
plt.ylabel('Latitude')

for i in range(8):
    plt.text(dong_data['Lng'][i], dong_data['Lat'][i], dong_data['Dong'][i], fontsize=12)
plt.scatter(dong_data['Lng'], dong_data['Lat'], edgecolors='black', c='None', s=2500, alpha=0.3)
'''

# 그래프를 출력
plt.show()