#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>T;
typedef long long ll;
template<class T> using pbset=tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<class T> using pbmultiset=tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans(n);
        int k=0;
        pbmultiset<int> st;
       
        for(int i=n-1;i>=0;i--)
        {
            ans[i]=st.order_of_key(nums[i]);
            st.insert(nums[i]);
            cout<<st.size()<<" ";
            k++;
        }
        return ans;
        
    }
};