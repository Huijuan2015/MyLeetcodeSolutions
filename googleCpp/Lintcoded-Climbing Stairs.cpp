class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        /*
        int result =0;
        int last =1;
        int lastlast=1;
        for(int i = 2; i<= n; ++i){
            result = last+ lastlast;
            lastlast=last;
            last=result;
        }
        return result;*/
        
        vector<int> f(n+1);
        //f[0] = 0;
        f[1] = 1;
        f[2] = 2;
        for(int i = 3; i <= n; ++i){
            f[i] = f[i-1]+f[i-2];
        }
        return f[n];
    }
};



class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return 1;
        }
        /*
        int result =0;
        int last =1;
        int lastlast=1;
        for(int i = 2; i<= n; ++i){
            result = last+ lastlast;
            lastlast=last;
            last=result;
        }
        return result;*/
        
        vector<int> f(n+1);
        f[0] = 1;
        f[1] = 2;
        //f[2] = 2;
        for(int i = 2; i < n; ++i){
            f[i] = f[i-1]+f[i-2];
        }
        return f[n-1];
    }
};