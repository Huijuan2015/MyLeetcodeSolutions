class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //回溯。先对数组进行排序，然后从小到大累加，等于或超过target时回溯。
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        combinationHelper(candidates, 0, target, tmp, res);
        return res;
    }
    
private:
    void combinationHelper(vector<int>& candidates, int start, int remain, vector<int>& tmp, vector<vector<int>>& res){
        if(!remain){
            res.push_back(tmp);
            return;
        }else{
        
            for(int i = start; i < candidates.size(); ++i){
                if(i != start && candidates[i] == candidates[i-1]){
                    continue;
                }//跳过重复
                if(remain >= candidates[i]){
                    tmp.push_back(candidates[i]);
                    combinationHelper(candidates, i+1, remain-candidates[i], tmp, res);//不使用当前值
                    tmp.pop_back();
                }
            }
        }
    
    }
};