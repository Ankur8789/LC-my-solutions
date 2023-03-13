class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
         while(tx>sx && ty>sy)
         {
             if(tx>ty)
                 tx%=ty;
             else
                 ty%=tx;
         }
        if(tx==sx && ty>=sy && (ty-sy)%tx==0)
            return true;
        if(ty==sy && abs(tx-sx)%ty==0 && tx>=sx)
            return true;
        return false;
    }
};