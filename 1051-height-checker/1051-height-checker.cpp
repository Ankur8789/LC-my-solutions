class Solution {
public:
    int heightChecker(vector<int>& h) 
    {
       vector<int> nw=h;
       sort(begin(nw),end(nw));
       int cnt=0;
       for(int i=0;i<h.size();i++)
           cnt+=h[i]!=nw[i];
       return cnt;
    }
};