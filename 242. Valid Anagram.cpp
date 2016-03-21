1. hash table

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vec(26,0);
        if(s.length() != t.length()) return false;
        for(int i = 0; i < s.length(); ++i){
            vec[s[i]-'a']++;
            vec[t[i]-'a']--;
        }
        
        for(int i = 0; i <26; ++i){
            if(vec[i] != 0) return false;
        }
        
        return true;
    }
};

2. 2 pointers
class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length()-1;
        
        while(start < end){
            while(start < end && !isalnum(s[start])) start ++;
            while(start < end && !isalnum(s[end])) end --;
            if(tolower(s[start]) != tolower(s[end])) return false;
        
            start++;
            end--;
            
        }
        return true;
    }
};