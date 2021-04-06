# Exercise7
# writer: 21700760 Juyoung Ha

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# read excel data file
df = pd.read_excel('stockprice_3.xlsx')

# find exist company code
comp = df['Code'].unique()

# declare list for temporary data storing
ls = []

# data reading and draw data plot
for k in range(0, len(comp)):

    plt.figure(k+1, figsize=(50, 30))  # set the figure size

    # collect price data
    compData = df[df['Code'] == comp[k]]    # load each company data

    # draw original graph
    plt.subplot(2, 1, 1)              # set the subplot
    plt.title('Price & Volume Information of ' + comp[k], pad=20, fontsize=20)  # set the title
    plt.xlabel('Date', fontsize=15)   # set the plot-x label
    plt.ylabel('Price', fontsize=15)  # set the plot-y label
    plt.xticks(np.arange(0, len(compData), 30), fontsize=5) # set the xticks
    plt.plot(compData['Date'].astype(str), compData['Price'], label='original')  # draw the result

    # draw price with 3-MA
    ls.clear()
    ls.append(compData['Price'].iloc[0])  # add original data(1)
    for i in range(1, len(compData) - 1):
        ls.append(compData['Price'].iloc[i - 1: i + 1].mean())  # calculate 3-MA
    ls.append(compData['Price'].iloc[len(compData)-1])  # add original data(2)
    plt.subplot(2, 1, 1)   # set the subplot
    plt.plot(compData['Date'].astype(str), ls, label='3-MA')  # draw the result

    # draw price with 5-MA
    ls.clear()
    ls.append(compData['Price'].iloc[0])  # add original data(1)
    ls.append(compData['Price'].iloc[1])  # add original data(2)
    for i in range(2, len(compData) - 2):
        ls.append(compData['Price'].iloc[i - 2: i + 2].mean())  # calculate 5-MA
    ls.append(compData['Price'].iloc[len(compData) - 2])  # add original data(3)
    ls.append(compData['Price'].iloc[len(compData) - 1])  # add original data(4)
    plt.subplot(2, 1, 1)   # set the subplot
    plt.plot(compData['Date'].astype(str), ls, label='5-MA')  # draw the result
    plt.legend()  # print the legend

    # collect volume data
    # draw original graph
    plt.subplot(2, 1, 2)   # set the subplot
    plt.xlabel("Date", fontsize=15)
    plt.ylabel("Volume", fontsize=15)
    plt.xticks(np.arange(0, len(compData), 30), fontsize=5)
    plt.plot(compData['Date'].astype(str), compData['Volume'], label='original')

    # draw volume with 3-MA
    ls.clear()
    ls.append(compData['Volume'].iloc[0])
    for i in range(1, len(compData) - 1):
        ls.append(compData['Volume'].iloc[i - 1: i + 1].mean())  # calculate 3-MA
    ls.append(compData['Volume'].iloc[len(compData)-1])
    plt.subplot(2, 1, 2)   # set the subplot
    plt.plot(compData['Date'].astype(str), ls, label='3-MA')

    # draw volume with 5-MA
    ls.clear()
    ls.append(compData['Volume'].iloc[0])
    ls.append(compData['Volume'].iloc[1])
    for i in range(2, len(compData) - 2):
        ls.append(compData['Volume'].iloc[i - 2: i + 2].mean())  # calculate 3-MA
    ls.append(compData['Volume'].iloc[len(compData) - 2])
    ls.append(compData['Volume'].iloc[len(compData) - 1])
    plt.subplot(2, 1, 2)   # set the subplot
    plt.plot(compData['Date'].astype(str), ls, label='5-MA')
    plt.legend()

# print the plot
plt.show()