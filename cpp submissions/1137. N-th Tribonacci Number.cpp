class Solution {
public:
    int tribonacci(int n) {
    /*
    TLE
    if(n==0) return 0;
    if(n==1||n==2) return 1;
    return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    */
        /*vector<int> v(n+1,0);
        v[0]=0;
        v[1]=1;
        if(n==0) return 0;
        if(n==1) return 1;
        v[2]=1;
        for(int i=3;i<=n;i++){
            v[i]=v[i-1]+v[i-2]+v[i-3];
        }
        return v[n];*/


        vector<int> dp(n+1,0);
        dp[0]=0;
        if(n==0)
            return dp[0];
        dp[1]=1;
        if(n==1)
            return dp[1];
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};
