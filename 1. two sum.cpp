class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hashmap;
        
        for(int i = 0; i < nums.size(); ++i) {
            hashmap[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); ++i) {
            const int gap = target - nums[i];
            if(hashmap.find(gap) != hashmap.end() && hashmap[gap] > i){
                res.push_back(i);
                res.push_back(hashmap[gap]);
                break;
            }
        }
        return res;
    }
};