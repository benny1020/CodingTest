
n, m, k = map(int, input().split())

data = list(map(int, input().split()))

data.sort()

first = data[n-1]
second = data[n-2]

total = 0

while(True):
    for i in range(k):
        if m==0:
            break
        m-=1
        total+=first
        
    if m == 0: 
        break
    
    m-=1
    total+=second
    
print(total)
        