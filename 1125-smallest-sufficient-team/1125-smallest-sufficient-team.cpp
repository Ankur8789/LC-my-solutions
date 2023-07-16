#define ll long long
class Solution {
public:
    unordered_map<string, ll> dp;
    vector<int> mask;
 ll f(int k, int idx, int currmask) {
        if (currmask == k)
            return 0;

        if(idx == mask.size())
            return INT_MAX;

        string key = to_string(idx)+" "+to_string(currmask);
        if (dp.count(key))
            return dp[key];
        ll ans = INT_MAX;
        ll pick = f(k,idx+1, currmask | mask[idx]);
        ll notPick = f(k, idx + 1, currmask);
        if (__builtin_popcountll(pick) < __builtin_popcountll(notPick)) 
         ans=pick | (1LL << idx);
         else 
         ans = notPick;

        dp[key] = ans;
        return ans;
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
        for (int i = 0; i < req_skills.size(); i++) {
            mp[req_skills[i]] = i;
        }
        mask.resize(people.size(), 0);
        for (int i = 0; i < people.size(); i++) {
            vector<string>& temp = people[i];
            int t = 0;
            for (string& skill : temp) {
                t |= 1 << mp[skill];
            }
            mask[i] = t;
        }

        int k = (1 << req_skills.size()) - 1;
        dp.clear();
        ll cnt = f(k,0,0);
        vector<int> ans;
        int index = 0;
        while (cnt > 0) {
            ll pick = cnt & 1;
            if (pick == 1) {
                ans.push_back(index);
            }
            index++;
            cnt >>= 1;
        }
        return ans;
    }
};