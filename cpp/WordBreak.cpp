class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> dp(s.size()+1);
        set<int> wordsize;
        for (auto it : dict)
            wordsize.insert(it.size());

        dp[0] = true;
        for (int i = 0; i<s.size(); i++){
            for (auto k : wordsize){
                if (i+1-k >= 0 && dp[i+1-k] == true){
                    if (dict.find(s.substr(i+1-k, k)) != dict.end())
                        dp[i+1] = dp[i+1-k];
                }
            }
        }
        return dp[s.size()];
    }
};