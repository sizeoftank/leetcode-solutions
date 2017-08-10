class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int status = 1; //Ascend
        int left = 1<<(sizeof(int)-1);
        if (num.size()<=1){
            return 0;
        }
        int peak = 0;
        for (int i = 1; i < num.size(); i++){
            if (num[i] > num[i-1])
                peak = peak + 1;
            else
                break;
        }
        return peak;
    }
};