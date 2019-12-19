import time
import sys

def numUniqueTrees(n):
    subprods = [(n+k)/k for k in range(2,n+1)]

    prod =1
    for subprod in subprods:
        prod *= subprod
    
    return prod

if __name__=="__main__":
    num = int(sys.argv[1])
    
    start = time.time()
    ans = numUniqueTrees(num)
    start = time.time()-start
    print("Num trees {0} for {1}, execution time {2}".format(ans,num,start))