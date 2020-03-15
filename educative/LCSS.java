import java.util.*;


public class LCSS
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);

		String str1 = scanner.nextLine();
		String str2 = scanner.nextLine();

		System.out.println(String.format("LC Subsequence of %s and %s is %d characters long",str1,str2,LongestCommonSubsequence(str1, str2)));
	}

	public static int LongestCommonSubsequence(String str1, String str2)
	{
		if (str1.length()==0 || str2.length()==0)
			return 0;

		//store subs in array
		ArrayList<Integer> subs = new ArrayList<Integer>(Collections.nCopies(str2.length(),0));
		int temp = 0;

		//build subsolution values
		for(int i =0; i<str1.length(); i++)
		{
			for(int j  =0; j<str2.length(); j++)
			{
				//till point i, j longest common subsequence is max of i,j-1 and i-1,j
				//or if ith and jth are equal then i-1,j-1

				int c1 = 0;
				if (str1.charAt(i)==str2.charAt(j))
				{
					c1 = 1+ (j>0?temp:0);
				}

				int c2 = Math.max(j>0?subs.get(j-1):0,subs.get(j));

				temp = subs.get(j); //store this for usage by next j

				subs.set(j,Math.max(c1,c2));
			}
		}

		return subs.get(subs.size()-1);
	}
}
