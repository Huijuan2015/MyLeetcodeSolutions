class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        //有重复
        int index1 = -1;
        int index2 = -1;
        int shortest = INT_MAX;
        for(int i = 0; i < words.size(); ++i){
            if(word1 == words[i]) index1 = i;
            if(word2 == words[i]) index2 = i;
            if(index1 != -1 && index2 != -1){
                shortest = min(shortest, abs(index1-index2));
            }
        }
        
        return shortest;
    }
};

class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        if(words.empty() ||words.size() < 2) return -1;
        
        int dis = INT_MAX;
        int last1 = -1;
        int last2 = -1;
        
        for(int i = 0; i < words.size(); ++i){
            
            if(words[i] == word1){
                if(word1 == word2){
                    last1 = last2;
                    last2 = i;
                }else{
                    last1 = i;
                }
            }
            if(words[i] == word2){
                last2 = i;
            }
            if(last1 != -1 && last2 != -1){
                dis = min(dis, abs(last2-last1));
            }
        }
        return dis;
    }
};