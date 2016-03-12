class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        
        int newLength = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != val){
                nums[newLength] = nums[i];
                newLength ++;
            }
        }
        return newLength;
    }
};