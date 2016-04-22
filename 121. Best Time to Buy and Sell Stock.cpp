class Solution {
public:
    int maxProfit(vector<int>& prices) {//2,1
        //find the biggest diff
        int maxProfit = 0;
        int low = 0;
        
        
        for(int i = 1; i < prices.size(); ++i){//1->1
            if(prices[low] > prices[i])low = i;
            maxProfit = max(maxProfit, prices[i] - prices[low]);
        }
        return maxProfit;
    }
};

214
124
12
21



