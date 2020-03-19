import java.util.*;

public class LongestRepeatingSubsequence
{

	public static String LRS(String str1)
	{
		if (str1.length()==0) return "";

		int[][] dp = new int[str1.length()][str1.length()];

		int bestI = -1;
		int bestJ = -1;
		int bestLen = 0;

		for(int i=0; i<str1.length(); i++)
		{
			int temp;
			for(int j =0; j<i; j++)
			{
				//if ith and jth match, length for i and j = 1 + elngth at i-1,j-1
				if (str1.charAt(i) == str1.charAt(j) && i!=j)
				{
					dp[i][j] = (j>0 && i>0 ? dp[i-1][j-1] : 0) +1;
				}
				else //mismatch means best of lrs in both possible cases
				{
					dp[i][j] = Math.max((j>0?dp[i][j-1]:0),(i>0?dp[i-1][j]:0));
				}

				if (dp[i][j] > bestLen)
				{
					bestLen = dp[i][j];
					bestI =i;
					bestJ =j;
				}
			}
		}
		
		char[] result = new char[bestLen];
		int l = bestLen-1;
		int i = bestI;
		int j = bestJ;
		while(i>=0 && j>=0)
		{
			//check if chars match
			if (str1.charAt(i)==str1.charAt(j) && i!=j)
			{
				result[l] = str1.charAt(i);
				i--;
				j--;
				l--;
			}
			else
			{
				if (dp[i][j] == (i>0?dp[i-1][j]:0))
					i--;
				else
					j--;
			}
		}
		return new String(result);
	}


	public static void main(String[] args)
	{
		Scanner scn = new Scanner(System.in);
		String str1;
		str1 = scn.nextLine();

		System.out.println("LRS is " + LRS(str1));
		
	}



}
