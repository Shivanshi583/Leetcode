/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]
 

Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                v.push_back(i);
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                v.push_back(i);
                break;
            }
        }
        if(v.size()==0) {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=-1,l=-1;
        vector<int>v;
        int s=0,e=nums.size()-1;
      
        while(s<=e){
              int mid=s+(e-s)/2;
            if(nums[mid]==target){
                f=mid;
                e=mid-1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
        s=0,e=nums.size()-1;
      
        while(s<=e){
              int mid=s+(e-s)/2;
            if(nums[mid]==target){
                l=mid;
                s=mid+1;
            }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else{
                e=mid-1;
            }

        }
        if(f!=-1){
            v.push_back(f);
        }
        else{
            v.push_back(-1);
        }
         if(l!=-1){
            v.push_back(l);
        }
        else{
            v.push_back(-1);
        }
        return v;
    }
};