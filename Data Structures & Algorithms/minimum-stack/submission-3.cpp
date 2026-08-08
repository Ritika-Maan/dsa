class MinStack {
    int minn;
    stack<pair<int,int>> st;
public:
    MinStack() {
        minn=INT_MAX;
    }
    
    void push(int val) {
        if(!st.empty()){
            minn=min(minn,val);
            st.push(make_pair(val,minn));
        }else{
            minn=val;
            st.push(make_pair(val,minn));
        }
    }
    
    void pop() {
        st.pop();
        if(!st.empty()){
            minn=st.top().second;
        }
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        auto i=st.top();
        return i.second;
    }
};
