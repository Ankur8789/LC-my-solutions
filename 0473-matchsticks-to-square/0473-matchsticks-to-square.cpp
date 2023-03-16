class Solution {
public:
bool search(vector<int>& v, int a, int b, int c, int d, int i, int n, long long target) {
    if (i == n) 
    {
        return a == b && b == c && c == d && d == target;
    } 
    else 
    {
        int x = v[i];
        if (a + x <= target && search(v, a+x,b,c,d,i+1,n,target)) return true;
        if (b + x <= target && search(v, a,b+x,c,d,i+1,n,target)) return true;
        if (c + x <= target && search(v, a,b,c+x,d,i+1,n,target)) return true;
        if (d + x <= target && search(v, a,b,c,d+x,i+1,n,target)) return true;
        return false;
    }
}

bool makesquare(vector<int>& matchsticks) 
{
    long long s = 0;
    int n = matchsticks.size();
    int largest = 0;
    for (int i=0; i<n; i++) 
    {
        s += matchsticks[i];
        largest = max(matchsticks[i], largest);
    }
    bool possible = (s % 4) == 0 && largest <= s/4;
    if (possible) 
    {
        long long target = s/4;
        possible = search(matchsticks, 0, 0, 0, 0, 0, n, target);
    }
    return possible;
}
};