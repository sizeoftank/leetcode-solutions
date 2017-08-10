class Solution {
private:
    void dfs(vector< pair<bool,vector<int>> > dp, int n, string s, string res, vector<string> &result){
        if (n == 0)
        {
            result.push_back(res);
        }
        else {
            for (int i = 0; i < dp[n].second.size(); i++){
                int pre = dp[n].second[i];
                string tail = s.substr(pre, n-pre);
                if (n==dp.size()-1){
                    dfs(dp, pre, s, tail, result);
                }
                else{
                    dfs(dp, pre, s, tail+" "+res, result);   
                }
            }
        }
    }
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector< pair<bool, vector<int>>> dp(s.size()+1);
        set<int> wordsize;
        vector<string> ret;
        for (auto it : dict)
            wordsize.insert(it.size());

        dp[0].first = true;
        for (int i = 0; i<s.size(); i++){
            for (auto k : wordsize){
                if (i+1-k >= 0 && dp[i+1-k].first == true){
                    if (dict.find(s.substr(i+1-k, k)) != dict.end()){
                        // dp[i+1] = dp[i+1-k];
                        if (dp[i+1-k].first == true){
                            dp[i+1].first = true;
                            dp[i+1].second.push_back(i+1-k);
                        }
                        else{
                            dp[i+1].first = false;
                        }
                    }
                }
            }
        }
        dfs(dp, s.size(), s, "", ret);
        return ret;
    }
};
