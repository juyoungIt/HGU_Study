# easyCrypto.py


def easyCrypto(string):
    sample1 = 'abcdefghijklmnopqrstuvwxyz' # 소문자의 나열
    sample2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' # 대문자의 나열
    convert1 = 'badcfehgjilknmporqtsvuxwzy'
    convert2 = 'BADCFEHGJILKNMPORQTSVUXWZY'
    result = [] # 암호화 결과를 저장하는 리스트 선언
    hint1 = list(zip(sample1,convert1))
    hint2 = list(zip(sample2,convert2))
    print(hint1)
    print('===================================================')
    print(hint2)

    for letter in string:
        if letter in sample1:
            for i in range(len(sample1)):
                if letter == hint1[i][0]:
                    result.append(hint1[i][1])
        elif letter in sample2:
            for i in range(len(sample2)):
                if letter == hint2[i][0]:
                    result.append(hint2[i][1])
    return result
                
            
s1 = input("문자열 입력 : ")
print('===================================================')
convert_result = easyCrypto(s1)
delimiter = ''
result = delimiter.join(convert_result)
print('===================================================')
print("암호화한 결과는 다음과 같습니다.")
print(result)
