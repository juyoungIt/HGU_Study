# hw3 exercise4
# writer : 21700760 Juyoung Ha

import numpy as np
import openpyxl

# open data excel file
file = openpyxl.load_workbook('data_set_train.xlsx')
ws = file.active

data = []
col = []
yList = []
year = 2000

for row in ws.iter_rows(min_row=2):
    ls = []
    for cell in row:
        ls.append(cell.value)
    while True:
        if year == int(ls[1][:4]):
            yList.append(ls[2])
            break
        else:
            if len(yList) != 0:
                result = np.array(yList).astype(float)
                print(year, 'avg :', format(np.mean(result), '9.2f'))
                year += 1
                yList = []
                yList.append(ls[2])
                break
            else:
                year += 1
result = np.array(yList).astype(float)
print(year, 'avg :', format(np.mean(result), '9.2f'))