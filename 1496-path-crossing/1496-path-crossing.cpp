class Solution {
public:
    bool isPathCrossing(string path) 
    {
       int x=0,y=0;
       set<pair<int,int>> st;
        st.insert({0,0});
       for(auto t: path)
       {
           if(t=='N')
               y++;
           else if(t=='S')
               y--;
           else if(t=='E')
               x++;
           else
               x--;
           if(st.find({x,y})!=st.end())
               return true;
           st.insert({x,y});
       }
        return false;
    }
};