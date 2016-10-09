class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        // write your code here
        int Alen = A.size();
        int Blen = B.size();
        int len = Alen+Blen;
        if(len & 0x1){//奇数
            return findKth(A,Alen,B,Blen,len/2+1);
        }else{
            return (findKth(A,Alen,B,Blen,len/2)+findKth(A,Alen,B,Blen,len/2+1))/2;
        }
    }
    
    double findKth(vector<int> A, int m, vector<int>B, int n, int k){
        if(m>n){
            return findKth(B,n,A,m,k);
        }
        //注意边界条件
        if (0 >= m) return B[k-1];  
        if (0 >= n) return A[k-1];
        if (1 == k) return min(A[0], B[0]);  
        int posA = min(k/2,m), posB = k-posA;
        if(A[posA-1] < B[posB-1]){
            vector<int> newA(A.begin()+posA, A.end());
            return findKth(newA, m-posA, B, n, k-posA);
        }else{
            vector<int> newB(B.begin()+posB, B.end());
            return findKth(A,m,newB,n-posB,k-posB);
        }
        return 0;
    }
};
