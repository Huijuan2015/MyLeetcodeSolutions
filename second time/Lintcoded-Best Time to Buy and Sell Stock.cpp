1.
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
         if(prices.empty() || prices.size() == 0)return 0;
         int low = prices[0];
         int maxPro = 0;
         for(int i = 1; i < prices.size(); ++i){
             if(low > prices[i]) low = prices[i];
             maxPro = max(maxPro, prices[i]-low);
         }
         return maxPro;
    }
};
----------------------
2.
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty() || prices.size() == 0)return 0;
        int maxSum = 0;
        //累计所有递增段
        for (int i = 1; i < prices.size(); ++i) {
           if(prices[i] > prices[i-1]) {
               maxSum += prices[i]-prices[i-1];
           }
        }
        return maxSum;
    }
};
----------------------
3.class Solution {
f1[i]表示 -- 截止到i下标为止，左边所做交易能够达到最大profit；
f2[i]表示 -- 截止到i下标为止，右边所做交易能够达到最大profit；
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(prices.empty() || prices.size() == 0){
            return 0;
        }
        int len = prices.size();
        
        vector<int> f1(len,0);
        vector<int> f2(len,0);
        
        int low = prices[0];
        int high = prices[len-1];
        
        f1[0] = 0;
        f2[len-1] = 0;
        
        for(int i = 1; i < len; ++i){
            low = min(low, prices[i]);
            f1[i] = (f1[i-1], prices[i] - low);
        }
        
        for(int i = len-2; i >= 0; --i){
            high = max(high, prices[i]);
            f2[i] = max(f2[i+1],high - prices[i]);
        }
        
        int maxPro = INT_MIN;
        for(int i = 0; i < len; ++i){
            maxPro = max(maxPro, f1[i]+f2[i]); 
        }
        return maxPro;
    }
};
----------------------
4.
