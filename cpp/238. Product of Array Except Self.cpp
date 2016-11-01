class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {//1 0

        vector<int> res(nums.size(),1);
    
        for(int i = 1; i < nums.size(); ++i){//1
            res[i] = res[i-1]*nums[i-1];
        }
        int rightProduct = 1;//necessary
        for(int i = nums.size()-2; i >= 0; --i){
            rightProduct *= nums[i+1];
            res[i] *= rightProduct;
        }
        return res;
    }
};