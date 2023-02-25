class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*//BRUTE FORCE
        int i=0,maxx=0;
        while(i<prices.size()){
            if(prices[i]<prices[i+1]){
                int d=prices[i+1]-prices[i];
                maxx=max(maxx,d);
            }
            i++;
        }
        return maxx;*/
        
        //OPTIMAL APPROACH
        int minn= prices[0], profit=0;
        for(int i=1;i<prices.size();i++){
            int d= prices[i]-minn;
            profit=max(profit,d);
            minn=min(minn,prices[i]);
        }
        return profit;
        
    }
};
