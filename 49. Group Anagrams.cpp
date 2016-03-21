class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map< string, vector<string> > map;// sorted string, anagram strings
        sort(strs.begin(), strs.end());//保证输出顺序
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            map[tmp].push_back(str);
        }
        
        vector< vector<string> > res;
        for(auto pair : map){
            res.push_back(pair.second);
        }
        return res;
    }
};