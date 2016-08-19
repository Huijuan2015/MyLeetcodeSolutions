class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
            //可以加句break
            /*if(A[i]>=A.length||A[i]<=0||A[i]==A[A[i]-1])
                    break;*/
        }//unsorted 数组中第i位存放数值(i+1)
        
        for(int i = 0; i < n; ++i){
            if(nums[i] != i+1){
                return i+1;//正常bucket
            }
        }
        return n+1;
    }
};