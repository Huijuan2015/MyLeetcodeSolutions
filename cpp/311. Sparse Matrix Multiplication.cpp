class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        //AB[i][j] = A[0][i~j]*+B[]
        // A M*N
        // B N*P
        //AB M*P
        int M = A.size();
        int N = B.size();
        int P = B[0].size();
        vector<vector<int>> AB(M, vector<int>(P, 0));
        for(int i = 0; i < M; ++i ){
            for(int j = 0; j < N; ++j){
                if(A[i][j]){
                    for(int k = 0; k < P; ++k){
                        AB[i][k] += A[i][j] * B[j][k];//->useful
                    }
                }
            }
        }
        return AB;
    }
};