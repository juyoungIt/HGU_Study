# date : 2021/03/09
# writer : 21700760 Juyoung Ha

inputOk = False
count = 0
startDay = 0
numberDay = 0

# # enter the data from user(include Exception Handling)
while not inputOk:
    startDay = int(input('Enter the start day (0~6)>> '))
    if startDay < 0 or startDay > 6:
        inputOk = False
        print('Error! - start day value is invalid.')
        continue
    numberDay = int(input('Enter the number of days (1~31)>> '))
    if numberDay < 1 or numberDay > 31:
        inputOk = False
        print('Error! - number of days value is invalid.')
        continue
    inputOk = True

# print header of calendar
for x in ['Sun', 'Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat']:
    print(x + ' ', end='')
print('')

# print empty space of calendar
for y in range(0, startDay):
    print('%3s' % '   ' + ' ', end='')
    count = count+1

# print day number of calendar
for z in range(1, numberDay+1):
    print('%3s' % str(z) + ' ', end='')
    count = count+1
    if count % 7 == 0:
        print('')
        count = 0