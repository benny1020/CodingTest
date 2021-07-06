# 잃어버린 괄호
"""
문제
세준이는 양수와 +, -, 그리고 괄호를 가지고 식을 만들었다.
그리고 나서 세준이는 괄호를 모두 지웠다.

그리고 나서 세준이는 괄호를 적절히 쳐서 이 식의 값을
최소로 만들려고 한다.

괄호를 적절히 쳐서 이 식의 값을 최소로 만드는 프로그램을 작성하시오.

입력
첫째 줄에 식이 주어진다. 식은 ‘0’~‘9’, ‘+’, 그리고 ‘-’만으로
이루어져 있고, 가장 처음과 마지막 문자는 숫자이다.
그리고 연속해서 두 개 이상의 연산자가 나타나지 않고,
5자리보다 많이 연속되는 숫자는 없다. 수는 0으로 시작할 수 있다.
입력으로 주어지는 식의 길이는 50보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.
"""
# 뒤에서부터 보는게 중요!!
# digit과 num을 이용해 숫자로 변환
# +를 만나면 sum에 num을 추가
# -를 만나면 sum을 total에서 빼줌
# 만약 식이 다 끝나면 total 에 num과 sum을 더해줌

expression = input()

total = 0
num=0
digit = 0
sum = 0
i=len(expression)-1
while(i>=0):
    if expression[i] == '-':
        sum += num
        total -= sum
        num=0
        sum=0
        digit=0
    elif expression[i] == '+':
        sum+=num
        num=0
        digit=0
    else:
        num+= (( ord(expression[i])-ord('0'))*(10**digit))
        digit+=1
    i-=1
total += (num+sum)
print(total)
