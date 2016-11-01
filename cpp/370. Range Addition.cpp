class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //只更新start end+1 index
        vector<int> calculateHelper(length, 0);
        vector<int> res(length, 0);
        for(auto update : updates){
            calculateHelper[update[0]] += update[2];
            if(update[1]+1 < length) calculateHelper[update[1]+1] -= update[2];
        }
        
        int sum = 0;
        for(int i = 0; i < length; ++i){
            sum += calculateHelper[i];
            res[i] = sum;
        }
        return res;
    }
};