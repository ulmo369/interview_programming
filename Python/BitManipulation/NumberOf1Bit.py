n = 11101 #input

res = 0
while n:
    res = res + n%2
    n = n >> 1

print(res)
