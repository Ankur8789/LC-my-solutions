class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) 
    {
        int cnt=0;
        stack<pair<int,int>> st;
        map<int,int> mp;
        for(int i=0;i<as.size();i++)
        {
            if(as[i]<0)
            {
                if(cnt>0)
                {
                    int val=abs(as[i]);
                    while(st.size()>0 && st.top().first<=val)
                    {
                        if(st.top().first==val)
                        {
                            cnt--;
                            mp.erase(st.top().second);
                            st.pop();
                            val=0;
                            break;
                        }
                        else
                        {
                            cnt--;
                            mp.erase(st.top().second);
                            st.pop();
                        }
                    }
                    if(val==0)
                    {
                        continue;
                    }
                    else
                    {
                        if(st.size()==0)
                        {
                            mp[i]++;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
                else
                {
                   mp[i]++; 
                }
            }
            else
            {
                cnt++;
                st.push({as[i],i});
                mp[i]++;
            }
                
        }
        vector<int> ans;
        for(int i=0;i<as.size();i++)
        {
            if(mp.find(i)!=mp.end())
                ans.push_back(as[i]);
        }
        return ans;
    }
};