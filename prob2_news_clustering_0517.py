#include <iostream>
#include <cstring>
#include <math>
#define MAX_ALPHA 26
#using namespace std;

def is_alpha(ch):
    if  ( ord(ch)>=65 and ord(ch)<=90 ) or (ord(ch)>=97 and ord(ch)<=122) :
        return 1
    else:
        return 0

if __name__ == "__main__":
    MAX_ALPHA=26
    str1 = "FRANCE"
    str2 = "french"

    dp1 = [[0 for col in range(MAX_ALPHA)] for row in range(MAX_ALPHA)]
    dp2 = [[0 for col in range(MAX_ALPHA)] for row in range(MAX_ALPHA)]
    max = 0;
    min = 0;


    for i in range(len(str1)-1):
        #print(str1[i],str1[i+1])
        if is_alpha(str1[i]) and is_alpha(str1[i+1]):
            tmp_1 = ord(str1[i])
            tmp_2 = ord(str1[i+1])
            if tmp_1 <=90:
                tmp_1+=32
            if tmp_2 <=90:
                tmp_2+=32
            tmp_1 -=97
            tmp_2 -=97
            dp1[tmp_1][tmp_2]=dp1[tmp_1][tmp_2]+1
    for i in range(len(str2)-1):
        if is_alpha(str2[i]) and is_alpha(str2[i+1]):
            #print(str1[i],str1[i+1])
            tmp_1 = ord(str2[i])
            tmp_2 = ord(str2[i+1])
            if tmp_1 <=90:
                tmp_1+=32
            if tmp_2 <=90:
                tmp_2+=32
            tmp_1 -=97
            tmp_2 -=97
            dp2[tmp_1][tmp_2]=dp2[tmp_1][tmp_2]+1

    for i in range(MAX_ALPHA):
        for j in range(MAX_ALPHA):
            if dp1[i][j] >= dp2[i][j]:
                max= max+dp1[i][j]
                min= min+dp2[i][j]
            else:
                max=max+dp2[i][j]
                min=min+dp1[i][j]



    answer = 0
    if max == 0 and min ==0:
        answer = 65536
    else:
        answer = int( float(min)/float(max)*65536)
    print(answer)
