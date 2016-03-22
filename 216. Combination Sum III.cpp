class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector< vector<int> > res;
        vector<int> ans;
        Helper(k, n, 1, ans, res);
        return res;
    }
    
    void Helper(int k, int remain, int start, vector<int>& ans, vector< vector<int> >& res){
        if(remain < 0) return;
        if(remain == 0 && ans.size() == k) res.push_back(ans);
        
        for(int i = start; i <= 9; ++i){
            
            ans.push_back(i);
            Helper(k, remain - i, i+1, ans, res);
            ans.pop_back();
            
        }
            
        }
    
};