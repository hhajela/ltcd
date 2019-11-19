import math

def getBiggerStrings(frequencies, key):

    # do binary search in frequencies for key
    first = 0
    last = len(frequencies)-1

    while first<=last:
        mid = math.floor((first+last)/2)

        if frequencies[mid]>key:
            last=mid-1
        elif frequencies[mid]<key:
            first=mid+1
        else:
            while mid>=0 and frequencies[mid]==key:
                mid = mid -1
            
            return mid+1
    
    if first>(len(frequencies)-1):
        return len(frequencies)
    elif last<0:
        return 0
    else:
        return last+1

if __name__=="__main__":
    first = "abcd,aabc,bd"
    second = "aaa,aa"

    # find sizes of all the strings in first
    firstSizes = [word.count(min(word)) for word in first.split(',')]
    
    # sort the first frequency array
    firstSizes.sort()

    #print(firstSizes)

    # for each word in second, compare its size to the sizes of strings in first 
    # by doing a binary search in the frequencies for that key
    result = []

    for word in second.split(','):
        size = word.count(min(word))

        result.append(getBiggerStrings(firstSizes,size))

    print(result)