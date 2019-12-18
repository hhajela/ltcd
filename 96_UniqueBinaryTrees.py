import io
import sys
import time

lookupTable = {}

def calcWays2(num):
    global lookupTable

    totalWays = 0

    if num == 2:
        return 2
    elif num <= 1:
        return 1
    elif lookupTable.get(num) is not None:
        return lookupTable[num]

    #how many ways to partition?
    for i in range(num):
        totalWays += calcWays2(i) * calcWays2(num-i-1)

    lookupTable[num] = totalWays
    return totalWays

def calcWays(num):
    elapsed = time.time()
    answer =  calcWays2(num)
    elapsed = time.time()-elapsed
    print("Execution took {0} secnds".format(elapsed))
    return answer


if __name__=="__main__":
    print("number of ways for {0} is {1}".format(sys.argv[1],calcWays(int(sys.argv[1]))))