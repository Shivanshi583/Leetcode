/*
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

Return the modified image after performing the flood fill.

 

Example 1:


Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
Example 2:

Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
Output: [[0,0,0],[0,0,0]]
Explanation: The starting pixel is already colored 0, so no changes are made to the image.
 

Constraints:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

Expected Time Compelxity: O(n*m)*4
Expected Space Complexity: O(n*m)


*/

//using DFS
class Solution {
public:
    void helper(vector<vector<int>>&image, int i, int j, int oldC, int newC)
    {
        if(i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != oldC)
            return;
        
        image[i][j] = newC;
        helper(image, i + 1, j, oldC, newC);
        helper(image, i - 1, j, oldC, newC);
        helper(image, i, j + 1, oldC, newC);
        helper(image, i, j - 1, oldC, newC);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc] != color)
            helper(image, sr, sc, image[sr][sc], color);
        
        return image;
    }
};



//using bfs
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
          int n=image.size();
    int m=image[0].size();
    int dr[]={0,-1,0,+1};
    int dc[]={1,0,-1,0};
    vector<vector<int>> grid=image;
     int inicolor=image[sr][sc];
     if(image[sr][sc]==newColor){
         return image;
     }
     queue<pair<int,int>>q;
     grid[sr][sc]=newColor;
     q.push({sr,sc});
     while(!q.empty()){
         pair<int,int> todo=q.front();
         q.pop();
         for(int i=0;i<4;i++){
             int nr=todo.first+dr[i];
             int nc=todo.second+dc[i];
             if(nr>=0 && nr<n && nc>=0 && nc<m && image[nr][nc]==inicolor && grid[nr][nc]!=newColor){
                grid[nr][nc]=newColor;
                 q.push({nr,nc});
             }
         }
         
     }
     return grid;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends