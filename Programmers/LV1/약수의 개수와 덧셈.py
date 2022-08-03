def check_num(num) :
    if int(num**(1/2))**2 == num:
        return False
    else:
        return True

def solution(left, right):
    answer = 0
    for i in range(left,right+1):
        if(check_num(i)):
            answer+=i
        else:
            answer-=i
            
    return answer

