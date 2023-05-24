//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int N, int gs, vector<int> &hand) 
    {
        if(N % gs!=0 )
        return false;
        multiset<int> ms;
        for(auto t: hand)
        ms.insert(t);
        while(ms.size()>0)
        {
            int val=*ms.begin();
            int ct=1;
            while(ct<gs)
            {
                if(ms.find(val+1)==ms.end())
                return false;
                ms.erase(ms.find(val+1));
                val++;
                ct++;
            }
            ms.erase(ms.begin());
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends