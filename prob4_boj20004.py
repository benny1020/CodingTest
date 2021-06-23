#include <iostream>
#using namespace std;

def is_win(num):
    temp=30;
    while(1):
        temp-=(num+1);
        if temp <=0:
            if num<temp+num+1:
                return 1
            else:
                return 0

if __name__ == "__main__":
    num = int(input())
    for i in range(num):
        if is_win(i+1) == 1:
            print(i+1)
