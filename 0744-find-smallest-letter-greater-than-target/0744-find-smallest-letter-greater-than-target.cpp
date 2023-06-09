class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        for(auto t: letters)
        {
            if(t>target)
                return t;
        }
        return letters[0];
    }
};