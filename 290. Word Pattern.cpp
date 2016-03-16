class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;//char and word
        set<string> checkUnique;//check if word unique
        istringstream strcin(str);
        string word;
        vector<string> words;
        while(strcin >> word) words.push_back(word);
        
        if(pattern.size() != words.size()) return false;
        
        for(int i = 0; i < pattern.length(); ++i){//search char
            if(map.find(pattern[i]) != map.end()){//find it but not right word
                if(map[pattern[i]] != words[i])
                    return false;
            }
             //not find   
            else {
                //if word exist but char not
                if(checkUnique.count(words[i])){//return 1->yes, return 0 ->no
                    return false;
                }else{
                    map.insert({pattern[i], words[i]});
                    checkUnique.insert(words[i]);
                }
        }
        }
        
        return true;
    }
};