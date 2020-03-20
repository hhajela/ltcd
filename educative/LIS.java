import java.util.*;

public class LIS
{
	public static void main(String[] args)
	{
		Scanner scanner = new Scanner(System.in);

		int length = scanner.nextInt();
		int[] nums = new int[length];
		for(int i =0; i<nums.length; i++)
		{
			nums[i] = scanner.nextInt();
		}

		System.out.println(String.format("LIS is %d characters long",LIS(nums)));
	}

	public static int LIS(int[] nums)
	{
		if (nums.length == 0) return 0;

		//keep track of the longest LIS length for each index
		int[] subs = new int[nums.length];
		Arrays.fill(subs,0);

		subs[0] = 1;
		int maxLen = 1;

		for(int i =1; i<nums.length; i++)
		{
			//initial best option - just take ith in the sequence
			subs[i] = 1;

			//go through all prev element candidates
			//pick the one that gives highest lis
			for(int j = 0;j<i; j++)
			{
				//for ith to be added to seq
				//it has to be greater than jth
				//and the score obtained from adding i to jth lis
				//should be greater than current best
				if(nums[i]>nums[j] && subs[i]<subs[j]+1)
				{
					subs[i]= subs[j]+1;
				}
			}
			if(subs[i]>maxLen)
				maxLen = subs[i];
		}

		return maxLen;
	}
}
