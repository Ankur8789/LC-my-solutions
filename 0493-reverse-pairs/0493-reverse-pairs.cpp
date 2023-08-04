#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T;
typedef long long ll;
typedef long double ld;
template <class T>
using pbset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T>
using pbmultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    int reversePairs(vector<int>& nums) 
    {
        pbmultiset<ll> ms;
        ll ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ll temp=ms.size()-ms.order_of_key(2LL*nums[i]+1LL);
            ans+=temp;
            ms.insert(nums[i]);
        }
        return ans;
    }
};