class Solution {
    void dfs(int sr, int sc, vector<vector<int>>& ans, vector<vector<int>>& image, int newColor, int xrow[],int xcol[], int color){
        ans[sr][sc]=color;
        int n=image.size(), m=image[0].size();
        for(int i=0;i<4;i++){
            int nrow=sr+xrow[i];
            int ncol=sc+xcol[i];
            if(nrow>=0 && nrow< n && ncol>=0 && ncol< m && image[nrow][ncol]==newColor && ans[nrow][ncol] !=color){
                dfs(nrow,ncol,ans,image,newColor,xrow,xcol,color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int newColor= image[sr][sc];
        vector<vector<int>> ans=image;
        int xrow[]={-1,0,1,0};
        int xcol[]={0,1,0,-1};
        dfs(sr,sc,ans,image,newColor, xrow,xcol, color);
        return ans;
    }
};
