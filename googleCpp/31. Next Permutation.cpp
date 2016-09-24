class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int k = -1;
        for(int i = len-2; i >= 0; --i){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        
        if(k == -1){
            sort(nums.begin(), nums.end());
            return;
        }
        
        //int l = -1;
        for(int i = len-1; i >= k; --i){
            if(nums[i] > nums[k]){
                //l = i;
                swap(nums[k], nums[i]);
                break;
            }
        }
        
        //swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
    }
};