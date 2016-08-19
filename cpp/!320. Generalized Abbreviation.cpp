class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        string cur = "";
        Helper(word, cur, res, 0, 0);
        return res;
    }
    /*for every character, we can keep it or abbreviate it. 
    To keep it, we add it to the current solution and carry on backtracking.
    To abbreviate it, we omit it in the current solution, but increment the count, which indicates how many characters have we abbreviated. 
    When we reach the end or need to put a character in the current solution, and count is bigger than zero, we add the number into the solution.*/
    void Helper(string& word, string cur, vector<string>& res, int pos, int count){
        if(pos == word.length()){
            if(count > 0) cur += to_string(count);
            res.push_back(cur);
        }else{
            Helper(word, cur, res, pos+1, count+1);//abbr
            Helper(word, cur + (count > 0 ? to_string(count) : "") + word[pos], res, pos+1, 0);//not abbr
        }
        
       
    }
};