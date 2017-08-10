class Solution {
public:
    int singleNumber(int A[], int n) {
        map<int, bool> table;
        for (int i = 0; i < n; i++){
            map<int, bool>::iterator iter = table.find(A[i]);
            if (iter==table.end()){
                table.insert(pair<int, bool>(A[i], true));
            }
            else{
                iter->second = false;
            }
        }
        int single = 0;
        for (map<int,bool>::const_iterator iter=table.begin(); iter!=table.end(); iter++){
            if (iter->second == true){
                single =  iter->first;
                break;
            }
        }
        return single;
    }
};