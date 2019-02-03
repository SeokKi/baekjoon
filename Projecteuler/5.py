import time

def prime_factor(num):
     n = 1
     dic = {}  #dictionary
     while num>1:
          n+=1
          if(num%n == 0):
               num = num/n
               if not dic.get(n):
                    dic[n] = 1
               dic[n] = dic[n]*n
               n-=1
          
     return dic
start_t = time.time()

dic = {}

ans = 1



for num in range(1,21):
     for key, val in prime_factor(num).items():
          dicOri = dic.get(key)
          if dicOri is None:
               dicOri = 0
          dic[key] = dicOri if val < dicOri else val
          
mult = 1
for val in dic.values():
     mult *= val

print(mult)
print(time.time()-start_t)


#0.015 secs

