class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> st;
        for (auto x : deadends)
            st.insert(x);
        queue<pair<int, string>> q;
        unordered_map<string, int> vis;
        q.push({0, "0000"});
        while (q.size() > 0)
        {
            auto pr = q.front();
            q.pop();
            string s = pr.second;
            int cnt = pr.first;
            if (s == target)
                return cnt;
            if (st.find(s) != st.end())
                continue;
            for (auto &x : s)
            {
                char pre = x;
                if (x == '0' || x == '9')
                {
                    if (x == '0')
                    {
                        char pre = x;
                        char ch1 = '1';
                        char ch2 = '9';
                        x = ch1;
                        if (vis.find(s) == vis.end())
                        {
                            vis[s] = 1;
                            q.push({cnt + 1, s});
                        }
                        x = ch2;
                        if (vis.find(s) == vis.end())
                        {
                            vis[s] = 1;
                            q.push({cnt + 1, s});
                        }
                        x = pre;
                    }
                    else
                    {
                        char pre = x;
                        char ch1 = '8';
                        char ch2 = '0';
                        x = ch1;
                        if (vis.find(s) == vis.end())
                        {
                            vis[s] = 1;
                            q.push({cnt + 1, s});
                        }
                        x = ch2;
                        if (vis.find(s) == vis.end())
                        {
                            vis[s] = 1;
                            q.push({cnt + 1, s});
                        }
                        x = pre;
                    }
                }
                else
                {
                    char pre = x;
                    char ch1 = x + 1;
                    char ch2 = x - 1;
                    x = ch1;
                    if (vis.find(s) == vis.end())
                    {
                        vis[s] = 1;
                        q.push({cnt + 1, s});
                    }
                    x = ch2;
                    if (vis.find(s) == vis.end())
                    {
                        vis[s] = 1;
                        q.push({cnt + 1, s});
                    }
                    x = pre;
                }
            }
        }
        return -1;
    }
};