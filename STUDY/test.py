inp = "java and backend and junior and pizza 100"

k = inp.split(" and ")
tmp = k[3]
k.pop()
for j in tmp.split(' '):
    k.append(j)
print(k)
