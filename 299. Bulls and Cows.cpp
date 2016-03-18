class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, both = 0, n = secret.length();
        for (int i = 0; i < n; i++)
            bull += (secret[i] == guess[i]);
        for (char c = '0'; c <= '9'; c++)
            both += min(count(secret.begin(), secret.end(), c), 
                        count(guess.begin(), guess.end(), c));
        return to_string(bull) + "A" + to_string(both - bull) + "B";
    }
};


2.

class Solution {
public:
    string getHint(string secret, string guess) {
        //1A2B
        unordered_map <char, int> map;
        
        vector<bool> tag(secret.size(), false);
        
        string res;
        for(int i = 0; i < secret.length(); ++i){
            map[secret[i]]++;
        }
        int countA = 0;
        int countB = 0;
        for(int i = 0; i < secret.length(); ++i){
            if(secret[i] == guess[i]){
                countA  ++;
                map[secret[i]]--;
                tag[i] = true;
            }
        }
        
        for(int i = 0; i < guess.length(); ++i){
            if(!tag[i] && map[guess[i]] > 0){
                countB  ++;
                map[guess[i]]--;
            }
        }
        
        res = to_string(countA) +'A'+to_string(countB)+'B';
        return res;
    }
};