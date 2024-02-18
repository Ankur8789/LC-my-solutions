class Solution {
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders)
    {
         multiset<int> ms;
         for(int i=0;i<h.size()-1;i++)
         {
             if(h[i]>=h[i+1])
                 continue;
             else
             {
                 int rem=h[i+1]-h[i];
                 ms.insert(rem);
                 if(bricks>0 && bricks>=h[i+1]-h[i])
                 {
                     bricks-=h[i+1]-h[i];
                 }
                 else if(ladders>0)
                 {
                     ladders-=1;
                     auto v=*ms.rbegin();
                     ms.erase(--ms.end());
                     bricks+= v-rem;
                 }
                 else
                     return i;
                     
             }
         }
        return h.size()-1;
    }
};