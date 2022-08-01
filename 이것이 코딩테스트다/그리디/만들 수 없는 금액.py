inp = input()

arr = list(map(int,input().split()))
arr.sort()

target = 1

# 1 1 2 2 5 6
for x in arr:
    if target < x:
        break
    target += x
    
print(target)