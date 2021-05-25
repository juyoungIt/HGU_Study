#approxPi.py
import math

def approxPi(error):
    
    i = 0
    result = 0
    while True:
        result += (4/(2*i+1)*(-1)**i)
        add = 4/(2*i+1)
        i = i+1
        if add<=error:
           break
    
    return result


error = float(input("float type argument error를 입력해 주세요. : "))
result = approxPi(error)
print("====================================================")
print("사용자 입력값을 바탕으로 계산한 PI의 근삿값은", result)
