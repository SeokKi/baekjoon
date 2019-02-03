from time import time
def somma(n):
   if n==1:
      return 1
   else: 
      return n+somma(n-1)



def sommaquadrata(n):
   if n==1:
      return 1
   else: 
      return n**2+sommaquadrata(n-1)

start_t = time()
print(somma(100)**2-sommaquadrata(100))

print(time() - start_t)
