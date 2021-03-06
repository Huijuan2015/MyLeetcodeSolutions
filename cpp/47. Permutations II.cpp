/*1.Next permutation
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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

/*2. recursion*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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
        unordered_set<int> st;//bool isSwap
        for(int i = start; i < nums.size(); ++i){
            if(st.find(nums[i]) != st.end()) continue;//去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换
            st.insert(nums[i]);
            swap(nums[i], nums[start]);
            Helper(nums, start+1, res);
            swap(nums[i], nums[start]);
        }
    }
};