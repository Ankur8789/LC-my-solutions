class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        vector<int> time;
        int n=dist.size();
        for(int i=0;i<n;i++)
            time.push_back(dist[i]/speed[i]+(dist[i]%speed[i] !=0));
        int cnt=0;
        sort(time.begin(),time.end());
        for(int i=0;i<n;i++)
        {
            if(time[i]>i)
                cnt++;
            else
                break;
        }
        return cnt;
        
    }
};