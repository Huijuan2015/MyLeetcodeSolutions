class ValidWordAbbr {
public:
    unordered_map<string,unordered_set<string>> map; //d2r-> words 
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i = 0; i < dictionary.size(); ++i){
            
            string word = dictionary[i];
            int n = word.length();
            string abbr = word[0] + to_string(n-2)+word[n-1];
            map[abbr].insert(word);
        }
        
    }

    bool isUnique(string word) {
        int n = word.length();
        string abbr = word[0]+to_string(n-2)+word[n-1];
        return map[abbr].count(word) == map[abbr].size();
    }
};



// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");