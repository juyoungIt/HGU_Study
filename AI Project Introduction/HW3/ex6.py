# hw3 exercise6
# writer : 21700760 Juyoung Ha

import numpy as np
import openpyxl
import matplotlib.pyplot as plt

# open data excel file
file = openpyxl.load_workbook('data_set_train.xlsx')
ws = file.active

data = []
col = []
yList = []
year = [2000, 'Q', 1]    # represent year and quarter information
label = []               # store label for graph

tradingCount = []    # the list that store the number of trading each quarter
avgTradCount = []    # the list that store the average price of each quarter trading
trade = 0            # the number of each trading per quarter

# go to the next quarter
def changeYear(year):
    if year[2] < 4:
        year[2] += 1
    else:
        year[2] = 1
        year[0] += 1


for row in ws.iter_rows(min_row=2):
    ls = []
    for cell in row:
        ls.append(cell.value)
    while True:
        if "".join(map(str, year)) == ls[1]:
            yList.append(ls[2])
            trade += 1
            break
        else:
            if len(yList) != 0:
                result = np.array(yList).astype(float)
                avgTradCount.append(np.mean(result))  # calculate average price
                tradingCount.append(trade)  # calculate trading count
                label.append("".join(map(str, year)))  # make label for graph
                trade = 0
                changeYear(year)
                yList = []
                yList.append(ls[2])
                break
            else:
                changeYear(year)
result = np.array(yList).astype(float)
avgTradCount.append(np.mean(result)) # calculate average price
tradingCount.append(trade)  # calculate trading count
label.append("".join(map(str, year)))  # make label for graph


# draw graph
plt.figure(figsize=(18, 8))  # set the graph size

# draw bar graph
plt.subplot(211)
plt.xticks(np.arange(1, 48, 1), labels=label)
plt.xticks(fontsize=5)
plt.bar(range(1, 48), tradingCount, width=0.5, align='center', color='black')

# draw graph
plt.subplot(212)
plt.xticks(np.arange(1, 48, 1), labels=label)
plt.xticks(fontsize=5)
plt.plot(range(1, 48), avgTradCount, color='red')
plt.plot(range(1, 48), avgTradCount, 'C0o', alpha=0.5, color='red')
plt.show()