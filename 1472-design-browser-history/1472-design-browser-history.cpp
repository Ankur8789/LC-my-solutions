class BrowserHistory {
public:
    unordered_map<int,string> m;
    int t,fwd;
    BrowserHistory(string homepage) 
    {
        m.clear();
        t=0;
        fwd=0;
        m[t]=homepage;
    }
    
    void visit(string url) 
    {
        t++;
        m[t]=url;
        fwd=t;
    }
    
    string back(int steps) 
    {
       t=max(0,t-steps);
        return m[t];
    }
    
    string forward(int steps) 
    {
        t=min(fwd,t+steps);
        return m[t];
    }
};