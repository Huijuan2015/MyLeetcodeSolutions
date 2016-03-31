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
    //如果返回true，这两个元素就需要交换位置，反之则不需要。
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

//Find the k-most frequent elements from a list
//
int kTop(ListNode *head, int k){

    unordered_map<int, int> mp;//head->val, counts
    while(head){
        mp[head->val] ++;
        head = head->next;
    }

    priority_queue<pair<int, int>, vector<int, int>, cmp> pq；
    for(auto ele : mp){
        pq.push_back(make_pair(ele.second, ele.first));
    }

    for(int i = 0; i < k-1; ++i){
        pq.pop()
    }
    return pq.top();
}

struct cmp(){
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.first < b.first;
    }
};