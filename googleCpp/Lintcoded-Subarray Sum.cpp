比较用sum数组和sum值

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        // write your code here
        //subarray sum=0
        vector<int> res;
        if(nums.empty()||nums.size() == 0) return res;
        int len = nums.size();
        map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        for(int i = 0; i < len;++i){
            sum += nums[i];
            if(mp.find(sum) != mp.end()){//find it
                res.push_back(mp[sum]+1);
                res.push_back(i);
                return res;
            }
            mp[sum]= i;
        }
        return res;
    }
};