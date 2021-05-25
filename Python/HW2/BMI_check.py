#BMI_check.py

height = int(input("키를 cm 단위로 입력해 주세요. : "))
weight = int(input("몸무게를 입력해 kg 단위로 입력해 주세요. : "))

BMI = weight/(height/100)**2

if BMI < 18.5:
    print("당신의 BMI 수치는", BMI,"이며, 저체중 상태 입니다.")
elif BMI>=18.5 and BMI < 25.0:
    print("당신의 BMI 수치는", BMI,"이며, 정상 상태 입니다.")
elif BMI>=25.0 and BMI < 30.0:
    print("당신의 BMI 수치는", BMI,"이며, 과체중 상태 입니다.")
else:
    print("당신의 BMI 수치는", BMI,"이며, 비만 상태 입니다.")
