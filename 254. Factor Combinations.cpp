class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector< vector<int> > res;
        vector<int> factor;
        Helper(n, 2, factor, res);
        return res;
    }
    
    void Helper(int n, int start, vector<int>& factor, vector< vector<int> >& res){
        if(n == 1) {
            if(factor.size() > 1){
                res.push_back(factor);
            }
            return;
        }
       // int k = static_cast<int>(sqrt(n));
        for(int i = start; i <= n; ++i){
            if(n%i == 0){
                factor.push_back(i);
                Helper(n/i, i, factor, res);
                factor.pop_back();
            }
        }
             
    }
};