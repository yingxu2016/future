class MaxStack {
private:
    stack<int> s;
    stack<int> m;
public:
    /** initialize your data structure here. */
    MaxStack() {

    }

    void push(int x) {
        s.push(x);
        if(m.empty()) {
            m.push(x);
        }
        else {
            m.push(max(x, m.top()));
        }
    }

    int pop() {
        int ret = s.top();
        s.pop();
        m.pop();
        return ret;
    }

    int top() {
        return s.top();
    }

    int peekMax() {
        return m.top();
    }

    int popMax() {
        int max = m.top();
        stack<int> tmp;
        while(s.top() != max) {
            tmp.push(s.top());
            s.pop();
            m.pop();
        }
        s.pop();
        m.pop();
        while(!tmp.empty()) {
            this->push(tmp.top());
            tmp.pop();
        }
        return max;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
