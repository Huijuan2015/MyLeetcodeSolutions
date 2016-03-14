/*S1:DP

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        
        for(auto num : nums){
            sum += num;
            if(sum > maxSum) maxSum = sum;
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};*/
/*S2: prefix sum*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        int minSum = 0;
        
        for(auto num : nums){
            sum += num;
            maxSum = max(maxSum, sum-minSum);
            minSum = min(minSum, sum);
        }
        
        return maxSum;
    }
};