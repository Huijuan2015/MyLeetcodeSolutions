class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if(s == "" || s.size()<2) return res;
        for(int i = 0; i < s.size()-1; ++i){
            if(s[i] == '+' && s[i+1] == '+'){
                string str = s.substr(0,i) + "--"+s.substr(i+2, s.size()-i-2);
                
                res.push_back(s);
            }
        }
        return res;
    }
};