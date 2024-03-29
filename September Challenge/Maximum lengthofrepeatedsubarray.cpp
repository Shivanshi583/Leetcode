/*
Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 

Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
 

Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/
//to(m*n)
//sc=o(1)
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        int maxc=0;
        for( int i=-n+1;i<m;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i+j<0){
                    continue;
                    
                }
                else if(i+j>=m){
break;
                }
                else if(nums1[i+j]==nums2[j]){
                    count++;
                    maxc=max(count,maxc);
                    
                }
                else{
                    count=0;
                }
            }
        }
        return maxc;
    }
};