class Solution {
public:
    int minDeletionSize(vector<string>& strs) 
    {
        int cnt=0;
        // int last=-1;
        int len=strs[0].size();
        int n=strs.size();
        vector<int> vis(n);
        //checking for each index whether it is needed or not
        for(int i=0;i<len;i++)
        {
             bool del=false;
             vector<int> good;
            for(int j=0;j<n-1;j++)
            {
                string curr=strs[j];
                string nxt=strs[j+1];
                if(vis[j])
                    continue;
                if(curr[i]>nxt[i])
                {
                    del=true;
                    cnt++;
                    break;
                }
                else if(curr[i]==nxt[i])
                    continue;
                else
                {
                    good.push_back(j);
                }
            }
            if(!del)
            {
                for(auto t: good)
                    vis[t]=1;
            }
        }
        return cnt;
    }
};