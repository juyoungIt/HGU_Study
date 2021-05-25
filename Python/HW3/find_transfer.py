#HW03_find_transfer.py

I_string = input("Input a sentence : ")
S_string = input("Input a word for search : ")

I_string = I_string.lower()
S_string = S_string.lower()

S_length = len(S_string)
start = 0
S_count = 0

while 1:
    index = I_string.find(S_string,start)
    if index != -1:
        S_count = S_count + 1
        start = index+S_length
    else:
        break

print("A word '",S_string,"' appears ",S_count,"times in the sentence.")
result = I_string.replace(S_string,S_string.upper())
print(result)
