# hw3 exercise5
# writer : 21700760 Juyoung Ha

import numpy as np
import openpyxl

# open data excel file
file = openpyxl.load_workbook('data_set_train.xlsx')
ws = file.active

data = []
col = []
yList = []
year = [2000, 'Q', 1]  # represent year and quarter information


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
            break
        else:
            if len(yList) != 0:
                result = np.array(yList).astype(float)
                if year[2] == 4:
                    print("".join(map(str, year)), 'avg :', format(np.mean(result), '9.2f'))
                else:
                    print("".join(map(str, year)), 'avg :', format(np.mean(result), '9.2f'), end='    ')
                changeYear(year)
                yList = []
                yList.append(ls[2])
                break
            else:
                changeYear(year)
result = np.array(yList).astype(float)
if year[2] == 4:
    print("".join(map(str, year)), 'avg :', format(np.mean(result), '9.2f'))
else:
    print("".join(map(str, year)), 'avg :', format(np.mean(result), '9.2f'), end='')