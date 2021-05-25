# 리스트 수와 element수에 영향을 받지 않게 능동적으로 작성함.

def N_find (listname, string):
    F_index = [] # index값을 저장할 배열선언
    for i in range(0, len(listname)):
        for j in range(0, len(listname[i])):
            if string in listname[i]:
                F_index.append(i)
                break
    if len(F_index) == 0: # 동일한 문자 또는 문자열이 없는지 체크
        return -1
    return F_index

#리스트에 대한 내용은 여기에서 변경해 주어야 함.
fr = ["apple", "banana", "lime", "blueberry", "strawberry"]

print("현재 설정되어있는 list : ", fr)
string = input("어떤 문자를 찾아볼까요? : ")
result = N_find(fr, string)
print(result)
