#from time import time
import math


def eratos(num):
    #start_t = time()
    sieve = [False, False] + [True] * num
    
    for i in range(2, int(math.sqrt(num))+1):
        if sieve[i]:
            sieve[i*2::i] = [False] * len(sieve[i*2::i])

    #print(time() - start_t)

    #start_t = time()
    return [i for i,x in enumerate(sieve) if x]#, start_t




#li, start_t = eratos(55555555)

li = eratos(200000)


print(li[10000])

#print(time() - start_t)
