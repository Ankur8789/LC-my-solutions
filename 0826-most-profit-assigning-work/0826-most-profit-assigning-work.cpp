class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        sort(worker.begin(), worker.end());
        vector<pair<int, int>> task(profit.size());
        for(int i=0; i<profit.size(); i++)
        {
            task[i] = {difficulty[i], profit[i]};
        }
        sort(task.begin(), task.end());
        // for(auto x:task) cout << x.first << " " << x.second << endl;
        int maxTillNow = 0;
        int i = 0;
        int ans = 0;
        for(int j=0; j<task.size(); j++)
        {
            while(i<worker.size() && task[j].first > worker[i])
            {
                ans += maxTillNow;
                i++;
            }
            if(i == worker.size()) break;
            maxTillNow = max(maxTillNow, task[j].second);
        }
        ans += (worker.size()-i)*maxTillNow;
        return ans;
    }
};