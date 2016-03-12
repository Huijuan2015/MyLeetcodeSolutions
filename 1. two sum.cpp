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