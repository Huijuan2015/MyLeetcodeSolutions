class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, char> map;//char index in s => char in t
        unordered_set<char> checkSet;//check if its already paired with other char
        for(int i = 0; i < s.length(); ++i){
            if(map.find(s[i]) != map.end() && map[s[i]] != t[i]) 
                return false;
            else if(map.find(s[i]) == map.end() && checkSet.find(t[i]) != checkSet.end())
                return false;
            else if(map.find(s[i]) == map.end() && checkSet.find(t[i]) == checkSet.end()){ 
                map[s[i]] = t[i];
                checkSet.insert(t[i]);
            }
            
            
        }
        return true;
    }
};