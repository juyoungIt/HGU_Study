# date : 2021/03/09
# writer : 21700760 Juyoung Ha

size = int(input('Enter the star size >> '))

for x in range(0, size):
    for y in range(0, x):
        print(' ', end='')
    for z in range(size, x, -1):
        print('*', end='')
    print('')
