class Solution {
public:
    void unionn(int x, int y, vector<int> &alpha){
        x = find(x, alpha);
        y = find(y, alpha);

        if(x!=y)
            alpha[max(x, y)] = min(x, y);
    }

    int find(int x, vector<int> &alpha){
        if(alpha[x]==-1)
            return x;

        return alpha[x] = find(alpha[x], alpha);
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> alpha(26, -1);

        for(int i=0; i<s1.size(); i++)
            unionn(s1[i]-'a', s2[i]-'a', alpha);

        for(int i=0; i<baseStr.size(); i++)
            baseStr[i] = find(baseStr[i]-'a', alpha)+'a';

        return baseStr;
    }
};