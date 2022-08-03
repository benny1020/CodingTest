def solution(numbers):
    
    li = []
    for i in range(len(numbers)):
        for j in range(i+1,len(numbers)):
            li.append(int(numbers[i]+numbers[j]))
    li = list(set(li))
    li.sort()
    return li