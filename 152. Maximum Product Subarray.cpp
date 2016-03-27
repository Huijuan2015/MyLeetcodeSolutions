class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty() || nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        int maxLocal = nums[0];
        int minLocal = nums[0];
        int global = nums[0];
        
        for(int i = 1; i < nums.size(); ++i){
            int maxCopy = maxLocal;
            maxLocal = max(max(nums[i], nums[i]*maxLocal), nums[i]*minLocal);
            minLocal = min(min(nums[i], nums[i]*minLocal), nums[i]*maxCopy);
            global = max(maxLocal, global);
        }
        return global;
    }
};
如果当前是负数，如果minLocal是负数
local min:  可以更小，