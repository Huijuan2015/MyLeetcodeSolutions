class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
     
    vector<vector<int> > subsets(vector<int> &nums) {
        // write your code here
        
        vector<int> subset;
        subsetsHelper(nums,subset,0);
        return res;
        
    }
    
private:
    
    vector<vector<int>> res;
    void subsetsHelper(vector<int> &nums, vector<int>& subset, int start){
        res.push_back(subset);
        
        for(int i = start; i < nums.size();++i){
            subset.push_back(nums[i]);
            subsetsHelper(nums,subset,i+1);
            subset.pop_back();
        }
    }
};  


class Solution {
public:

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        
        vector<int> path;
        
        dfs(nums,0, path);
        return result;
    }

private:
    vector<vector<int>> result;
    void dfs(vector<int>& nums, int start, vector<int>& path){
        result.push_back(path);
        
        for(auto i= start; i<nums.size();++i){
            if(i!=start && nums[i] == nums[i-1]) continue;//一样就不做操作
            path.push_back(nums[i]);
            dfs(nums, i+1, path);//终止条件是到end()
            path.pop_back();
        }
    }
};