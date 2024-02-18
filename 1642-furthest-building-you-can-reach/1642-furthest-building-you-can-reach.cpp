class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();

        int b = bricks;
        int l = ladders;

        priority_queue<int> pq;

        for (int i = 0; i < n - 1; i++)
        {
            if (heights[i] > heights[i + 1])
                continue;

            int diff = heights[i + 1] - heights[i];

            pq.push(diff);

            if (diff <= b)
            {
                b -= diff;
            }
            else if (diff > b)
            {
                if (l > 0)
                {
                    int top = pq.top();
                    pq.pop();
                    b += top - diff;
                    --l;
                }
                else
                    return i;
            }
        }

        return b >= 0 ? n - 1 : 0;
    }
};