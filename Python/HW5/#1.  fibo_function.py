def fibo(size):
    fibo_list=[]
    for i in range(0,size):
        if i == 0:
            fibo_list.append(1)
        elif i == 1:
            fibo_list.append(1)
        else:
            a = fibo_list[i-2] + fibo_list[i-1]
            fibo_list.append(a)
    for i in range(0,size):
        print(fibo_list[i],end="\t")

size = int(input("출력할 피보나치 수열의 size를 입력해 주세요. : "))
fibo(size)
