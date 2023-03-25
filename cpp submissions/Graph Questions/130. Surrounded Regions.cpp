class Solution {
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int xrow[], int xcol[]){
        vis[row][col] = 1; 
        int n = board.size(), m = board[0].size();
        
        // check for top, right, bottom, left 
        for(int i = 0;i<4;i++) {
            int nrow = row + xrow[i];
            int ncol = col + xcol[i]; 
            // check for valid coordinates and unvisited Os
            if(nrow >=0 && nrow <n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board, xrow, xcol); 
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int xrow[] = {-1, 0, +1, 0};
        int xcol[] = {0, 1, 0, -1}; 
        //O's in boundaries 
        // for rows
        for(int i=0;i<m;i++){
            //first row
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0, i, vis, board, xrow, xcol);
            }
            // last row
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1, i, vis, board, xrow, xcol);
            }
        }
        // for cols
        for(int j=0;j<n;j++){
            //first col
            if(!vis[j][0] && board[j][0]=='O'){
                dfs(j, 0, vis, board, xrow, xcol);
            }
            // last col
            if(!vis[j][m-1] && board[j][m-1]=='O'){
                dfs(j, m-1, vis, board, xrow, xcol);
            }
        }
        //for the whole matrix
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};
