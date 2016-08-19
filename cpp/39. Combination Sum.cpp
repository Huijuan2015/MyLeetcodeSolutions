class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //回溯。先对数组进行排序，然后从小到大累加，等于或超过target时回溯。
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        combinationHelper(candidates, 0, target, tmp, res);
        return res;
    }
    
private:
    void combinationHelper(vector<int>& candidates, int start, int remain, vector<int>& tmp, vector<vector<int>>& res){
        if(!remain){//0表示假 remain==0时进if
            res.push_back(tmp);
            return;
        }
        
        for(int i = start; i < candidates.size(); ++i){//可以（int）一下 for safe
            if(remain >= candidates[i]){
                tmp.push_back(candidates[i]);
                combinationHelper(candidates, i, remain-candidates[i], tmp, res);
                tmp.pop_back();
            }
        }
    }
};