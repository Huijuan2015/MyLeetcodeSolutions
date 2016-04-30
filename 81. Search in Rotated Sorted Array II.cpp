class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty() || nums.size() == 0) return -1;
        int start = 0;
        int end = nums.size()-1;
        
        while(start <= end){
            //加这两句 跳过重复
            while(start < end && nums[start] == nums[start+1]) start++;
            while(start < end && nums[end]== nums[end-1])end --;
            
            int mid = start+(end-start)/2;
            if(target == nums[mid]) return true;
            if(nums[start] <= nums[mid]){
                if(nums[start] <= target && nums[mid] >= target){
                    end = mid-1;
                }else{
                    start = mid+1;
                    
                }
                
            }else{
                if(nums[end] >= target && nums[mid] < target){
                    start = mid+1;
                }else{
                    end = mid-1;
                    
                }
            }
        }
            return false;
        
    }
           
};