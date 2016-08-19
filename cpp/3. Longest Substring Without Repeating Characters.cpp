class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        
        int maxLength = 0;
        unordered_map<char,int> map;
        for(int i = 0; i < s.length(); ++i){
            if(map.find(s[i]) != map.end()&& map[s[i]] >= start) {
                    start = map[s[i]]+1;
               }
            map[s[i]] = i;//数出没出现过都要更新坐标
            maxLength = max(maxLength, i-start+1);
        }
        return maxLength;
    }
};