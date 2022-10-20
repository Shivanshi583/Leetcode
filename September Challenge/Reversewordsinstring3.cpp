/*
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
Example 2:

Input: s = "God Ding"
Output: "doG gniD"
 

Constraints:

1 <= s.length <= 5 * 104
s contains printable ASCII characters.
s does not contain any leading or trailing spaces.
There is at least one word in s.
All the words in s are separated by a single space.
*/
class Solution {
public:
    string reverseWords(string s) {

   
    int n = s.length();
    stack<char>st;
    string ans = "";
    
    for(int i=0;i<n;i++){
        while(i<n and s[i]!=' '){
            st.push(s[i++]);
        }
        
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        ans += ' ';
    }
    ans.pop_back();
    return ans;
    
}
};

class Solution {
public:
    string reverseWords(string s) {
        int l=0;int r=0;
        while(l<s.size()){
            while(r<s.size() && s[r]!=' '){
                r++;
            }
            reverse(s.begin()+l,s.begin()+r);
            l=r+1;
            r=l;
        }
        return s;
    }
};