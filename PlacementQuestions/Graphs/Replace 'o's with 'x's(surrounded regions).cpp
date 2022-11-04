/*
Replace O's with X's
MediumAccuracy: 49.91%Submissions: 10581Points: 4
Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just left and just right of it.

Example 1:

Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 
Your Task:
You do not need to read input or print anything. Your task is to complete the function fill() which takes n, m and mat as input parameters ad returns a 2D array representing the resultant matrix.

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n*m)

Constraints:
1 ≤ n, m ≤ 500
*/
class Solution{

public:
    int p, q;

    void dfs(int i, int j, vector<vector<char>> mat, vector<vector<int>>& vis) {

        vis[i][j] = 1;

        int dx[4] = {0, 0, -1, 1};

        int dy[4] = {-1, 1, 0, 0};

        for(int k = 0; k < 4; k++) {

            int nx = i + dx[k];

            int ny = j + dy[k];

            if((nx >= 0 && ny >= 0 && nx < p && ny < q) && mat[nx][ny] == 'O' 

                && vis[nx][ny] == 0) {

                dfs(nx, ny, mat, vis);

            }

        }
    }

    

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)

    {

        p = n;

        q = m;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {

            // for first column

            if(vis[i][0] == 0 && mat[i][0] == 'O')

                dfs(i, 0, mat, vis);

            //for last column

            if(vis[i][m-1] == 0 && mat[i][m-1] == 'O')

                dfs(i, m-1, mat, vis);

        }

        for(int j = 0; j < m; j++) {

            // for first row

            if(vis[0][j] == 0 && mat[0][j] == 'O')

                dfs(0, j, mat, vis);

            //for last row

            if(vis[n-1][j] == 0 && mat[n-1][j] == 'O')

                dfs(n-1, j, mat, vis);

        }

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(vis[i][j] == 0 && mat[i][j] == 'O') mat[i][j] = 'X';

            }

        }

        return mat;

    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends

//without visited array

class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<char>>& board) {
        
        if(!safe(i, j, m, n) or board[i][j] != 'O') return;
        if(board[i][j] == 'O') board[i][j]='#';
        dfs(i + 1, j, m, n, board);
        dfs(i, j + 1, m, n, board);
        dfs(i - 1, j, m, n, board);
        dfs(i, j - 1, m, n, board);
    }
    
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(border(i, j, m, n) and board[i][j] == 'O') {
                    dfs(i, j, m, n, board);
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    bool border(int i, int j, int m, int n) {
        return (i == 0 or i == m-1 or j == 0 or j == n-1);
    }
    
    bool safe(int i, int j, int m, int n) {
        return (i >= 0 and i < m and j >= 0 and j < n);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(border(i, j, m, n) and board[i][j] == 'O') {
                    board[i][j] = '#';
                    q.push({i, j});
                }
            }
        }
        
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto dir: dirs) {
                int x = cur.first + dir.first;
                int y = cur.second + dir.second;
                if(safe(x, y, m, n) and !border(x, y, m, n) and board[x][y] == 'O') {
                    board[x][y] = '#';
                    q.push({x, y});
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }

private:
    bool border(int i, int j, int m, int n) {
        return (i == 0 or i == m-1 or j == 0 or j == n-1);
    }
    
    bool safe(int i, int j, int m, int n) {
        return (i >= 0 and i < m and j >= 0 and j < n);
    }
};