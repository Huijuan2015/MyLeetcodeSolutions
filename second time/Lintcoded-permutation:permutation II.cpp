class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<int> subset;
        Helper(nums, subset);
        return res;
    }
    
private:
    vector<vector<int> > res;
    void Helper(vector<int> nums, vector<int> subset){
        if(subset.size() == nums.size()) {
            res.push_back(subset);
            return;
        }
        for(auto num : nums){
            //num not in suset
            if(find(subset.begin(), subset.end(), num) == subset.end()){
               subset.push_back(num);
               Helper(nums, subset);
               subset.pop_back();
            }
        }
    }
};



class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        vector<bool> visited(nums.size(), false);
        vector<int>subset;
        dfs(nums, subset, visited);
        return result;
    }
    
private:
    vector<vector<int>> result;
    
    
    void dfs(vector<int>& nums,vector<int> subset,vector<bool>& visited){
        if(subset.size() == nums.size()){
            result.push_back(subset);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            //剪枝 前面的数使用了
            //先判断前面的一个数是否和自己相等，相等的时候则前面的数必须使用了，自己才能使用，这样就不会产生重复的排列了。
            if(i!=0 && nums[i] == nums[i-1] && !visited[i-1]) continue;
            
            if(!visited[i]){
                visited[i] = true;
                subset.push_back(nums[i]);
                dfs(nums, subset,visited);
                subset.pop_back();
                visited[i] = false;
            }
        }
    
    }
};