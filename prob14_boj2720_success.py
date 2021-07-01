

def sol(num):
    print(num//25, end=' ')
    num -= (num//25)*25
    print(num//10, end=' ')
    num -= (num//10)*10
    print(num//5, end=' ')
    num -= (num//5)*5
    print(num//1)

num = int(input())

for i in range(num):
    tmp = int(input())
    sol(tmp)
