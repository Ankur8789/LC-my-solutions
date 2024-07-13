class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& pos, vector<int>& he, string dir) 
    {
        stack<int> st;
        int cc=0;
        vector<pair<int,pair<int,char>>> vp;
        for(int i=0;i<dir.size();i++)
            vp.push_back({pos[i],{he[i],dir[i]}});
        sort(vp.begin(),vp.end());
        map<int,int> mp;
        for(auto t: vp)
            mp[t.first]=t.second.first;
        vector<int> ans;
        for(int i=0;i<dir.size();i++)
        {
            if(vp[i].second.second=='L')
            {
                if(cc>0)
                {
                    while(st.size()>0 && mp[st.top()]<=mp[vp[i].first])
                    {
                        if(mp[st.top()]<mp[vp[i].first])
                        {
                            mp[vp[i].first]--;
                            cc--;
                            st.pop();
                        }
                        else if(mp[st.top()]==mp[vp[i].first])
                        {
                            st.pop();
                            cc--;
                            mp[vp[i].first]=0;
                            break;
                        }
                    }
                    if(st.size()>0 && mp[vp[i].first]>0)
                    {
                       mp[st.top()]--;
                    }
                   if(st.size()==0 && mp[vp[i].first]>0)
                     ans.push_back(vp[i].first);
                }
                else
                {
                    ans.push_back(vp[i].first);
                }
            }
            else
            {
                st.push(vp[i].first);
                cc++;
            }
        }
        while(st.size()>0)
        {
            ans.push_back(st.top());
            st.pop();
        }
        map<int,int> mx;
        for(auto t: ans)
                mx[t]+=1;
        vector<int> fin;
        for(int i=0;i<pos.size();i++)
        {
            if(mx[pos[i]]>0)
            {
                fin.push_back(mp[pos[i]]);
            }
        }                  
        return fin;     
        
    }
};