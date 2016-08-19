class Solution {
public:
    int lengthOfLastWord(string s) {
        int curWordStart = 0;
        int n = s.length();
        int LastWordLen = 0;
        for(int i = 0; i < n; ++i){
            
            if(s[i] != ' '){
                LastWordLen = i-curWordStart+1;
            }else if(s[i] == ' '){
                curWordStart = i+1;
            }
        }
        return LastWordLen;
    }
};