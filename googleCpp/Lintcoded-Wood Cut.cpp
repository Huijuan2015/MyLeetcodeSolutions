class Solution {
public:
    /** 
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        // write your code here
        int n = L.size();
        if(n == 0) return 0;
        sort(L.begin(), L.end());
        int start = 1;
        int end = L[n-1];
        int res = 0;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            int count = 0;
            for(int i = n-1; i >= 0; --i){
                count += L[i]/mid;
            }
            if(count >= k){
                start = mid+1;
                res = mid;
            }else end = mid-1;
        }
        return res;
    }
};