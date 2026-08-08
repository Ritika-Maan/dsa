class MyQueue {
    stack<int> st;
    stack<int> sr;
public:
    MyQueue() {
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if(sr.empty()){
            while(!st.empty()){
                sr.push(st.top());
                st.pop();
            }
        }
        int x=sr.top();
        sr.pop();
        return x;
    }
    
    int peek() {
        if(sr.empty()){
            while(!st.empty()){
                sr.push(st.top());
                st.pop();
            }
        }
        return sr.top();
    }
    
    bool empty() {
        if(sr.empty()&& st.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */