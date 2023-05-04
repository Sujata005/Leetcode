class Solution {
    int timer=1;

    private:
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int time[], int lowTime[], vector<vector<int>> &bridges){
        vis[node]=1;
        time[node]=lowTime[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,vis,adj,time,lowTime,bridges);
                // While traversing if the lowTime of a node is lesser than the iterating node 
                // it is replaced with lowest of both
                lowTime[node]=min(lowTime[node],lowTime[it]);
                // node---it
                if(lowTime[it]>time[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                // while backtracking again same thing is done lowest of both time is stored
                lowTime[node]=min(lowTime[node],lowTime[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        // Creating graph
        vector<int> adj[n];
        for(auto it: connections){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //bridge edges
        vector<int> vis(n,0);
        int time[n];
        int lowTime[n];
        vector<vector<int>> bridges;
        dfs(0,-1,vis,adj,time,lowTime,bridges);
        return bridges;
    }
};
