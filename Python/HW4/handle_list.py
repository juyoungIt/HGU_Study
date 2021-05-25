#handle_list.py

num_list = []
from copy import*

print("지금부터 10개의 정수를 입력해 주세요.")
for i in range(0,10):
    number = int(input("숫자를 입력해 주세요. : "))
    num_list.append(number)


#problem - 1
print("================================================")
print("Problem 1")
print("변환 전 리스트 : ", num_list) # 변환 전의 리스트 출력
sample = deepcopy(num_list) #리스트 원본을 보호하기 위한 deepcopy 활용
temp = sample[9] # 리스트의 가장 마지막 값을 따로 저장
sample.insert(0,temp) # .insert() 이용하여 맨앞에 리스트의 가장 마지막 값 추가
sample.pop(10) # 리스트의 가장 마지막 값 삭제

print("변환 후 리스트 : ", sample) # 변환 완료된 리스트 출력
print("================================================")

#problem - 2

print("Problem 2")
print("변환 전 리스트 : ", num_list)
sample = deepcopy(num_list) #리스트 원본을 보호하기 위한 deepcopy 활용
sample.pop(4)
sample.pop(4) # 중간에 위치한 2개의 element를 삭제
print("변환 후 리스트 : ", sample)
print("================================================")

#Problem - 3
print("Problem 3")
print("주어진 리스트 : ", num_list)
sample = deepcopy(num_list) #리스트 원본을 보호하기 위한 deepcopy 활용

 #최댓값을 먼저 찾음
for i in range(0,10):
    if i == 0:
        max = sample[i]
    else:
        if max<sample[i]:
            max = sample[i]

 #최댓값을 sample에서 삭제
sample.remove(max)

 #두번째로 큰 값을 찾음
for i in range(0,9):
    if i == 0:
        second_max = sample[i]
    else:
        if second_max<sample[i]:
            second_max = sample[i]

print("주어진 리스트에서 두번째로  큰 수는", second_max,"이다.")
print("================================================")

#Problem - 4
print("Problem 4")
print("주어진 리스트 : ", num_list)

sample = deepcopy(num_list)#리스트 원본을 보호하기 위한 deepcopy 활용

for i in range(0,10):
    for j in range(0,10):
        if sample[i] == sample[j]:
            if i == j:
                continue
            elif i>j:
                continue
            print("exist duplicate elements")
            print("중복되는 값 : ", sample[i])
            print("위치(index) : ",i,j )
            






















