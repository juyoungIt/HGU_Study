import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel file
dataFrame = pd.read_excel('data_set_train.xlsx')

# 그래프를 그리기 위한 사전세팅
dong = ['Chungdam', 'Apgujeong', 'Dogok', 'Samsung', 'Daechi', 'Gaepo', 'Yeocksam', 'Suseo']
lon = [127.0487, 127.0303, 127.0438, 127.0565, 127.0611, 127.0609, 127.0374, 127.1052]
lat = [37.5232, 37.5317, 37.4898, 37.5140, 37.4995, 37.4790, 37.4999, 37.4890]
data = {'Dong':dong, 'Lat':lat, 'Lng':lon}
dong_data = pd.DataFrame(data=data)

# scatter plot을 그림
plt.scatter(dataFrame['Longtitude(경도)'], dataFrame['Latitude(위도)'], alpha=0.1)
plt.xlabel('Longtitude')
plt.ylabel('Latitude')

for i in range(8):
    plt.text(dong_data['Lng'][i], dong_data['Lat'][i], dong_data['Dong'][i], fontsize=12)
plt.scatter(dong_data['Lng'], dong_data['Lat'], edgecolors='black', c='None', s=2500, alpha=0.3)

plt.show()