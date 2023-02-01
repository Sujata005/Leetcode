class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            long long l=target-nums[i];
            for(int j=i+1;j<nums.size();j++){
                long long k= l-nums[j];
                int low =j+1;
                int high=nums.size()-1;
                while(low<high){
                    int sum=nums[low]+nums[high];
                    if(sum<k){
                        low++;
                    }
                    else if(sum>k){
                        high--;
                    }
                    else{
                        vector<int> temp(4,0);
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[low];
                        temp[3]=nums[high];
                        ans.push_back(temp);
                        while(low<high && nums[low]==temp[2]) ++low;
                        while(low<high && nums[high]==temp[3]) --high;
                    }
                }
                while(j+1<nums.size() && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<nums.size() && nums[i+1]==nums[i]) ++i;
        }
        return ans;
    }
};
