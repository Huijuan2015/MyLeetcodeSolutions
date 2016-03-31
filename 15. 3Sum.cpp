class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> res;
         
         sort(nums.begin(), nums.end());
         
         for(int i = 0; i<nums.size(); ++i){
             int target = -nums[i];
             int start = i+1;
             int end = nums.size() -1;
         
             while(start < end){
                 int sum = nums[start] +nums[end];
                 if(sum < target) start ++;
                 else if(sum > target) end --;
                 else{
                     vector<int> triplet(3, 0);
                     triplet[0] = nums[i];
                     triplet[1] = nums[start];
                     triplet[2] = nums[end];
                     res.push_back(triplet);
                     //2,3重复
                     while(start < end && nums[start] == triplet[1]) start ++;
                     while(start < end && nums[end] == triplet[2]) end --;
                 }
             }
             //1重复
             while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
         }
         return res;
    }
};