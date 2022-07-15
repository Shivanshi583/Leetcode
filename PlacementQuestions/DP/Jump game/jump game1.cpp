/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
class Solution {//founded the maximum number of steps from a point can reach end or next index
public:
    bool canJump(vector<int>& nums) {
       int maxreach=0;
        for(int i=0;i<=maxreach;i++){
            if(maxreach>=nums.size()-1) return true;
            maxreach=max(maxreach,i+nums[i]);
        }
        return maxreach>=nums.size()-1;
    }
};
class Solution{//seen if the next index can be reaches from the previous index,will not work for bigger numbers
    public:
    bool canJump(vector<int>& nums){
        int n=nums.size();
      int last=n-1;  
        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=last){
                last=i;
            }
        }
        return last==0;
    }
};
class Solution {//checked if we can reach the next index or not
public:
    bool util(vector<int>& nums,int i,vector<int>&dp)
    {
        if(i>=nums.size()-1)return true;
        if(dp[i]!=-1)return dp[i];
        if(nums[i]==0)return dp[i]=false;
        for(int j=1;j<=nums[i];j++)
        {
            if(util(nums,i+j,dp))return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return util(nums,0,dp);
    }
};
