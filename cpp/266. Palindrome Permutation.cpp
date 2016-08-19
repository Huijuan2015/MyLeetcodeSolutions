class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;
        
        for(int i = 0; i < s.length(); ++i){
            if(map[s[i]] == 0) map[s[i]]++;
            else map[s[i]]--;
        }
        int count = 0;
        for(int i = 0; i < 256; ++i){
            if(map[i] == 1) count ++;
        }
        
        return count <=1;
    }
};