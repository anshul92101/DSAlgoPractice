class MinStack {
    stack<pair<int,int>> st;
    int mini ;
public:
    MinStack() {
        while(!st.empty()) st.pop();
        mini = INT_MAX;
    }
    
    void push(int val){
        mini = val;
        if(!st.empty()){
            mini = min(val,st.top().second);
        }
        st.push({val,mini});
        
    }
    
    void pop(){
        st.pop();
    }
    
    int top(){
        int topElement = st.top().first;
        return topElement;
    }
    
    int getMin() {
        int minElement = st.top().second;
        return minElement;
    }
};