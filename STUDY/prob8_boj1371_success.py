# 문제
"""
영어에서는 어떤 글자가 다른 글자보다 많이 쓰인다. 예를 들어, 긴 글에서 약 12.31% 글자는 e이다.

어떤 글이 주어졌을 때, 가장 많이 나온 글자를 출력하는 프로그램을 작성하시오.
"""

# 입력
"""
첫째 줄부터 글의 문장이 주어진다. 글은 최대 5000글자로 구성되어 있고, 공백, 알파벳 소문자, 엔터로만 이루어져 있다. 그리고 적어도 하나의 알파벳이 있다.
"""

# 출력
"""
첫째 줄에 가장 많이 나온 문자를 출력한다. 여러 개일 경우에는 알파벳 순으로 앞서는 것부터 모두 공백없이 출력한다.
"""

# 알파벳이 총 26개 있으므로 길이가 26인 배열을 생성하고 모두 0으로 초기화
# a -> 0번째 숫자 ++, b -> 1번째 숫자 ++
# 끝나면 배열에 각각의 문자가 나온 횟수가 저장됨
# 문자를 숫자로 변환할때 아스키코드 사용
import sys



max = 0
max_idx=0


arr = [0 for i in range(26)]



for str in sys.stdin.read():
    if 97 <= ord(str):
        if ord(str) <= 122 : # i가 97~122 즉 a~z인경우 , a는 아스키코드로 97 , z는 122
            arr[ord(str)-97]+=1 # 갯수 하나 더해줌


for i in range(26):
    if max <= arr[i]:
        max_idx = i
        max = arr[i]
for i in range(26):
    if arr[i]==max:
        print(chr(i+97),end='')
