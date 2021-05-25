#GuessNumbers.py
import random

count = 0
trying = 0 # 시행횟수를 저장하는 변수선언 및 초기화
strike = 0 # 스트라이크 값을 저장하는 변수선언 초기화
ball = 0 # 볼 값을 저장하는 변수선언 초기화

com_number = []
user_number = []
for i in range(0,4):
    com_number = random.sample(range(1,10),4)
print(com_number)

def check_list(listname,input_num):
    if len(listname) == 0:
        return 1
    else:
        for i in range(0,len(listname)):
            if input_num in listname:
                return 2
            else:
                return 1
            
while strike != 4:
    user_number = []
    while count < 4:
        number = input("1에서 9 사이의 숫자 입력 : ")
        result = check_list(user_number, number)
        if result == 1:
           user_number += number
           count += 1
        elif result == 2:
           print("중복된 값 존재...다시 입력")
           continue


    strike = 0 
    ball = 0
    count = 0
    for i in range(0,4):
       for j in range(0,4):
          if str(com_number[i])== user_number[j] and i == j:
             strike+=1
          elif str(com_number[i])== user_number[j] and i != j:
             ball+=1    
         
    print(strike,"-strike, ",ball,"-ball")
    trying+=1
    
print("You win! on",trying,"try.")
    





    
    

    
