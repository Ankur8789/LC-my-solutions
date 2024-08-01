class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int cnt=0;
        for(auto t: details)
        {
            string s="";
            s+=t[11];
            s+=t[12];
            int val=stoi(s);
            if(val>60)
                cnt++;
        }
        return cnt;
    }
};