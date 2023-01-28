class SummaryRanges {
public:
    set<int> ms;
    SummaryRanges() 
    {
        ms.clear();
    }
    
    void addNum(int value) 
    {
        ms.insert(value);
        
    }
    
    vector<vector<int>> getIntervals() 
    {
         set<int> s=ms;
        vector<vector<int>> ans;
        while(s.size()>0)
        {
            vector<int> temp;
            temp.push_back(*s.begin());
            int x=*s.begin();
            int y=x;
            while(1)
            {
                if(s.find(x+1)==s.end())
                    break;
                s.erase(x+1);
                y=x+1;
                x++;
                
            }
            temp.push_back(y);
            ans.push_back(temp);
            s.erase(s.begin());
        }
        return ans;
        
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */