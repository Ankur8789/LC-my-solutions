class Solution {
public:
    bool check(int mid,string& s,vector<vector<int>>& fre){
        int i=0,j=0,n=s.size();
        unordered_map<char,int> mp;
        while(j<n){
            if(j-i+1<mid)
                j++;
            else if(j-i+1==mid){
                vector<int> tmp=fre[j];
                if(i>0){
                    for(int idx=0;idx<26;idx++)
                        tmp[idx]-=fre[i-1][idx];
                }
                int res=0;
                for(auto x: tmp)
                    res+=(x>0);
                if(res==1){
                    for(int idx=0;idx<26;idx++){
                        if(tmp[idx]){
                           mp[char(idx+'a')]+=1;
                           if(mp[char(idx+'a')]==3)
                               return true;
                        }
                    }
                }
                i++,j++;
            }
        }
        return false;
    }
    int maximumLength(string s) {
        int n=s.size();
        vector<vector<int>> fre(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            fre[i][s[i]-'a']++;
            if(i>0){
                for(int j=0;j<26;j++)
                    fre[i][j]+=fre[i-1][j];
            }
        }
        int l=1,r=n-2,ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(mid,s,fre)){
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};