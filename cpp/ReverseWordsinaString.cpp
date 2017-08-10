class Solution {
public:
    void reverseWords(string &s) {
        istringstream sstrem(s);
        string retval;
        string word;
        while (sstrem >> word){
            if (!retval.empty())
                retval = word +" " + retval;
            else
                retval = word + retval;
        }
        s = retval;
    }
};