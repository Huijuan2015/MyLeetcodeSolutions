/*Solution 1 next permutation
sort nums in ascending order, add it to res;
generate the next permutation of nums using nextPermutation(), and add it to res;
repeat 2 until the next permutation of nums returns to the sorted condition in 1.
*/
/*
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(nextPermutation(nums)){
            res.push_back(nums);
        }
        return res;
    }
private:    
    bool nextPermutation(vector<int>& nums) {
        int k = -1;
        for(int i = nums.size() -2; i >= 0 ; --i){
            if(nums[i] < nums[i+1]){
                k = i;
                break;
            }
        }
        if(k == -1){
            sort(nums.begin(), nums.end());
            return false;//stop sign
        }
        
        int l = -1;
        for(int i = nums.size() -1; i >= k ; --i){
            if(nums[i] > nums[k]){
                l = i;
                break;
            }
        }
        
        swap(nums[k], nums[l]);
        reverse(nums.begin()+k+1, nums.end());
        return true;
    }
};*/



/* Solution 2 backtracking*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        Helper(nums, 0, res);
        return res;
    }
    
    void Helper(vector<int>nums, int start, vector<vector<int>>& res){
    //nums不&,因为函数本身对nums进行了修改
        if(start == nums.size()){
            res.push_back(nums);
            return ;
        }
        
        for(int i = start; i < nums.size(); ++i){
            swap(nums[i], nums[start]);//组合求法
            Helper(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    
    }
};
//solution 3 backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        vector<int> visited(nums.size(), 0);
        
        dfs(nums, 0, visited, cur, res);
        return res;
    }
    
    void dfs(vector<int> nums, int cur_len, vector<int>& cur, vector<int>& visited, vector<vector<int>>& res){
        if(cur_len == nums.size()) {
            res.push_back(cur);
            return;
        }
        
            for(int i = 0; i < nums.size(); ++i){
                if(visited[i] == 0){
                    visited[i] = 1;
                    cur.push_back(nums[i]);
                    dfs(nums,cur_len+1, cur, visited, res);
                    cur.pop_back();
                    visited[i] = 0;
                }
            }
        
    }
};
