#HW07(2) File_IO.py

import sys

try:
    infile1 = open('in01.txt','r')
    infile2 = open('in02.txt','r')
    outfile = open('result.txt','w')
    slist1 = infile1.readlines()
    slist2 = infile2.readlines()
    if len(slist1)>len(slist2):
        size = len(slist1)
    elif len(slist1)<len(slist2):
        size = len(slist2)
    else:
        size = len(slist1)
        
    for i in range(size):
        for j in range(1):
            if i == len(slist1):
                continue
            else:
                outfile.write(slist1[i])
        for k in range(1):
            if i == len(slist2):
                continue
            else:
                outfile.write(slist2[i])
        
    print("in01.txt = ", slist1)
    print("\n")
    print("in02.txt = ", slist2)
    print("\n")
    print("result.txt =")
    infile1.close()
    infile2.close()
    outfile.close()
    outfile = open('result.txt','r')
    s = outfile.read()
    print(s)
    outfile.close()
    
except IOError as err:
    print("I/O error : {0}", format(err))
    
