class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        vis[row][col]=1;
        int n=grid.size(), m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            // Traversing neigbours
            for(int xrow=-1;xrow<=1;xrow++){
                for(int xcol=-1;xcol<=1;xcol++){
                    if(abs(xrow)!=abs(xcol)){
                        int nrow=row+xrow;
                        int ncol=col+xcol;
                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                            vis[nrow][ncol]=1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), count=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    count++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return count;
    }
};
