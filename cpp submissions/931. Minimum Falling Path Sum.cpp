class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
       if(j<0 || j>=matrix[0].size()) return 1e9;
       if(i == 0) return matrix[0][j];
       if(dp[i][j]!= -1) return dp[i][j];
       int u=matrix[i][j]+f(i-1, j, matrix,dp);
       int ld=matrix[i][j]+f(i-1, j-1, matrix,dp);
       int rd=matrix[i][j]+f(i-1, j+1, matrix,dp);

       return dp[i][j]=min(u, min(ld,rd)); 
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size(),m=matrix[0].size(), minn=1e9 ;
       vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
           minn=min(minn,f(n-1,j,matrix,dp));
        }
        return minn; 
    }

};
