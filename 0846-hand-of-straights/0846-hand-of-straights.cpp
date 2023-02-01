class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        multiset<int> ms;
        for(int i=0;i<hand.size();i++)ms.insert(hand[i]);
        while(ms.size()>0)
        {
            int v=*ms.begin();
            int k=1;
            while(1)
            {
                if(k==groupSize)
                    break;
                if(ms.find(v+1)==ms.end())
                    return false;
                 ms.erase(ms.find(v+1));
                v++;
                k++;
            }
            ms.erase(ms.begin());
        }
        return true;
    }
};