import math

def is_pail(num):
     li = [num//(10 ** x)%10 for x in range(int(math.log10(num)), -1, -1)]
     return li == li[::-1]


ans = []
for i in range(999, 99, -1):
    for j in range(999, 99, -1):
        if(is_pail(i*j)):
            ans.append(i*j)
print(max(ans))



# 3.9 secs.    
# if is_pail => str(i*j) == str(i*j)[::-1] 
# 0.88 secs
