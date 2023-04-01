class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //optimized approach from left
        /*int left = 0;
        while (arr[left] < arr[left+1]) left++;
        return left;

        //from right
        int r=arr.size()-1;
        while (arr[r] < arr[r-1]) r--;
        return r;*/

        //using Binary search
        int s=0, e=arr.size()-1, m;
        m=s+(e-s)/2;
        while(s<e){
            if(arr[m]<arr[m+1]) s=m+1;
            else e=m;
            m=s+(e-s)/2;
        }
        return s;
    }
};
