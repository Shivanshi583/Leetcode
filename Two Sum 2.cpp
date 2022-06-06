class Solution { //optimal approach tc=O(n), sc=O(1);
public:
    vector<int> twoSum(vector<int>& arr, int t) {
       vector<int >res;
        int n=arr.size();
        int i=0;int j=n-1;
        while(i<j){
            if(arr[i]+arr[j]<t) i++;
            else if(arr[i]+arr[j]>t) j--;
            else if(arr[i]+arr[j]==t){
                res.push_back(i+1);
                res.push_back(j+1);
                break;//ONLY ONE SOLUTION NEEEDED
            }
        }
        return res;
    }
};

class Solution { //USING HASHMAP
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> m;
        int diff;
        for(int i=0;i<nums.size();i++){
            diff=target-nums[i];
            if(m.find(diff)!=m.end()){
                ans.push_back(m[diff]+1); 
                ans.push_back(i+1);            
                return ans;
                break;
            }
            m[nums[i]]=i;
        }
        return ans; 
    }
};


