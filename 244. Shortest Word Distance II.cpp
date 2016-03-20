class WordDistance {
public:
unordered_map<string, vector<int>> map;//word and index
    WordDistance(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i){
            map[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> index1 = map[word1];
        vector<int> index2 = map[word2];
        int dist = INT_MAX;
        int i = 0;
        int j = 0;
        while(i<index1.size()&&j < index2.size()){
            dist = min(dist, abs(index1[i]-index2[j]));
            if(index1[i]>index2[j])j++;
            else i++;
        }
        
        return dist;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");