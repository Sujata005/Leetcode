class Solution(object):
    def isMatch(self, s, p):
        #Using regex
        pattern = re.compile("^" + p + "$")
        if pattern.search(s) is None:
            return False
        return True
        
        #Using dynamic programming or something I don't really know
        ls, lp = len(s), len(p)
        dp = [[False] * (ls+1) for _ in range(lp+1)]
        dp[0][0] = True
        for i in range(1, lp+1):
            for j in range(ls+1):
                dp[i][j] = ((i>1 and dp[i-2][j]) or dp[i-1][j] or dp[i][j] or (j>0 and dp[i][j-1] and (s[j-1]==p[i-2] or p[i-2]=='.'))) if p[i-1]=='*' else (j>0 and dp[i-1][j-1] and (p[i-1]==s[j-1] or p[i-1]=='.'))
        return dp[-1][-1]
