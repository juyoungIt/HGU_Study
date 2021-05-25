#HW07(1) mergeSort.py
from copy import*

def mergeSort(list1,list2):
    temp = [] #list result에 추가되는 값들을 저장하는 list
    for number in list2:
        if number in list1:
            if number in temp:
                result.append(number)
            else:
                temp.append(number)
                continue
        else:
            result.append(number)
            temp.append(number)
    result.sort()
    return result

#list1, list2 define
list1 = [3,6,9,12,15,18,18,21,24,27]
list2 = [6,12,18,24,30,30]
print("======================================")
print("list1 = ", list1)
print("list2 = ", list2)
print("======================================")
result = deepcopy(list1)

final_list = mergeSort(list1, list2)
print("final_list = ", final_list)
