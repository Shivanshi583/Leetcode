/*

You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..

Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.

 

Example 1:

Input: s = "cba", k = 1
Output: "acb"
Explanation: 
In the first move, we move the 1st character 'c' to the end, obtaining the string "bac".
In the second move, we move the 1st character 'b' to the end, obtaining the final result "acb".
Example 2:

Input: s = "baaca", k = 3
Output: "aaabc"
Explanation: 
In the first move, we move the 1st character 'b' to the end, obtaining the string "aacab".
In the second move, we move the 3rd character 'c' to the end, obtaining the final result "aaabc".
 

Constraints:

1 <= k <= s.length <= 1000
s consist of lowercase English letters.
*/

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1){
            int n=s.size();
            string doublestring=s+s;
            string ans=s;
            for(int i=1;i<n;i++){
                string str=doublestring.substr(i,n);
                if(str<ans){
                    ans=str;
                }

            }
            return ans;
        }
        //other cases will be taken as if k==2 and we can pick one one letter to make it lexicographically smallest
        sort(s.begin(),s.end());
        return s;
    }
};