class Solution {
public:
    int countCollisions(string s) 
    {
       stack<char> st;
       int cnt=0;
       int ans=0;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='L')
           {
               if(st.size()>0)
               {
                   char pre=st.top();
                   st.pop();
                   if(pre=='R')
                   {
                       // cnt+=1;
                       cnt--;
                       ans+=2;
                       while(cnt)
                       {
                           cnt--;
                           ans++;
                           st.push('S');
                       }
                       st.push('S');
                       st.push('S');
                   }
                   else
                   {
                       // cnt+=1;
                       ans+=1;
                       while(cnt)
                       {
                           cnt--;
                           ans++;
                           st.push('S');
                       }
                       st.push('S');
                       st.push('S'); 
                   }
               }
               else
                   continue;
           }
           else if(s[i]=='S')
           {
               if(st.size()>0)
               {
                   char pre=st.top();
                   st.pop();
                   if(pre=='R')
                   {
                       cnt--;
                       ans+=1;
                       while(cnt)
                       {
                           cnt--;
                           ans++;
                           st.push('S');
                       }
                       st.push('S');
                       st.push('S');
                   }
                   else
                   {
                       st.push('S');
                       st.push('S');
                   }
               }
               else
               {
                   st.push(s[i]);
                   // cnt++;
               }
           }
           else
           {
              st.push(s[i]);
               cnt++;
           }
           // cout<<ans<<endl;
       }
        return ans;
    }
};