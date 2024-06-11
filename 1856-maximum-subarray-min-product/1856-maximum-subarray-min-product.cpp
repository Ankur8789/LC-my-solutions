class Solution {
public:
    const int mod=1e9+7;
    typedef long long ll;
    int maxSumMinProduct(vector<int>& nums) 
    {
        int n=nums.size();
        vector<ll> pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++)
            pref[i]+=(nums[i]+pref[i-1]);
        vector<ll> left(n),right(n);
        stack<ll> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && nums[st.top()]>=nums[i])
                st.pop();
            if(st.size()==0)
                right[i]=n-1;
            else
                right[i]=st.top()-1;
            st.push(i);
        }

        while(st.size())
            st.pop();
        for(int i=0;i<n;i++)
        {
            while(st.size()>0 && nums[st.top()]>=nums[i])
                st.pop();
            if(st.size()==0)
                left[i]=0;
            else
                left[i]=st.top()+1;
            st.push(i);
        }
        ll maxi=0;
        for(int i=0;i<n;i++)
        {
            ll val=0,le=0,ri=0;
            if(left[i]==0)
                le=0;
            else
                le=pref[left[i]-1];
            ri=pref[right[i]];
            val=(ri-le);
            val*=nums[i];
            maxi=max(maxi,val);
        }
        return maxi%mod;
        
    }
};