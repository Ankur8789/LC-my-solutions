class Skiplist {
public:
    map<int,int> mp;
    Skiplist() {
      mp.clear();  
    }
    
    bool search(int target) {
        return mp.find(target)!=mp.end();
    }
    
    void add(int num) {
        mp[num]++;
    }
    
    bool erase(int num) {
        if(mp.find(num)!=mp.end())
        {
            mp[num]--;
            if(mp[num]==0)
                mp.erase(num);
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */