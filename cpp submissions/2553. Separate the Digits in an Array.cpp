class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> s;
        for(int i=0;i<nums.size();i++){
            while(nums[i]){
                int x=nums[i]%10;
                s.push(x);
                nums[i]/=10;
            }
            while(!s.empty()){
                ans.push_back(s.top());
                s.pop();
            }
        }
        return ans;
    }
};
