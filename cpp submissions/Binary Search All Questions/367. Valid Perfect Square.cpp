class Solution {
public:
    bool isPerfectSquare(int num) {
    int left = 0;
    int right = num;
    while(left <= right){
        long mid = (left+right)/2;
        
        if(mid*mid==num)
            return true;
        else if(mid*mid > num)
            right = mid - 1;
        else
            left = mid+1;
    }
    return false;  
    }
};
