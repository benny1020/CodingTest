
l1 = [1,2]
l2 = [3,4,5]

p = "1 2 3"

pl = p.split()

for i in range(len(pl)):
    pl[i] = int(pl[i])

print(pl)
