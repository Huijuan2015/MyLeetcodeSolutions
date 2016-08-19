class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty() || nums.size() == 0) return 0;
        int n = nums.size();
        if(n == 1 ) return nums[0];
        
        vector<int> sum(n,0);
        sum[0] = nums[0];
        sum[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n; ++i){
            sum[i] = max(nums[i]+sum[i-2], sum[i-1]);//抢或不抢
        }
        return sum[n-1];
    }
};