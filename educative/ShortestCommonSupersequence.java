import java.util.*;

public class ShortestCommonSupersequence 
{
	public static void main(String[] args)
	{
		Scanner scn = new Scanner(System.in);
		String str1 = scn.nextLine();
		String str2 = scn.nextLine();
		System.out.println("Shortest common super sequence length is " + SCSS(str1,str2));
	}

	public static int SCSS(String str1, String str2)
	{
		if (str1.length()==0 && str2.length()==0) return 0;

		if (str1.length()==0)
			return str2.length();

		if (str2.length()==0)
			return str1.length();

		//store scss lengths for case when no chars incldued from str2
		int[] scssLengths = new int[str2.length()+1];
		for(int i =0; i<scssLengths.length; i++)
		{
			scssLengths[i] = i;
		}

		//loop through values for rest of cases
		for(int i =0; i<str1.length(); i++)
		{
			//store 0th value corresponding to i-1
			int temp = scssLengths[0];

			//0th value for ith char = i+1 (since all chars included)
			scssLengths[0] = i+1;

			for(int j =1; j<scssLengths.length; j++)
			{
				//if i and j same, scss length = scss length i-1,j-1 + 1
				if (str1.charAt(i) == str2.charAt(j-1))
				{
					//swap temp and current value since both depend on each other's old values
					int temp2 = temp;
					temp = scssLengths[j];
					scssLengths[j] = temp2;
					scssLengths[j]++; //1 more for this char
				}
				else
				{
					temp = scssLengths[j]; // can modify , not required for scsslenghts calc
					//ith,jth not same take min(i,j-1 and i-1,j) +1
					scssLengths[j] = Math.min(scssLengths[j-1],scssLengths[j])+1;
				}
			}
		}

		return scssLengths[scssLengths.length-1];
	}
}
