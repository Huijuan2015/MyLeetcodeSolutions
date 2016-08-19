class Solution {//O(n^2)
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<pair<int, int>>> mp;
        
        for(int i = 0; i < nums.size(); ++i){
            for(int j = i + 1; j < nums.size(); ++j){
                mp[nums[i]+nums[j]].push_back(make_pair(i, j));
            }
        }//1+2 2+3 1+4... 2找2
        
        vector<vector<int>> res;//i,j + k,l
        
        for(int i = 0; i < (int)nums.size()-3; ++i){//为什么类型转换？
            if(i && nums[i] == nums[i-1]) continue;//duplicated
            for(int j = i+1; j < (int)nums.size()-2; ++j){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int remain = target - nums[i] - nums[j];
                if(mp.find(remain) != mp.end()){
                    for(auto itr = mp[remain].begin(); itr != mp[remain].end(); ++itr){
                        int k = (*itr).first;
                        int l = (*itr).second;
                        
                        if(k > j){
                            vector<int> ans(4);
                            ans[0] = nums[i];
                            ans[1] = nums[j];
                            ans[2] = nums[k];                           
                            ans[3] = nums[l];
                            if(res.empty() || ans != res.back()){
                                res.push_back(ans);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};