class Solution {
public:
    
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) 
    {
        if(sx==fx && sy==fy)
        {
            if(t!=1)
                return 1;
            else
                return 0;
        }
        return max(abs(sx-fx),abs(sy-fy))<=t;
    }
};