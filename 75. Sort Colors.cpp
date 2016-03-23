class Solution {
public:
    void sortColors(vector<int>& nums) {
        //0-r
        //1-w
        //2-b
        if(nums.empty() || nums.size() <= 1) return;
        int red = 0;
        int blue = nums.size()-1;
        
        for(int i = 0; i <= blue; ++i){
            while(nums[i] == 2 && i < blue){
                swap(nums[blue], nums[i]);
                blue--;
            }
            while(nums[i] == 0 && i > red){
                swap(nums[i], nums[red]);
                red++;
             
            }
        }
        
    }
};