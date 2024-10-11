#define SORT(A) sort(A.begin(), A.end());
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tgt) {
        map<int,int> mp;
        vector<pair<int,int>> arr,dep;
        for(int i=0;i<times.size();i++){
           arr.push_back({times[i][0],i});
           dep.push_back({times[i][1],i});
        }
        SORT(arr);
        SORT(dep);
        set<int> st;
        for(int i=0;i<times.size();i++)
            st.insert(i);
        int i=0,j=0,n=times.size();
        while(i<n && j<n){
            if(arr[i].first<dep[j].first){
                int per=arr[i].second;
                mp[per]=*st.begin();
                st.erase(st.begin());
                if(per==tgt)
                    return mp[per];
                i++;
            }
            else{
                while(arr[i].first>=dep[j].first){
                    st.insert(mp[dep[j].second]);
                    mp.erase(dep[j].second);
                    j++;
                }
            }
        }
        return n;
    }
};