class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size();//if need to insert in the end
        
        while(start < end){
            int mid = start + (end-start)/2;
            if(nums[mid] < target) start = mid +1;
            else end = mid;
        }
        return end;
    }
};