class Solution {
public:
    static int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        int retval;
        for (int idx=0; idx < tokens.size(); idx++){
            if (tokens[idx].compare("+")==0 || tokens[idx].compare("-")==0 
                || tokens[idx].compare("*")==0 || tokens[idx].compare("/")==0) {
                int a, b;
                b = stk.top();
                stk.pop();
                a = stk.top();
                stk.pop();
                if (tokens[idx]=="+"){
                    stk.push(a+b);
                }
                else if(tokens[idx]=="-"){
                    stk.push(a-b);
                }
                else if(tokens[idx]=="*"){
                    stk.push(a*b);
                }
                else if(tokens[idx]=="/"){
                    if (b == 0)
                        return 0;
                    stk.push(a/b);
                }
            }
            else{
                stk.push(atoi(tokens[idx].c_str()));
            }
        }
        return stk.top();
    }
};
