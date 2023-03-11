class Solution {
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        vector<int> v;
        vector<int> l;
        vector<int> r;

        // l.push_back(0);
        // l.push_back(nums[0]);
        int i = 0;
        while (i < nums.size())
        {
            int a = 0, b = 0;
            for (int j = 0; j < i; j++)
                a += nums[j];
            l.push_back(a);
            for (int j = i + 1; j < nums.size(); j++)
                b += nums[j];
            r.push_back(b);
            i++;
        }
        r.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(abs(l[i] - r[i]));
        }

        return v;
    }
};