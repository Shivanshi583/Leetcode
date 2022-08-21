/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
Example 2:

Input: nums = [1], target = 1
Output: 1
 

Constraints:

1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000
*/
class Solution {
    int CountsubsetSum(vector<int>& nums, int sum)
    {
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i = 0; i<n + 1; ++i)
        {
            for(int j = 0; j<sum + 1; ++j)
            {
                if(i == 0)
                    t[i][j] = 0;
                if(j == 0)
                    t[i][j] = 1;
            }
        }
        for(int i = 1; i<n + 1; ++i)
        {
            for(int j = 0 ;  j<sum + 1; ++j)
            {
                if(nums[i-1] <= j)
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                else
                    t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i<nums.size(); ++i)
            sum += nums[i];
     
        if (abs(target) > sum || (sum + target) % 2 != 0){ 
            return 0;
        }
        
        target = abs (target);
        sum = (sum + target)/2;
        int c = CountsubsetSum(nums,sum);
        return c;
    }
};

//if 0 is in the constraints of arr[i]
class Solution {
  public:
    int perfectSum(vector<int>&a, int n, int sum){
       /*
       This numerical is little bit different because they have also included 0 in arr[i] in constraints
       */
       int dp[n+1][sum+1];
       for(int j=0;j<=sum;j++)
           dp[0][j]=0;
       dp[0][0]=1;
    for(int i=1;i<=n;i++){
     for(int j=0;j<=sum;j++){
      if(a[i-1]<=j)
       dp[i][j]=dp[i-1][j-a[i-1]] + dp[i-1][j];
      else
       dp[i][j]=dp[i-1][j];
     }
    }
    return dp[n][sum];
}
  
   int findTargetSumWays(vector<int>&arr ,int diff) {
       //Your code here
       int n=arr.size();
       int s=0;
    for(int i=0;i<n;i++)
     s+=arr[i];
    int s1=(s+diff)/2;
    if((s+diff)%2!=0)
        return 0;
    return perfectSum(arr,n,s1);
   }


};
