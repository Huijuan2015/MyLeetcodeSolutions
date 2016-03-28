class MinStack {
public:
    stack<int> stk, minstk;
    
    void push(int x) {
        stk.push(x);
        if(minstk.empty() || x <= minstk.top()){
            minstk.push(x);
        }
    }

    void pop() {
        int top = stk.top();
        stk.top();
        if(top == minstk.top()){
            minstk.pop();
        }//如果minstk中top是要pop的元素
        stk.pop();
       
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};