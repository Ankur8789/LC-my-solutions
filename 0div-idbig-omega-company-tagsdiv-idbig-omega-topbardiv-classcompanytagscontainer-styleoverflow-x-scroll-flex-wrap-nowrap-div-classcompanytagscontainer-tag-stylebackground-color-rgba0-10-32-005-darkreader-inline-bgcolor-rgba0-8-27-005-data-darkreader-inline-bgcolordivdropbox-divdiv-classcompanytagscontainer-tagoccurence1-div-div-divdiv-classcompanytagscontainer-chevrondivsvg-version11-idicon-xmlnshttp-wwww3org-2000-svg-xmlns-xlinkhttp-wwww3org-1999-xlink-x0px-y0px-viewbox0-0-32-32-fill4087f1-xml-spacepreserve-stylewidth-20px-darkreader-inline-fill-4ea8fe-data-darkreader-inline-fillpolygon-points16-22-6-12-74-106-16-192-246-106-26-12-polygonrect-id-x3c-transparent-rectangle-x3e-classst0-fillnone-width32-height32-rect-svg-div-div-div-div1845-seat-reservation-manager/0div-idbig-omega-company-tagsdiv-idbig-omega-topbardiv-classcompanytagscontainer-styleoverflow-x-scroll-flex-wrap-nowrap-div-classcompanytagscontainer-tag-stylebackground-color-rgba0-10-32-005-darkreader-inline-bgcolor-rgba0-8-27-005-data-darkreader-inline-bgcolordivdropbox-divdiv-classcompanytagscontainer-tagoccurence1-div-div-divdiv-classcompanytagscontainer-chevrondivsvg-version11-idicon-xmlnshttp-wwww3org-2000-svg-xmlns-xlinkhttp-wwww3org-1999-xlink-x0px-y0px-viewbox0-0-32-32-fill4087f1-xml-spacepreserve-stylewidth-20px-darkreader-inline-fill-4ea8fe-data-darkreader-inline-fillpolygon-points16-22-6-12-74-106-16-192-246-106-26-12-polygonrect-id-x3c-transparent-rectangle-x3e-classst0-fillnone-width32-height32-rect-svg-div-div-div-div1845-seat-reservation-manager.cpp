class SeatManager {
public:
    multiset<int> res,unres;
    SeatManager(int n) 
    {
       res.clear();
       unres.clear();
       for(int i=1;i<=n;i++)
           unres.insert(i);
    }
    
    int reserve() 
    {
        int val=*unres.begin();
        unres.erase(unres.begin());
        res.insert(val);
        return val;
        
    }
    
    void unreserve(int seatNumber) 
    {
        unres.insert(seatNumber);
        res.erase(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */