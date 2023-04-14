#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>T;
typedef long long ll;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
int ppc(int n)
{
    ll c = 0;
    for (; n; ++c)
        n &= n - 1;
    return c;
}
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k)
    {
        set<int> st;
        pbmset<int> ms;
        vector<int> bts;
        for(auto t: nums)
        {
            if(st.find(t)==st.end())
            {
                st.insert(t);
                int cnt=ppc(t);
                bts.push_back(cnt);
                ms.insert(-1*cnt);
            }
        }
        ll ans=0;
        for(auto t: bts)
        {
            ans+=ms.order_of_key(t-k+1);
        }
        return ans;
        
        
    }
};