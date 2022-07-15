/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
*/
class Solution {//greedy
public:
    int jump(vector<int>& nums) {
        int maxreach=0;
        int jumps=0;
        int curr=0;
        
        for(int i=0;i<nums.size()-1;i++){
            
            maxreach=max(maxreach,nums[i]+i);
            if(i==curr){
              
                jumps++;
                  curr=maxreach;
            }
        }
        return jumps;
    }
};
 class Solution {//memoized
     public:
     int dp[10001];
    int solve(int i,int n,vector<int> &nums)
    {
        if(i>=n-1)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int ans=1e9;
        for(int j=1;j<=nums[i];j++)
        {
            ans=min(ans,1+solve(i+j,n,nums));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++)
            dp[i]=-1;
        return solve(0,n,nums);
    }
 };