# 문제
"""
다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다.
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오.
(6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
"""

# 입력
"""
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수 또는 0이다.
"""

# 출력
"""
첫째 줄에 필요한 세트의 개수를 출력한다.
9999 -> 2
"""

# 한세트라는게 2개들어있다는 뜻인듯 아니네XXX 1세트 -> 0~9
# 숫자 각자리마다 분리해야댐 ->10의 제곱승으로 계속 나눔 몫이 0일때까지
import math
def digit(num): #자릿수 구해주는 함수
    k=1
    dig = 10
    while(1):
        if num // dig == 0:
            return k
        else:
            k+=1
            dig *=10

num = int(input())
if num == 0:
    print(1)
    exit(0)
dig = digit(num) #자릿수
div = pow(10,dig-1)
#print(div)
#0부터 8까지 배열 선언 그리고 9는 6으로
arr = [0 for i in range(9)]

for i in range(dig):
    if div == 1:
        if num==9:
            arr[6]+=1
        else:
            arr[num]+=1
        break
    d = num // div
    #print("d ",d)
    if(d == 9):
        arr[6]+=1
    else:
        arr[d]+=1
    num-=div*d
    div = int(div/10)
max = 0
arr[6] = math.ceil(arr[6]/2)
for i in range(8):
    if(max < arr[i]):
        max = arr[i]
print(max)
