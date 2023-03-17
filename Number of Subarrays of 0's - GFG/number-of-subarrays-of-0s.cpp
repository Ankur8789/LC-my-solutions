//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
typedef long long int ll;
long long int no_of_subarrays(int n, vector<int> &arr) 
{
    ll i=0,j=0;
    ll cc=0;
    ll on=0;
    while(j<n)
    {
        if(arr[j]==1)
        on++;
        while(on>0)
        {
            if(arr[i]==1)
            on--;
            i++;
        }
        cc+=(j-i+1);
        j++;
    }
    return cc;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends