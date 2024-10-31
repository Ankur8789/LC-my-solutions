class Solution {
public:
    typedef long long ll;
    ll dp[101][101];
    ll f(int i,int j,vector<int>& robot,vector<vector<int>>& factory){
        if(j == robot.size())
            return 0;
        if(i == factory.size())
            return 2e18;
        auto& x = dp[i][j];
        if(x != -1)
            return x;
        ll ans = 2e18 , cnt = 0,dis = 0;
        ans = min(ans , f(i+1, j , robot,factory));
        for(int idx = j;idx < robot.size() && cnt < factory[i][1];idx++){
            dis += abs(robot[idx] - factory[i][0]);
            cnt += 1;
            ans = min(ans , dis + f(i+1 , idx + 1, robot,factory ));
        }
        return x = ans;
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(begin(factory) , end(factory));
        sort(begin(robot) , end(robot));
        memset(dp , -1 , sizeof(dp));
        ll ans = f(0,0,robot,factory);
        return ans;
    }
};