class MinStack {
private:
    stack<int> stk;
    stack<int> minstk;
    const int int_max = !(1<<(sizeof(int)*8 - 1));
    int min = int_max;
public:
    void push(int x) {
        stk.push(x);
        if (minstk.empty() || x <= minstk.top()){
            minstk.push(x);
        }
    }

    void pop() {
        if (minstk.top() == stk.top()){
            minstk.pop();
        }
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};