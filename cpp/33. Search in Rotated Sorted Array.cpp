/*
三种情况
1. 递增
2. 前半段长
3. 后半段长
注意 start=end的情况
 */

 class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            if(nums[mid] == target) return mid;
            
            if(nums[mid] >= nums[start]){
                if(target >= nums[start] && target <= nums[mid]) {
                    end = mid-1;
                }else{
                    start = mid+1;
                }
                
            }else{
                if(target<=nums[end] && target > nums[mid]){
                    start = mid+1;
                }else end = mid-1;
            }
        }
        
        return  -1;// if while(start < end)->return nums[start] == target ? start : -1;//start==end,无法进入while
    }
};