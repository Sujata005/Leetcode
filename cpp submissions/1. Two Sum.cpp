class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        
        /*for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }*/
        
        /*map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.find(target-nums[i])!=m.end()){
                ans.push_back(i);
                ans.push_back(m[target-nums[i]]);
            }
            m[nums[i]]=i;
        }*/

        //Two pointer approach
        //This approach can be implemented if and only if we have to return elements
        //If we have to return indices of the array we should use hash map
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1;
        while(low<high){
            if(nums[low]+nums[high]>target){
                high--;
            }
            else if(nums[low]+nums[high]==target){
                ans.push_back(low);
                ans.push_back(high);
                break;
            }
            else{
                low++;
            }
        }
        return ans;
    }
};
