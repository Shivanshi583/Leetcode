/*
Return all non-negative integers of length n such that the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

 

Example 1:

Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.
Example 2:

Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

Constraints:

2 <= n <= 9
0 <= k <= 9
*/
class Solution {
public:
    vector<int>ans;
    int countDigits(int n){
        int count=0;
        while(n>0){
            count++;
            n/=10;
            
        }
        return count;
    }
void findnum(int num,int n,int k){
    if(countDigits(num)==n){
        ans.push_back(num);
        return;
    }
    for(int i=0;i<=9;i++){
        int lastDigit=num%10;
        if(abs(lastDigit-i)==k){
            int number=num*10+i;
            findnum(number,n,k);
        }
    }
    
}
    
    vector<int> numsSameConsecDiff(int n, int k) {
        for(int i=1;i<=9;i++){//taken for the starting digit
            findnum(i,n,k);
        }
        return ans;
    }
};