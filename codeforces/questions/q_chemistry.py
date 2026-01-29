a = int(input())
for i in range(a):
    b = list(input())
    for j in b:
        if j == ')':
            b.remove(j)