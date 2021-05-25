#various_loops.py

#loop1
Sum1 = 0
for i in range(1,101):
    if i%2 == 0:
        Sum1 = Sum1 + i
print("The sum of all odd numbers between 2 and 100 : ", Sum1)

#loop2
Sum2 = 0
for j in range(10,26):
    Sum2 = Sum2 + j
print(Sum2)

#loop3
for k in range(0,21):
    print(3**k)

#loop4
Sum3 = 0
a = int(input("Input first number. : "))
b = int(input("Input second number. : "))
for l in range(a,b+1):
    if l%2 == 0:
        Sum3 = Sum3 + l
average = Sum3 / (b+1-a)
print("The average of all even numbers a and b",average)

#loop5
Sum4 = 0
number = input("Input number : ")
for m in range(0, len(number)):
    if int(number[m])%2 != 0:
        Sum4 = Sum4 + int(number[m])
print("The sum of all odd digits of an input",Sum4)


