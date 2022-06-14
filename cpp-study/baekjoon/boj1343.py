

inp = input()

ans = []
tot = 0
for i in inp:
    if i != '.':
        tot += 1
    else:
        if tot % 2 ==1:
            print(-1)
            exit()
        else:
            #print(tot/4)
            print(tot)
            for j in range(tot//4):
                ans.append("AAAA")
            tot = (tot - tot*(tot//4))
            print(tot)
            for j in range(tot):
                ans.append("B")
            tot=0
            ans.append(".")
#print(tot//4)
if tot != 0:
    if tot % 2 ==1:
            print(-1)
            exit()
    for j in range(tot//4):
        ans.append("AAAA")
    print
    tot = (tot - tot*(tot//4))
    print(tot)
    for j in range(tot):
        ans.append("B")
    

#print(ans)
for i in ans:
    print(i,end='')
    
print()
        
        