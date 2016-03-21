class Solution {
public:
    int hIndex(vector<int>& citations) {
        //h指数是指他至多有h篇论文分别被引用了至少h次
        /*
        1、将某作者的所有文章的引用频次按照从大到小的位置排列

        2、从前到后，找到最后一个满足条件的位置，其条件为：

        此位置是数组的第x个，其值为y，必须满足 y >= x;
         */
        sort(citations.begin(), citations.end());
        //reverse(citations.begin(), citations.end());
       
        int h = 0;
        int i = 0;
        int n = citations.size();
        for(int i = n-1; i >= 0; --i ){
            if(citations[i] >= n-i){
                h = n-i;
            }else continue;
        }
        return h;
    }
};


