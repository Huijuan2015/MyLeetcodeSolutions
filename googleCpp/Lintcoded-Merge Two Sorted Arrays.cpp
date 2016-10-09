class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        // write your code here
        vector<int> res;
        if((A.empty()||A.size() == 0) && (B.empty() || B.size() == 0)) 
            return res;
        int ALen = A.size();
        int BLen = B.size();
        int Apos = 0, Bpos = 0;
        while(Apos < ALen && Bpos < BLen){
            
            if(A[Apos] <= B[Bpos]){
                res.push_back(A[Apos]);
                Apos++;
            }else{
                res.push_back(B[Bpos]);
                Bpos++;
            }
        }
        if(Apos < ALen) res.insert(res.end(),A.begin()+Apos, A.end());
        if(Bpos < BLen) res.insert(res.end(),B.begin()+Bpos, B.end());
        return res;
    }
};
