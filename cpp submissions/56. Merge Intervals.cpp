class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        /*
        //Optimal approach
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        //Initializing  temp vector 
        vector<int> temp=intervals[0];

        //traversing each element of intervals
        for(auto x: intervals){
            // Checking whether intervals merge or not
            if(x[0]<=temp[1]) 
                // Storing the max of both intervals
                temp[1]=max(x[1],temp[1]);
            else {
                ans.push_back(temp);
                temp=x;
            }
        }
        ans.push_back(temp);
        return ans;
        */
    }
};
