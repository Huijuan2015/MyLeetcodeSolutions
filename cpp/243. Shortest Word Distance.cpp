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