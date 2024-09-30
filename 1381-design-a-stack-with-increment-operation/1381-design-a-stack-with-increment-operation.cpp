class CustomStack {
public:
    vector<int> v;
    int sz;
    int currcnt=0;
    CustomStack(int maxSize) {
        v.clear();
        v.resize(maxSize);
        sz=maxSize;
        currcnt=0;
    }
    
    void push(int x) {
        if(currcnt==sz)
            return;
        v[currcnt]=x;
        currcnt++;
    }
    
    int pop() {
        if(currcnt==0)
            return -1;
        int x=v[currcnt-1];
        currcnt-=1;
        return x;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(currcnt,k);i++)
            v[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */