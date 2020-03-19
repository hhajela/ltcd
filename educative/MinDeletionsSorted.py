

def min_deletions_sorted(nums):

    #compute length of lis

    #min deletions = length of array - length(lis)

    subs = [0 for i in range(len(nums))]

    subs[0] = 1 # with only 1 element considered, length of lis = 1
    maxLen = 0

    for i in range(1,len(nums)):

        #for this number, lis is the one that is the best choice from all lis before it
        
        #initial best value for i is the one where it is the only one in the lis
        subs[i] = 1

        for j in range(0,i):
            #update subs[i] if lis conditions hold and this is the best choice thus far
            if nums[j]<=nums[i] and subs[j]+1>subs[i]:
                subs[i] = subs[j] +1

        #update global best
        if subs[i]>maxLen:
            maxLen = subs[i]

    return len(nums)-maxLen


if __name__=="__main__":

    length = int(input())

    nums = [int(input()) for i in range(length)]

    print("Min deletions to make this sorted are : {0}".format(min_deletions_sorted(nums)))

