class Solution
{
public:
    vector<int> seg;
    // Segment tree to return maximum in a range
    void upd(int ind, int val, int x, int lx, int rx)
    {
        if(ind>rx || ind<lx)
            return;
        if (lx == rx)
        {
            seg[x] = val;
            return;
        }
        int mid = lx + (rx - lx) / 2;
        upd(ind, val, 2 * x + 1, lx, mid);
        upd(ind, val, 2 * x + 2, mid + 1, rx);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    int query(int l, int r, int x, int lx, int rx)
    {
        if (lx > r or rx < l)
            return 0;
        if (lx >= l and rx <= r)
            return seg[x];
        int mid = lx + (rx - lx) / 2;
        return max(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid + 1, rx));
    }

    int lengthOfLIS(vector<int> &nums, int k)
    {
        int x = 1;
        while (x <= 200000)
            x *= 2;
        seg.resize(4*100000);

        int res = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = max(1, nums[i] - k), right = nums[i] - 1;
            int q = query(left, right, 0, 0, x - 1); 
            res = max(res, q + 1);
            upd(nums[i], q + 1, 0, 0, x - 1);
        }
        return res;
    }
};