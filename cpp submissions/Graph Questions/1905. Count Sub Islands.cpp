class Solution {
    void dfs(int i, int j, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int &flag, int n, int m){
        if(i<0||j<0||i>=n||j>=m||grid2[i][j]==0) return;
        if(grid1[i][j]==0) flag=0;
        grid2[i][j]=0;
        dfs(i+1,j,grid1,grid2,flag,n,m);
        dfs(i-1,j,grid1,grid2,flag,n,m);
        dfs(i,j+1,grid1,grid2,flag,n,m);
        dfs(i,j-1,grid1,grid2,flag,n,m);
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0, n=grid1.size(), m=grid1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]){
                    int flag=1;
                    dfs(i,j,grid1,grid2,flag,n,m);
                    ans+=flag;
                }
            }
        }
        return ans;
    }
};
