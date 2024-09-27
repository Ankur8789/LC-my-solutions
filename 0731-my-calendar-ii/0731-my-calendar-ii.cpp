class MyCalendarTwo {
public:
    map<int,int> mp;
    MyCalendarTwo() {
        mp.clear();
    }
    
    bool book(int start, int end) {
        mp[start]+=1;
        mp[end]-=1;
        int prefix=0;
        for(auto x: mp){
            prefix+=x.second;
            if(prefix>=3){
                mp[start]-=1;
                mp[end]+=1;
                return 0;
            }
        }
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */