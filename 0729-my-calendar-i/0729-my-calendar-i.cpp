
#define fi first
#define se second
class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        st.clear();
    }
    
    bool book(int s, int e) {
        for(auto x: st){
            if((x.se>s && x.fi<=s) ||  (x.se>e && x.fi<e)  || (x.fi>s && x.se<=e))
                return 0;    
        }
        st.insert({s,e});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */