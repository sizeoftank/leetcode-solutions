class Solution {
public:
    int findMin(vector<int> &num) {
        if (num.size()<=1)
            return num[0];
        for (vector<int>::size_type ix=0; ix < num.size()-1; ix++){
            if (num[ix] > num[ix+1]){
                return num[ix+1];
            }
        }
        if (num.front() > num.back())
            return num.back();
        else
            return num.front();
    }
};