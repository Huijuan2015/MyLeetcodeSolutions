自己写cmp的原因：pair前后元素排序方式不一样

If two words has the same frequency, 
the one with lower alphabetical order come first

class Solution {
public:
    /**
     * @param words an array of string
     * @param k an integer
     * @return an array of string
     */
     struct cmp{
        bool operator() (pair<int, string> a, pair<int, string> b) {
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequentWords(vector<string>& words, int k) {
        unordered_map<string, int> mymap;//string and freq
        for(auto const& word : words) {
            mymap[word]++;
        }
        vector<string> result;
        //push all to queue
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp > que;
        for(auto const& v : mymap) {
            que.push(make_pair(v.second, v.first));
        }
        while(que.empty() == false && k>0) {
            auto v = que.top();
            que.pop();
            k--;
            result.emplace_back(v.second);
        }
        return result;
    }

};