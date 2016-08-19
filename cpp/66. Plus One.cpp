class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //vector<int> res;
        int pos = digits.size()-1;
        
        while(pos >= 0 && digits[pos] == 9){
            digits[pos] = 0;
            pos --;
        }
        
        if(pos == -1){
            digits[0] = 1;
            digits.push_back(0);
        }else{
            digits[pos]++;
        }
        return digits;
    }
};