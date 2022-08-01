inp = list(map(int,input().split()))
inp.sort()

groupNum = 0 # 총 그룹 수
count = 0 # 현재 그룹에 포함된 모험가의 수
    
for i in inp:
    count += 1
    if(count>=i):
        groupNum+=1
        count = 0
    
    

print(groupNum)
