# DictExer.py

gradeCounts = {'A':8,'D':3,'B':15,'F':2,'C':6,'P':7,'I':1}

#1. All the keys
print('===============================================')
print("1. All the keys")
key_list = gradeCounts.keys()
print(key_list)
print('===============================================')
#2. All the values
print("2. All the values")
value_list = gradeCounts.values()
print(value_list)
print('===============================================')
#3. All of the key and value pairs in key order
print("3. All of the key and value pairs in key order")
key_list = list(gradeCounts.keys())
key_list.sort()
result = []
for i in range(len(value_list)):
    print(key_list[i],':',gradeCounts.get(key_list[i]))
for i in range(len(value_list)):
    part = []
    part.append(key_list[i])
    part.append(gradeCounts.get(key_list[i]))
    part = tuple(part)
    result.append(part)
print(result)
print('===============================================')
#4. The average value
print("4. The average value")
total_sum = 0
value_list = list(gradeCounts.values())

for i in range(len(value_list)):
    total_sum = total_sum + value_list[i]
average = total_sum/len(value_list)
print("The average value : ", average)
print('===============================================')
#5. Drawing Chart
print("5. Drawing Chart")
key_list = list(gradeCounts.keys())
key_list.sort()
for i in range(len(value_list)):
    print(key_list[i], ':', '*'*gradeCounts.get(key_list[i]))   
print('===============================================')
