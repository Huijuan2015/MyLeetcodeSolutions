class Solution {
public:
    int hIndex(vector<int>& citations) {
        //h指数是指他至多有h篇论文分别被引用了至少h次
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
       
        int h = 0;
        int i = 0;
        for(int c : citations ){
            h = max(h, min(++i, c));
        }
        return h;
    }
};