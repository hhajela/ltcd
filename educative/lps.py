

def lpsManacher(input):

    #keep track of the length of a palindrome using reference palidnromes
    transformedInput = addSeps(input)
    print("transformed input {0}".format(transformedInput))

    curCenter = 0
    rightBound = 0
    lengths = [0]
    maxLen = 0
    maxI =0
    for i in range(1,len(transformedInput)):
        m= 0
        n=0
        #check if outside reference palindrome
        if i>rightBound:
            lengths.append(0)
            m = i-1
            n=i+1
        else:
            #check if lenght of mirror palidnrome within bounds of reference palidnrome
            i_ = 2*curCenter -i
            if lengths[i_] < (rightBound-i-1):
                lengths.append(lengths[i_])
                m = -1
            else:
                lengths.append(rightBound-i)
                n=rightBound+1
                m = 2*i - n
        
        while m>=0 and n< len(transformedInput) and transformedInput[m] == transformedInput[n]:
            lengths[i] += 1
            m -=1
            n +=1
    
        if (lengths[i]+i)>rightBound:
            rightBound = i + lengths[i]
            curCenter = i
        
        if lengths[i]>maxLen:
            maxLen= lengths[i]
            maxI = i

    print(lengths)
    
    #extract longest palindrome
    longest = transformedInput[maxI-maxLen+1:maxI+maxLen+2:2]

    print("{0} is the longest palindrome".format(longest))
    



def addSeps(input):
    ret = ''.join(["|"+ i for i in input])
    ret += '|'
    return ret

if __name__=="__main__":
    lpsManacher("asdfasfdabcbcaertyuiiu")