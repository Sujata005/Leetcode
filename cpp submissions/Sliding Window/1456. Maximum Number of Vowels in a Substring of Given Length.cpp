class Solution {
public:
    int maxVowels(string s, int k) {
        string t="aeiou";
        int count=0,ans=0,j=0;
        for(;j<s.size();j++){
            if(j>=k && t.find(s[j-k])!=string :: npos){ 
                count--;
                
            }
            if(t.find(s[j])!=string::npos) count++;
            ans=max(ans,count);
        }
        return ans;
    }
};
