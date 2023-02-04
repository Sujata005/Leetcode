class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int sum=0;
        unordered_map<int,int> m;
        int count=0;
        for(int i=0;i<banned.size();i++){
            m[banned[i]]=0;
        }
        for(int i=1;i<=n;i++){
            if(m.find(i)!=m.end()) continue;
            sum+=i;
            if(sum<=maxSum) count++;
        }
        return count;
    }
};
