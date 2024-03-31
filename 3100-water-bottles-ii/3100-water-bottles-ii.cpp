class Solution {
public:
    int maxBottlesDrunk(int a, int b) 
    {
        int ans = a;
        int rem = a;
        while(rem > 0)
        {
            if (rem >= b)
            {
                rem -= b;
                ans++;
                rem++;
                b++;
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};