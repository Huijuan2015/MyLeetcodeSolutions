class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        // wirte your code here
        int len = A.size();
        int steps = 0;
        int curMax = 0;
        int curReachable = 0;
        for(int i = 0; i < len; ++i){
            if(curReachable < i){
                steps++;
                curReachable = curMax;
            }
            curMax = max(curMax, A[i]+i);
        }
        return steps;
    }
};
/*
ret:目前为止的jump数

curRch:从A[0]进行ret次jump之后达到的最大范围

curMax:从0~i这i+1个A元素中能达到的最大范围

当curRch < i，说明ret次jump已经不足以覆盖当前第i个元素，因此需要增加一次jump，使之达到

记录的curMax*/