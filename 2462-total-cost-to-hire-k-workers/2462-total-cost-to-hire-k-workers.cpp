class Solution {
public:
    typedef long long ll;
    long long totalCost(vector<int>& costs, int k, int candidates) 
    {
        ll ans=0;
       
        if(2*candidates>=costs.size())
        {
            sort(costs.begin(),costs.end());
            for(ll i=0;i<k;i++)
                ans+=costs[i];
            return ans;
        }
        else
        {
            ll cc=0;
            ll i=0;
             multiset<ll> msleft,msright;
            // cout<<1<<endl;
            while(cc<candidates)
            {
                
                // cout<<costs[i]<<" ";
                msleft.insert(costs[i]);
                i++;
                cc++;
            }
            i--;
            cout<<endl;
            // cout<<2<<endl;
            ll j=costs.size()-1;
            cc=0;
            while(cc<candidates)
            {
                // cout<<costs[j]<<" ";
                msright.insert(costs[j]);
                j--;
                cc++;  
            }
            j++;
                
            cout<<endl;
            while(i<j && k>0)
            {
                if(*msleft.begin()<*msright.begin())
                {
                    cout<<1<<" ";
                    cout<<*msleft.begin()<<endl;
                    ans+=*msleft.begin();
                    msleft.erase(msleft.begin());
                    i++;
                    k--;
                    if(i<j)
                        msleft.insert(costs[i]);
                }
                else if(*msleft.begin()==*msright.begin() && i!=j-1)
                {
                    if(costs[i+1]>costs[j-1])
                    {
                        ans+=*msright.begin();
                        msright.erase(msright.begin());
                        j--;
                        k--;
                        if(i<j)
                         msright.insert(costs[j]);
                    }
                    else
                    {
                        ans+=*msleft.begin();
                        msleft.erase(msleft.begin());
                        i++;
                        k--;
                        if(i<j)
                         msleft.insert(costs[i]);
                    }
                }
                else
                {
                    cout<<2<<" ";
                    cout<<*msright.begin()<<endl;
                    ans+=*msright.begin();
                    msright.erase(msright.begin());
                    j--;
                    k--;
                    if(i<j)
                        msright.insert(costs[j]);
                    
                }
            }
            while(k>0)
            {
                if(msleft.size()==0 || msright.size()==0)
                {
                    if(msleft.size()==0)
                    {
                        cout<<2<<" ";
                        cout<<*msright.begin()<<endl;
                        ans+=*msright.begin();
                        msright.erase(msright.begin());
                    }
                    else
                    {
                        cout<<1<<" ";
                        cout<<*msleft.begin()<<endl;
                         ans+=*msleft.begin();
                         msleft.erase(msleft.begin());
                    }
                    k--;
                    continue;
                }
                if(*msleft.begin()<*msright.begin())
                {
                    cout<<1<<" ";
                    cout<<*msleft.begin()<<endl;
                    ans+=*msleft.begin();
                    msleft.erase(msleft.begin());
                   
                }
                else
                {
                    cout<<2<<" ";
                    cout<<*msright.begin()<<endl;
                    ans+=*msright.begin();
                    msright.erase(msright.begin());
                    
                }
                k--;
            }
            return ans;
        }
    }
};