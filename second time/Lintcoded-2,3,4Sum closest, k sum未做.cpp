two sum

nlogn:两个指针 need sort
n:map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashmap;
        
        for(int i = 0; i < nums.size(); ++i) {
            const int gap = target - nums[i];
            if(hashmap.find(gap) != hashmap.end()){
                res.push_back(hashmap[gap]);
                res.push_back(i);
                break;
            }
            hashmap[nums[i]] = i;
        }
        return res;
    }
};
-----------------------------------------------
3 sum
2个指针 
class Solution {
public:    
    /**
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        // write your code here
        vector<vector<int> > res;
        if (nums.empty() || nums.size() == 0) return res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size()-1; ++i) {
            int target = -nums[i];
            int start = i+1;
            int end = nums.size()-1;
            
            while(start < end){
                int sum = nums[start]+nums[end];
                if(sum < target) start++;
                else if(sum > target) end--;
                else{
                    vector<int> tmp(3,0);
                    
                    tmp[0] = nums[i];
                    tmp[1] = nums[start];
                    tmp[2] = nums[end];
                    
                    res.push_back(tmp);
                    while(start < end && nums[start] == tmp[1]) start ++;
                    while(start < end && nums[end] == tmp[2]) end --;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
-----------------------------------------------
3 sum closest
class Solution {
public:    
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        // write your code here
        sort(nums.begin(), nums.end());
        int res = nums[0]+nums[1]+nums[2];
        for (int i = 0; i < nums.size(); ++i) {
            int start = i+1;
            int end = nums.size()-1;
            while(start < end){
                int sum = nums[i]+nums[start]+nums[end];
                if(abs(sum-target) < abs(res-target)){
                    res = sum;
                }
                if(sum<target) start ++;
                else end --;
            }
        }
        return res;
    }
};
-----------------------------------------------
4 sum

class Solution {
public:
    /**
     * @param numbers: Give an array numbersbers of n integer
     * @param target: you need to find four elements that's sum of target
     * @return: Find all unique quadruplets in the array which gives the sum of 
     *          zero.
     */
    vector<vector<int> > fourSum(vector<int> nums, int target) {
        // write your code here
        int len = nums.size();
        vector<vector<int>> res;
        if(len < 4) return res;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-3; ++i){
            if(i && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len-2; ++j){
                if(j!=i+1 && nums[j] == nums[j-1]) continue;

                int diff = target - nums[i]-nums[j];
                int start = j+1;
                int end = len-1;
                while(start < end){
                    if(nums[start]+nums[end] == diff){
                        vector<int> tmp(4,0);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[start];
                        tmp[3] = nums[end];
                        res.push_back(tmp);
                        start++;
                        end--;
                        while(start<end && nums[start] == nums[start-1]) start++;
                        while(start<end && nums[end] == nums[end+1]) end--;
                    }else if(nums[start]+nums[end] > diff) end --;
                    else start++;
                }
            }
        }
        return res;
    }
};

