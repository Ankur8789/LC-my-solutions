class Solution {
public:
    int minDeletions(string s) 
    {
        unordered_map<char,int> mp;
        for(auto t: s)
            mp[t]++;
        vector<pair<int,char>> vp;
        for(auto t: mp)
            vp.push_back({t.second,t.first});
        sort(vp.begin(),vp.end());
        int pre=-1;
        int cnt=0;
        set<int> st;
        for(int i=0;i<vp.size();i++)
        {
            if(st.find(vp[i].first)==st.end())
            {
                st.insert(vp[i].first);
            }
            else
            {
                while(1)
                {
                    if(vp[i].first==0)
                        break;
                    if(st.find(vp[i].first)==st.end())
                    {
                        st.insert(vp[i].first);
                        break;
                    }
                    vp[i].first--;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};