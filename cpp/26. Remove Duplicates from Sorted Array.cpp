class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        
        int pos = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[pos]){
                nums[++pos] = nums[i];
            }
        }
        return pos+1;
    }
};


//Solution 2

return distance(nums.begin(), unique(nums.begin(), nums.end()));