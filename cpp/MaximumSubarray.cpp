class Solution {
public:
    int maxSubArray(int A[], int n) {
        int sum = 0;
        int maxSum = (1<<(sizeof(int)*8 - 1));
        for (int i = 0; i < n; i++){
            sum = sum + A[i];
            sum = max(sum, A[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};