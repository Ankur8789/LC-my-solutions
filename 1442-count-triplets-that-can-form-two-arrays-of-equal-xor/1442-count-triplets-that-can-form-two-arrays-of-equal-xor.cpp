class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a, b, count = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            a = 0;
            for(int j = i + 1; j < arr.size(); j++)
            {
                a ^= arr[j-1];
                b = 0;
                for(int k = j; k < arr.size(); k++)
                {
                    b ^= arr[k];
                    if(a == b)
                        count++;
                }
            }
        }
        return count;
    }
};