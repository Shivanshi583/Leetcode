/*
You are given two integer arrays nums and multipliers of size n and m respectively, where n >= m. The arrays are 1-indexed.

You begin with a score of 0. You want to perform exactly m operations. On the ith operation (1-indexed), you will:

Choose one integer x from either the start or the end of the array nums.
Add multipliers[i] * x to your score.
Remove x from the array nums.
Return the maximum score after performing m operations.

 

Example 1:

Input: nums = [1,2,3], multipliers = [3,2,1]
Output: 14
Explanation: An optimal solution is as follows:
- Choose from the end, [1,2,3], adding 3 * 3 = 9 to the score.
- Choose from the end, [1,2], adding 2 * 2 = 4 to the score.
- Choose from the end, [1], adding 1 * 1 = 1 to the score.
The total score is 9 + 4 + 1 = 14.
Example 2:

Input: nums = [-5,-3,-3,-2,7,1], multipliers = [-10,-5,3,4,6]
Output: 102
Explanation: An optimal solution is as follows:
- Choose from the start, [-5,-3,-3,-2,7,1], adding -5 * -10 = 50 to the score.
- Choose from the start, [-3,-3,-2,7,1], adding -3 * -5 = 15 to the score.
- Choose from the start, [-3,-2,7,1], adding -3 * 3 = -9 to the score.
- Choose from the end, [-2,7,1], adding 1 * 4 = 4 to the score.
- Choose from the end, [-2,7], adding 7 * 6 = 42 to the score. 
The total score is 50 + 15 - 9 + 4 + 42 = 102.
 

Constraints:

n == nums.length
m == multipliers.length
1 <= m <= 103
m <= n <= 105
-1000 <= nums[i], multipliers[i] <= 1000
*/
class Solution {
public:
    int solve(vector<int>& nums, vector<int>& multipliers,int l,int r,int index,vector<vector<int>>&dp){
         int n=nums.size();
        int m =multipliers.size();
        if(index>=m) return 0;
        if(dp[index][l]!= INT_MIN){
            return dp[index][l];
        }
        int x=multipliers[index];
        return dp[index][l]= max(nums[l]*x +solve(nums,multipliers,l+1,r,index+1,dp) ,nums[r]*x+solve(nums,multipliers,l,r-1,index+1,dp)); 
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
     int n=nums.size();
        int m =multipliers.size();
        int l=0;
        int r=n-1;
        int indexmul=0;
         vector<vector<int>> dp(m+1,vector<int>(m+1,INT_MIN));
        return solve(nums,multipliers,l,r,indexmul,dp);
    }
};