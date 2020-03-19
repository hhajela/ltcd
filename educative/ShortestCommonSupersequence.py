
import sys

def shortestCommonSupersequence(str1,str2):

    if len(str1)==0 and len(str2) ==0:
        return ""

    if len(str1) == 0:
        return str2
    if len(str2) == 0:
        return str1

    temp = None
    #shortest common ss at i and j
    #if i and j are equal, then lenght = 1+ scss at i-1,j-1
    #if i and j are unequal then length 
    #min(scss(i,j-1), scss(i-1,j)) + 1

    #init values for no characters from str1 considered
    #then scss length for any j is the number of characters (index+1) in the str2
    subs = [i for i in range(len(str2)+1)] #indices from 0 to len(str2)

    #print(subs)
    for i,_ in enumerate(str1):

        temp = subs[0]  #store the i-1, 0th value in a temporary variable
        subs[0] = i+1 #scss length equals count of characters in str1 if none from str2 i.e. index +1

        for j in range(1, len(subs)):
            
            #print("i-1,j-1th : {0} i,j-1th : {1} i-1,jth : {2}".format(temp,subs[j-1],subs[j]));

            #print("considering characters {0} and {1}".format(str1[i],str2[j-1]))
            if str1[i]==str2[j-1]:
                #scss at i,j  = scss at i-1,j-1(temp) +1
                temp,subs[j] = subs[j],temp #need to swap because temp set to subs[j] and subs[j] set to temp
                subs[j] += 1 # add 1 for this letter
            else:
                temp = subs[j] #temp not involved in setting subs[j], can safely modify

                #min of scss at i,j-1 and i-1,j + 1
                subs[j] = min(subs[j-1],subs[j])+1

            #print(subs)
        
        #print("")

    #return scss length for all chars considered
    return subs[-1]
    


if __name__=="__main__":

    str1 = input()
    str2 = input()

    print("shortest common supersequence is {0}".format(shortestCommonSupersequence(str1,str2)))
