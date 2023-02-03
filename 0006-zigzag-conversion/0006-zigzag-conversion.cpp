class Solution {
public:
    string convert(string s, int numRows) 
    {
        
        if ( numRows == 1 ) return s; 

        int n = s.size();

        vector < string > results(numRows, "");
        int cnt = 0, flag = 0, j = 0, k = 0;

        for ( int i = 0; i < n; i++ ) 
        {
            if ( !flag and cnt < numRows ) 
            {
                results[j++] += s[i];
                cnt += 1;
                continue;
            }

            if ( !flag and cnt == numRows ) 
            {

                flag = 1;
                cnt = 0;
                j = 0;
                k = numRows - 2;

            }

            if ( flag and cnt < numRows - 2 ) 
            {

                results[k--] += s[i];
                cnt += 1;
                continue;
 
            }

            if ( flag and cnt == numRows - 2 ) 
            {

                flag = 0;
                cnt = 1;
                j = 1;
                results[0] += s[i]; 

            }

        }

        string ans = "";

        for ( auto i : results ) ans += i;

        return ans;

    }
};