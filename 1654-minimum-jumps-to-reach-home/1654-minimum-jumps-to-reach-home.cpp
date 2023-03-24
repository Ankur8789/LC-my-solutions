class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) 
    {
        unordered_set<int> st;
        for(auto t:forbidden)
            st.insert(t);
        queue<pair<int,int>> q;
        q.push({0,1});
        map<pair<int,int>,int> vis;
        int lvl=0;
        while(q.size())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                
                int pos=p.first;
                int last=p.second;
                
                if(pos==x)
                    return lvl;
                
                if(pos + a <= 6000)
                {  
                    // if(pos+a==x)
                    //     return lvl;
                    if(vis.find({pos+a,1})==vis.end()&&st.find(pos+a)==st.end())
                    {   
                        vis[{pos+a,1}]++;
                        q.push({pos+a,1});
                    }
                }
                
                if(last==1)
                {
                    if(pos-b>=0 && vis.find({pos-b,0})==vis.end()&&st.find(pos-b)==st.end())
                    {
                        // if(pos-b==x)
                        //     return lvl;
                        vis[{pos-b,0}]++;
                        q.push({pos-b,0});
                        // st.insert(pos-b);
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};