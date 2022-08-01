inp = str(input())
print(inp)
flag = inp[0]

cnt_zero = 0
cnt_one = 0
if flag == '0':
    cnt_zero += 1
else:
    cnt_one + 1
for i in inp:
    if i != flag:
        flag = i
        if i == '0':
            cnt_zero+=1
        else:
            cnt_one+=1
#print(cnt_zero)
#print(cnt_one)
if(cnt_zero > cnt_one):
    print(cnt_one)
else:
    print(cnt_zero)