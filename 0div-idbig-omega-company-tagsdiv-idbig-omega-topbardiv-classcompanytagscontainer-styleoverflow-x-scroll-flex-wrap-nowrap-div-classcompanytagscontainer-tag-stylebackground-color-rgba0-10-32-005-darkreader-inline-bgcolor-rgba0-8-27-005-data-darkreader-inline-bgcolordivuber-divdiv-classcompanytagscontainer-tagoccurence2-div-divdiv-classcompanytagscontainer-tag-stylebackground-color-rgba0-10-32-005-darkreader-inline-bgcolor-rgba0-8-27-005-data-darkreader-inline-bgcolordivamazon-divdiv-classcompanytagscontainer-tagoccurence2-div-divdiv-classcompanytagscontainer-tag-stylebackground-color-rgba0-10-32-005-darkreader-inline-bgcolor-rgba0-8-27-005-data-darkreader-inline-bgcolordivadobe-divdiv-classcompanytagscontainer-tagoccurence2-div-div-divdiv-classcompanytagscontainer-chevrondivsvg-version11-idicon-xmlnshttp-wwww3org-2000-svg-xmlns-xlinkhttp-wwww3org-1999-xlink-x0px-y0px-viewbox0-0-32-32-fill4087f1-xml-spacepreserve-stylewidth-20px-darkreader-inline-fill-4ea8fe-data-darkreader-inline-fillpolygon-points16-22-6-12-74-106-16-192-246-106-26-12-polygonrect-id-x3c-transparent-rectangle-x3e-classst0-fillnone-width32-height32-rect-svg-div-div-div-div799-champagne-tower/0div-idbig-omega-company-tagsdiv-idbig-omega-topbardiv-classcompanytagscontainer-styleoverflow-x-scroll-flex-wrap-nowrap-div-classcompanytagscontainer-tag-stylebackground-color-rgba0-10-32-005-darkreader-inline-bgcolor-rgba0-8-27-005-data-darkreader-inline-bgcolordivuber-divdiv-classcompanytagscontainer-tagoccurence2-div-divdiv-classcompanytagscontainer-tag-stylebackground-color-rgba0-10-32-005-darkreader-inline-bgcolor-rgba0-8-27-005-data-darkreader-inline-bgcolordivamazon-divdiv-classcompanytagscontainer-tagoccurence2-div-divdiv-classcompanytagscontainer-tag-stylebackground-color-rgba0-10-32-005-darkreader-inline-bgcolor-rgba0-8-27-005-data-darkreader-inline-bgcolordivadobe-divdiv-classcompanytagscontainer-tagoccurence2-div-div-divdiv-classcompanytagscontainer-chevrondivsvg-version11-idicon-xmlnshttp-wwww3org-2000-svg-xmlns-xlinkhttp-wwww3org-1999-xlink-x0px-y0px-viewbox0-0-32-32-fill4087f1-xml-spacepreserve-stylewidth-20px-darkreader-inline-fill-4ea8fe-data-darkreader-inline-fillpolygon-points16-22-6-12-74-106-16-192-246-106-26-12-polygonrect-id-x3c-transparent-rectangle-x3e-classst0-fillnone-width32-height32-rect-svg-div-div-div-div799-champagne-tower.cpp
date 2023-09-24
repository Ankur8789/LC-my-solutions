class Solution {
public:
    double champagneTower(int poured, int qr, int qg) 
    {
        vector<vector<double>> vec(101);
        for(int i=0;i<=100;i++)
            vec[i].resize(i+1);
        vec[0][0]=poured;
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<vec[i].size();j++)
            {
                if(vec[i][j]>1.0)
                {
                    double tmp=(vec[i][j]-1.0)/2.0;
                    vec[i+1][j]+=tmp;
                    vec[i+1][j+1]+=tmp;
                    vec[i][j]=1.0;
                }
            }
        }
        // for(int i=0;i<5;i++)
        // {
        //     for(int j=0;j<vec[i].size();j++)
        //         cout<<vec[i][j]<<" ";
        //     cout<<endl;
        // }
        return vec[qr][qg];
        
    }
};