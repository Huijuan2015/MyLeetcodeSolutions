class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        vector<int> subset;
        Helper(nums, subset, 0, res);
        return res;
    }
    
private:
    void Helper(vector<int>& nums, vector<int>&subset, int start, vector< vector<int> >&res){
        res.push_back(subset);
        
        for(int i = start; i < nums.size(); ++i){
            subset.push_back(nums[i]);
            Helper(nums,subset,i+1,res);
            subset.pop_back();
        }
    }
};