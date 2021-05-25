#HW03_CHtoNum.py

string = input("Input a name : ")
total_value = 0
stringlen = len(string)

for i in range(0, stringlen):
    if string[i] == 'a' or string[i] == 'A':
        value = 26
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'b' or string[i] == 'B':
        value = 25
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'c' or string[i] == 'C':
        value = 24
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'd' or string[i] == 'D':
        value = 23
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'e' or string[i] == 'E':
        value = 22
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'f' or string[i] == 'F':
        value = 21
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'g' or string[i] == 'G':
        value = 20
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'h' or string[i] == 'H':
        value = 19
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'i' or string[i] == 'I':
        value = 18
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'j' or string[i] == 'J':
        value = 17
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'k' or string[i] == 'K':
        value = 16
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'l' or string[i] == 'L':
        value = 15
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'm' or string[i] == 'M':
        value = 14
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'n' or string[i] == 'N':
        value = 13
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'o' or string[i] == 'O':
        value = 12
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'p' or string[i] == 'P':
        value = 11
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'q' or string[i] == 'Q':
        value = 10
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'r' or string[i] == 'R':
        value = 9
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 's' or string[i] == 'S':
        value = 8
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 't' or string[i] == 'T':
        value = 7
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'u' or string[i] == 'U':
        value = 6
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'v' or string[i] == 'V':
        value = 5
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'w' or string[i] == 'W':
        value = 4
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'x' or string[i] == 'X':
        value = 3
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'y' or string[i] == 'Y':
        value = 2
        print(string[i],"=",value)
        total_value = total_value + value
    elif string[i] == 'z' or string[i] == 'Z':
        value = 1
        print(string[i],"=",value)
        total_value = total_value + value
    
print("Total value of '",string,"'is",total_value)


