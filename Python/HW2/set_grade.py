#set_grade.py

score = float(input("Input your score : "))
grade_type = input("Input Letter of PF : ")

if grade_type == "Letter":
    if score>=90 and score<=100:
        print("Your grade is A")
    elif score>=80 and score<90:
        print("Your grade is B")
    elif score>=70 and score<80:
        print("Your grade is C")
    elif score>=60 and score<70:
        print("Yout grade is D")
    elif score>=0 and score<60:
        print("Your grade is F")
    else:
        print("Please check your score! It has a problem.")
        
elif grade_type == "PF":
    if score>=60 and score<=100:
        print("Your grade is Pass")
    elif score>=0 and score<60:
        print("Your grade is F")
    else:
        print("Please check your score! It has a problem.")
        
