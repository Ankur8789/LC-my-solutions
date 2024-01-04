class Solution
{
public:
    int numRabbits(vector<int> &answers)
    {
        map<int,int> fre;
        int res = 0;

        for(auto t: answers)
            fre[t]++;
        for(auto t: fre)
        {
            if(t.first==0)
                res+=t.second;
            else
            {
                int div = t.second / (t.first + 1);
                int rem = t.second % (t.first + 1);
                div+=(rem==0)?0:1;
                res += (div * (t.first + 1));
            }
        }

        return res;
    }
};