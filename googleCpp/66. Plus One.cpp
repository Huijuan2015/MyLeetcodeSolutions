class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int len = digits.size();
        vector<int> res = digits;
        int pos = len-1;
        if(pos >= 0){
            while(digits[pos] == 9 && pos >= 0) {
                res[pos] = 0;
                pos--;
             }
            if(pos >= 0)res[pos]++;
        }
        
        
        if(pos < 0){
            res.insert(res.begin(),1);
        }
        return res;
    }
};