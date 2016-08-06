class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = "";
        if(strs.empty() || strs.size() == 0) return "";
        bool flag = true;
        for(int i = 0; i < strs[0].length(); ++i){
            
            for(int j = 0; j < strs.size(); ++j){
                if(strs[j][i] != strs[0][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) longestPrefix += strs[0][i];
        }
        return longestPrefix;
    }
};