n = 1000

maxim = -1

for a in range(1, 1000):
    b = (n**2 - 2*a*n)//(2*n - 2*a)
    c = n - b - a
    if a**2 + b**2 == c**2:
        print(a*b*c)
        break
