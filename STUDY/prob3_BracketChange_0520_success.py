#https://programmers.co.kr/learn/courses/30/lessons/60058
# 2020 KAKAO BLIND RECRUITMENT
# Level 2 괄호 변환

def is_right(p): #해당 괄호가 올바른 괄호인지 확인 -> 스택 사용
    stack = []
    for i in p:
        if i =="(":
            stack.append('(')
        else:
            if(len(stack) ==0):
                return 0
            else:
                stack.pop()
    return 1

def sol(p): # 문제에 주어진대로 따라함, 재귀함수 사용
    if(p==""):
        return ""
    if(is_right(p)==1):
        return p
    tmp = 0 #u가 다 할당되었는지 확인용, 1인경우 할당완료
    left=0
    right=0
    u=[]
    v=[]
    ans = []
    for i in p:
        if(tmp == 1):
            v.append(i)
        else:
            u.append(i)
        if(i=="("):
            left = left+1
        else:
            right = right+1
        if(left == right): #left와 right 같은경우 u에 할당 끝
            tmp = 1
    #print("u",u)
    #print("v",v)

    if(is_right(u)):
        for i in sol(v):
            u.append(i)
        #print("solv",sol(v))
        return u
    else:
        ans.append('(')
        #print("ans",ans)
        for i in sol(v):
            ans.append(i)
        ans.append(')')
        if(len(u)-2>0):
            for i in range(len(u)-2):
                if u[i+1] == '(':
                    ans.append(')')
                else:
                    ans.append('(')
    #print("a",ans)
    return ans



def solution(p):
    answer = ''
    ans = sol(p)
    #print("ans",ans)
    for i in ans:
        if i == "(":
            answer = answer+"("
        else:
            answer = answer+")"
    #print("answer",answer)
    return answer
