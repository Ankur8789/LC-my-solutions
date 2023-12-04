class Solution {
public:
    string largestGoodInteger(string num) 
    {
       string ans="";
       for(int i=0;i<num.size();i++)
       {
           string tem="";
           tem+=num[i];
           if(i+1<num.size())
               tem+=num[i+1];
           if(i+2<num.size())
               tem+=num[i+2];
           if(tem.size()!=3)
               break;
           if(tem[0]==tem[1] && tem[1]==tem[2])
           {
               if(ans.size()==0)
               {
                   ans=tem;
                   continue;
               }
               if(tem[0]>ans[0])
                   ans=tem;
           }
       }
        return ans;
    }
};