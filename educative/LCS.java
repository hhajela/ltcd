/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class LCS
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scanner= new Scanner(System.in);
		String str1 = scanner.nextLine();
		String str2 = scanner.nextLine();
		System.out.println(String.format("LCS of %s and %s is %s",str1,str2,LCS(str1,str2)));
	}
	
	public static String LCS(String str1, String str2)
	{
		//calculate number of common characters
		//at pos i,j of str1 and str2 respectively
		//length of longest common substring ending in i,j is max of
		//1+ length of longest common substring ending in i-1,j-1
		//if ith and jth characters are the same
		//0 otherwise
		
		//need just one array of values
		ArrayList<Integer> subsolutions = new ArrayList<Integer>(Collections.nCopies(str1.length(),0));
		int maxIndex = -1;
		int maxLen = 0;
		
		//go over possible combinations of i and j
		for(int i =0; i<str2.length(); i++)
		{
			for(int j =str1.length()-1; j>=0; j--)
			{
				subsolutions.set(j, str2.charAt(i)==str1.charAt(j)?(1 + (j>0?subsolutions.get(j-1):0)):0);
				
				
				if (subsolutions.get(j)> maxLen)
				{
					maxLen = subsolutions.get(j);
					maxIndex = j;
				}
			}
		}
		
		return (maxIndex!=1)?str1.substring(maxIndex+1-subsolutions.get(maxIndex),maxIndex+1):"";
	}
}
