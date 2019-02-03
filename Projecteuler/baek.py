#n = int(input())

n = 10
count = 0
def bfs(num):
    global count
    if num == 1:
        print(count)
        return
    count += 1
    if num%3==0:
        bfs(num/3)
    elif num%2==0:
        bfs(num/2)
    else:
        bfs(num-1)

bfs(n)

##li = [0]*(n+1)
##
##li[1] = 0
##
##for i in range(2, n+1):
##        
##    li[i] = li[i-1] + 1
##
##    if i%2 == 0:
##        li[i] = min(li[i], li[int(i/2)]+1)
##    if i%3 == 0:
##        li[i] = min(li[i], li[int(i/3)]+1)
##
##
##
##
##print(li[n])
##    
