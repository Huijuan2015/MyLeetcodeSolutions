class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        
        if(haystack == "" || needle == "" || needle.size() == 0) return 0;
        
        for(int i = 0; i <= haystack.size() - needle.size(); ++i){//注意边界
            bool successFlag = true;
            for(int j = 0; j < needle.size(); ++j){
                if(haystack[i+j] != needle[j]) {
                    successFlag = false;
                    break;
                }
            }
            if(successFlag) return i;
        }
        return -1;
    }
};