class Solution {//tc=O(m+n),sc=O(1)
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
      int i = m - 1,// first pointer
        j = n - 1, // second  pointer
        k = m + n - 1;// third pointer
     while(i >= 0 and j >= 0) 
     {
         
         if(nums1[i] < nums2[j]) 
             nums1[k--] = nums2[j--];
         
          else 
             nums1[k--] = nums1[i--];
         
     }
     while(j >= 0) { // following part is the case when nums1 is empty and nums2 remains
         nums1[k--] = nums2[j--];
     }
        
    }
};