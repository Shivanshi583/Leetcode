class Solution { // Brute force -TC =O(N2) ,SC=O(1)
public:
    vector<int> twoSum(vector<int>& arr, int s) {
         int n=arr.size();
    vector<int> ans;
    for(int i=0;i<n;i++){
for(int j=i+1;j<n;j++){
    if(arr[i]+arr[j]==s){
       
       
        ans.push_back(i);
        ans.push_back(j);
    }
}
    }
    
    return ans;
    }
};


//OPTIMAL -TC=O(N),SC=O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        int diff;
        for(int i=0;i<nums.size();i++){
            diff=target-nums[i];
            if(m.find(diff)!=m.end()){
                ans.push_back(m[diff]); 
                ans.push_back(i);            
                return ans;
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};