def IsPrime(x):
    for i in range(2,x):
        if (x%i) == 0:
            return False
        return True

def Factors(x):
    print("The FACTORS are:")
    for i in range(1, x + 1):
        if x % i == 0:
            print(i)
            
def Function(x):
    for i in range(-5,5 + 1):
        if x == 0:
            break
        Y = 8*(x**2) + 1
        print("Result for ", i, "is =",Y)
        x = x - 1
        

x = int(input("Please enter a value: "))

if IsPrime(x) == False:
    Factors(x)

else:
    Function(x)
    