class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty() || nums.size() == 0) return 0;
        if(nums.size() <= 2) return nums.size();
        
        int n = nums.size();
        int first = 0;
        int newLength = 0;
        int count = 1;
        //1 1 1
        for(int i = 1; i < n; ++i){//1(3)
            
            if(nums[first] == nums[i]){//√
                count ++;//2
                if(count > 2){
                    continue;
                }
            }else{
               
                first = i;
                count = 1;
            }
            newLength ++;//2
            nums[newLength] = nums[i];//
            
            
        }
        return newLength+1;
    }
};