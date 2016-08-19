class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
       unordered_map<string, vector<string>> map;
       
       for(int i = 0; i < strings.size(); ++i){
           string difference = "";
           difference = diff(strings[i]);
           map[difference].push_back(strings[i]);
           sort(map[difference].begin(), map[difference].end());
       }
       vector<vector<string>> res;
       for(auto pair : map){
           res.push_back(pair.second);//注意写法
       }
        return res;
    }
private:   
    string diff(string str){
        string result;
        result = '0';
        
        for(int i = 1; i < str.length(); ++i){
            if((str[i]-str[i-1])<0) //注意后面字母排前面的情况
                result += to_string(str[i]-str[i-1]+26);
            else result += to_string(str[i]-str[i-1]);
        }
        
        return result;
    }
    
    
//         unordered_map<string, vector<string>> hash;
        
//         for(string s : strings){
//             hash[shift[s]].push_back(s);
//         }
        
//         vector<vector<string>>groups;
//         for(auto m : hash){
//             vector<string> group = m.second;
//             sort(group.begin(), group.end());
//             groups.push_back(group);
//         }
//         return groups;
//     }

// private:
//     string shift(string& s){
//         string t;
//         int n = s.length();
//         for(int i = 1; i < n; ++i){
//             int diff = s[i] - s[i-1];
//             if(diff < 0) diff += 26;
//             t += 'a' + diff + ',';
//         }
//         return t;
//     }
};