class Solution {
public:
    string longestPalindrome(string s) {
        //if(s == "") return NULL;
        int len = s.length();
        
        //vector cost more memory and space
        //vector<vector<bool> > f(len, vector<bool>(len));
        bool f[len][len];
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++){
                if(i >= j) f[i][j] = true;
                else f[i][j] = false;
            }
        }
        int start = 0;
        int end = 0;
        int maxLen = 1;
        for(int j = 1; j < len; ++j){
            for(int i = 0; i < j; ++i){
                if(s[i] == s[j]){
                    f[i][j] = f[i+1][j-1];
                    if(f[i][j] && j-i+1 > maxLen){
                        start = i;
                        end = j;
                        maxLen =  j-i+1;
                    }
                }else f[i][j] = false;
            }
        }
        return s.substr(start, maxLen);
    }
};