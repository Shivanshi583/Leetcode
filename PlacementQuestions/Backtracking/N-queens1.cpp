/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

Example 1:


Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]
 

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    bool isSafe(int row,int col,vector<string> board, int n){
        int dupr=row;
        int dupc=col;
        while(row>=0 && col>=0){
if(board[row][col]=='Q') return false;
            row--;
            col--;
    
    }
        row=dupr;
        col=dupc;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
                
        }
        
        row=dupr;
        col=dupc;
        while(row<n  && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
                
        }
        return true;
    }
    
    void solve(int col,  vector<vector<string>>& ans, vector<string>& board,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,ans,board,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
     vector<vector<string>> ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        solve(0,ans,board,n);
        return ans;
        
    }
};



//for this output

[2 4 1 3 ] [3 1 4 2 ]


class Solution{
public:
    bool check(vector <int> &pos, int row, int col, int n) {
        for(int j = col; j >= 0; j--){
            if(pos[j] == row + 1) return false;}
            
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(pos[j] == i + 1) return false;}
            
        for(int i = row, j = col; i < n && j >= 0; i++, j--) {
            if(pos[j] == i + 1) return false;}
      return true;
    }

    void solve(vector <int> &pos, int col, int n, vector < vector <int> > &ans) {
        if(col == n) {
            ans.push_back(pos);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(check(pos, i, col, n)) {
                pos[col] = i + 1;
                solve(pos, col + 1, n, ans);
                pos[col] = 0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        vector < vector <int> > ans;
        vector <int> pos(n, 0);
        solve(pos, 0, n, ans);
        return ans;
    }
};