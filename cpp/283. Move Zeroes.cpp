class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        // int n = nums.size();
        // int start = 0;
        // int end = n-1;
        // while(start<end){
        //     while(nums[end] == 0 && start < end) end--;
        //     while(nums[start] != 0 && start < end) start ++;
        //     swap(nums[start], nums[end]);
        //     start ++;
        //     end --;
        // }
        int idx = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != 0)
                nums[idx++] = nums[i];
        
        }
        
        for(; idx < nums.size(); ++idx){
            nums[idx] = 0;
        }
        
    }
};