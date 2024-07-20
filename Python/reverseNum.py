n=123456789
ans=0
while num > 0:
    aux=n%10
    ans=ans*10+aux
    num=num//10

print(ans)