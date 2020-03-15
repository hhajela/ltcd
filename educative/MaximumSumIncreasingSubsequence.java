import java.util.*;

public class MaximumSumIncreasingSubsequence
{
	public static void main(String[] args)
	{
		Scanner scn = new Scanner(System.in);

		int length = scn.nextInt();
		int[] nums = new int[length];
		for(int i =0; i<length; i++)
		{
			nums[i] = scn.nextInt();
		}
		System.out.println(String.format("max sum i.s. is %d",MaxSumSubsequence(nums)));
	}

	public static int MaxSumSubsequence(int[] nums)
	{
		//if empty then no max sum =0
		if(nums.length==0) return 0;

		//initialize subsolutions array
		int[] subs = new int[nums.length];
		Arrays.fill(subs,0);

		//for first element, it is its value
		subs[0] = nums[0];
		int maxSum = subs[0];

		//build max sum is for each index
		for(int i =1; i<nums.length; i++)
		{
			subs[i] = nums[i]; //default choice, only include this, then sum = value of this

			for(int j =0; j<i; j++)
			{
				//pick element if total sum > current best
				//and current element is bigger than this one
				if(nums[j]<=nums[i] && subs[j]+nums[i]>subs[i])
				{
					subs[i] = subs[j]+nums[i];
				}
			}

			if (subs[i]>maxSum)
				maxSum = subs[i];
		}

		return maxSum;
	}
}
