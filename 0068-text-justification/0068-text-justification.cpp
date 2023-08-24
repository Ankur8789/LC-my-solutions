class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        vector<string>ans;    
        vector<vector<string>>line;
        int temp=0;
        vector<string>tt;
        for(int i=0;i<n;i++)
        {    
            int x=words[i].size();
            if(x+temp+tt.size() <= maxWidth )
            {
                tt.push_back(words[i]);
                temp+=words[i].size();
            }
            else
            { 
                cout<<tt.size()<<" ";
                line.push_back(tt);
                tt.clear();
                tt.push_back(words[i]);
                temp=words[i].size();
            }
        }
        if(tt.size()>0)
            line.push_back(tt);cout<<tt.size()<<" ";
        for(int i=0;i<line.size();i++)
        {
            string s="";
            int linesz=0;
            for(int j=0;j<line[i].size();j++)
                linesz+=(int)(line[i][j].size());
            int space;
            
            if(line[i].size()>1)
            {
                if((i==line.size()-1))
                {
                    space=maxWidth-linesz;
                    s+=line[i][0];
                   for(int j=1;j<line[i].size();j++)
                   {
                       s+=" "+line[i][j];
                   }
                   int z=maxWidth-s.size();
                   while(z--)
                   {
                       s+=" ";
                   }
                    ans.push_back(s);
                    continue;
                }
                space=maxWidth-linesz;
                int spacebetwords=space/(line[i].size() - 1);
                int extraspaces=space%(line[i].size() - 1);
                for(int j=0;j+1<line[i].size();j++)
                {                    
                    s+=line[i][j];
                    int temp=spacebetwords+(extraspaces > 0 ? 1 : 0);
                    while(temp)
                    {
                        s+=" ";
                        temp--;
                    }
                    extraspaces--;
                }
                s+=line[i][line[i].size() -1];
                ans.push_back(s);
            }
            else
            {
                
                space=maxWidth-linesz;
                s+=line[i][0];
                while(space)
                {
                    s+=" ";
                    space--;
                }
                    ans.push_back(s);
            }
        }
        return ans;
    }
};