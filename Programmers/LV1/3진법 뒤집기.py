def solution(n):
    digit = 0
    while(1):
        if (3**digit)>n:
            break
        else:
            digit+=1
    s=""
    
    for i in range(digit):
        div = (n // 3**(digit-i-1))
        s+=str(div)
        n -= (3**(digit-i-1)*div)
    answer = 0
    for i in range(digit):
        answer += int(s[i])*3**i
    
    return answer