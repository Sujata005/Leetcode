class Solution {
public:
    vector<vector<string>> partition(string s) {
        //first step is to find all the palindromes in the string
        //then use dfs method to walk though the whole word using palindrome records
        
        //dp[startindex][len] indicates whether s[start]~[start+len] is palindome
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size()+1, false)); 
        for(int i=0;i<s.size();++i){
            dp[i][0]=dp[i][1]=true;
        }
        for(int j=2;j<=s.size();++j){
            for(int i=0;i+j<=s.size();++i){
                dp[i][j]=dp[i+1][j-2]&&(s[i]==s[i+j-1]);
            }
        }
        vector<vector<string>> finalRes;
        vector<string> curRes;
        dfs(s, 0, curRes, finalRes, dp);
        return finalRes;
    }
    void dfs(string &s, int index, vector<string> &curRes, vector<vector<string>> &finalRes, vector<vector<bool> > &dp){
        if(index==s.size()){
            finalRes.push_back(curRes);
            return;
        }
        for(int i=1;i+index<=s.size();++i){
            if(dp[index][i]) {
                curRes.push_back(s.substr(index, i));
                dfs(s, index+i, curRes, finalRes, dp);
                curRes.pop_back();
            }
        }   
    }
};
