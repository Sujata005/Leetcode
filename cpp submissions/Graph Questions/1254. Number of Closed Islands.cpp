class Solution {
    void dfs(vector<vector<int>>& grid, int i, int j){
        grid[i][j]=1;
        int n=grid.size(), m=grid[0].size();
        int xrow[]={-1,0,1,0};
        int xcol[]={0,1,0,-1};
        for(int x=0;x<4;x++){
            int nrow=i+xrow[x];
            int ncol=j+xcol[x];
            if(nrow>=0 && nrow< n && ncol>=0 && ncol< m && grid[nrow][ncol]==0){
                dfs(grid,nrow,ncol);
            }
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size(), count=0;
        // Checking for boundaries
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i == 0 || j==0 || i == n-1 || j==m-1) && grid[i][j]==0){
                    dfs(grid,i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
