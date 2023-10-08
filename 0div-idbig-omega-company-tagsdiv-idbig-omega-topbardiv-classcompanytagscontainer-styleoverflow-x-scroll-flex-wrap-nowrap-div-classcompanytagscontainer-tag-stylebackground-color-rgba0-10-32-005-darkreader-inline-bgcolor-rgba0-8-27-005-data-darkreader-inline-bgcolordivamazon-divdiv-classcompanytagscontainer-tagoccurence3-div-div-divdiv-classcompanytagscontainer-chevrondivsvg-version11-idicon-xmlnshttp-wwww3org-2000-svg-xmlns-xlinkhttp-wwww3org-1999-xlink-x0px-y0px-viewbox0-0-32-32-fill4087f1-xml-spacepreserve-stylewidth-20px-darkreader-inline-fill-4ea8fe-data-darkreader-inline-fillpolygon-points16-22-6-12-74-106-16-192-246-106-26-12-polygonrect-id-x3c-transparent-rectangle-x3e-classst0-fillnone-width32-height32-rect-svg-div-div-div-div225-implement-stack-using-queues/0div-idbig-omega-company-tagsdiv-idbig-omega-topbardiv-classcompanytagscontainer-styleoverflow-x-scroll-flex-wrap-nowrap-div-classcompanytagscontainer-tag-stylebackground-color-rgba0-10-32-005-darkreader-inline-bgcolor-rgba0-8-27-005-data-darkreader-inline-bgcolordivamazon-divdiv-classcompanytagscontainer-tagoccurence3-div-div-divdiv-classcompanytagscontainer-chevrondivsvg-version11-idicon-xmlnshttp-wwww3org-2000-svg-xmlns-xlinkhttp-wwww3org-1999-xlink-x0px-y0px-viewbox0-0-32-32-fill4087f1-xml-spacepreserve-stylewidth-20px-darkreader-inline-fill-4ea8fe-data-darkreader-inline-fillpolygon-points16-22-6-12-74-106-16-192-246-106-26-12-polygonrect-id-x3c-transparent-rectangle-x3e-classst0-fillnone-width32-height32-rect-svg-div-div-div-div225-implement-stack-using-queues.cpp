class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int y) 
    {
        queue<int> x;
        while(q.size()>0)
        {
            x.push(q.front());
            q.pop();
        }
        q.push(y);
        while(x.size())
        {
            q.push(x.front());
            x.pop();
        }
        
    }
    
    int pop() {
        int val=q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */