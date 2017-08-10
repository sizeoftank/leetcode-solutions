class Solution {
public:
    int maxProduct(int A[], int n) {
        int P = 1;
        int maxP = (1<<(sizeof(int)*8 - 1));
        int negative_first = 0;
        int negative_P = 0;

        for (int i=0; i<n; i++){
            if (A[i] == 0) {
                P = 1;
                negative_first = 0;
                maxP = max(maxP,0);
            }
            else {
                P = P*A[i];
                negative_P = negative_P*A[i];
                if (negative_first)
                    maxP = max(max(P, maxP), negative_P/negative_first);
                else
                    maxP = max(P, maxP);
                
                if (A[i] < 0 && !negative_first){
                    negative_first = A[i];
                    negative_P = A[i];
                }
            }
        }

        return maxP;
    }
};