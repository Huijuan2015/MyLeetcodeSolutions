class Solution {
public:
    /**
     * @param nums: The integer array
     * @return: The length of LIS (longest increasing subsequence)
     */
    int longestIncreasingSubsequence(vector<int> nums) {
        // write your code here
        int len = nums.size();
        if(len == 0) return 0;
        vector<int> f(len);//f[i]作为最大元素的LIS
        //f[i] = max{f[j] + 1}, j必须满足 j < i && nums[j] <= nums[i]
        //initialize: f[0..n-1] = 1
        f[0] = 1;
        int maxLen = 1;

        for(int i = 1; i < len; ++i){
            //f[i]=1;
            int localMax = 0;//previous longest
            for(int j = 0; j < i; ++j){
                //找出当前点之前的最大上升序列长度
                if(f[j]>localMax && nums[j] < nums[i]){
                    localMax = f[j];
                }
            }
            f[i] =  localMax+1;
            maxLen = max(maxLen, f[i]);
        }
        return maxLen;
    }
};
