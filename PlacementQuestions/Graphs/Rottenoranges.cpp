/*
Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
 

Example 1:

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0)
will rot oranges at (0,1), (1,1), (2,2) and 
(2,1) in unit time.
Example 2:

Input: grid = {{2,2,0,1}}
Output: -1
Explanation: The grid is-
2 2 0 1
Oranges at (0,0) and (0,1) can't rot orange at
(0,3).
 

Your Task:
You don't need to read or print anything, Your task is to complete the function orangesRotting() which takes grid as input parameter and returns the minimum time to rot all the fresh oranges. If not possible returns -1.
 

Expected Time Complexity: O(n*m)
Expected Auxiliary Space: O(n)
 

Constraints:
1 ≤ n, m ≤ 500*/

//isme sc is o(n*m)+o(n)
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int vis[n][m];
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 ){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                else{
                    vis[i][j]=0;
                }
            }
        }
        int tm=0;
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            int dr[]={0,-1,0,1};
            int dc[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]!=2 && grid[nr][nc]==1){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},t+1});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]!=2){
                    return -1;
                }
            }
        }
        return tm;
    }
};
//without vis array and end ka loop

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here 
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int cntfresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    
                    q.push({{i,j},0});
                    grid[i][j]=-1;
                }
            if(grid[i][j]==1) cntfresh++;
            }
        }
        int count=0;
        int tm=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm,t);
            int dr[]={0,-1,0,1};
            int dc[]={-1,0,1,0};
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                    count++;
                    grid[nr][nc]=-1;
                    
                    q.push({{nr,nc},t+1});
                }
            }
        }
        if(count!=cntfresh) return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
