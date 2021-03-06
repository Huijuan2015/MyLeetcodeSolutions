class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        vector<int> f(nums.size(), 0);
        f[0]=0;
    
        for(int i = 1; i < nums.size(); ++i){
            f[i] = max(f[i-1], nums[i-1]) - 1;
            if(f[i] < 0) return false;
        }
        return f[nums.size()-1] >= 0;
    }
};