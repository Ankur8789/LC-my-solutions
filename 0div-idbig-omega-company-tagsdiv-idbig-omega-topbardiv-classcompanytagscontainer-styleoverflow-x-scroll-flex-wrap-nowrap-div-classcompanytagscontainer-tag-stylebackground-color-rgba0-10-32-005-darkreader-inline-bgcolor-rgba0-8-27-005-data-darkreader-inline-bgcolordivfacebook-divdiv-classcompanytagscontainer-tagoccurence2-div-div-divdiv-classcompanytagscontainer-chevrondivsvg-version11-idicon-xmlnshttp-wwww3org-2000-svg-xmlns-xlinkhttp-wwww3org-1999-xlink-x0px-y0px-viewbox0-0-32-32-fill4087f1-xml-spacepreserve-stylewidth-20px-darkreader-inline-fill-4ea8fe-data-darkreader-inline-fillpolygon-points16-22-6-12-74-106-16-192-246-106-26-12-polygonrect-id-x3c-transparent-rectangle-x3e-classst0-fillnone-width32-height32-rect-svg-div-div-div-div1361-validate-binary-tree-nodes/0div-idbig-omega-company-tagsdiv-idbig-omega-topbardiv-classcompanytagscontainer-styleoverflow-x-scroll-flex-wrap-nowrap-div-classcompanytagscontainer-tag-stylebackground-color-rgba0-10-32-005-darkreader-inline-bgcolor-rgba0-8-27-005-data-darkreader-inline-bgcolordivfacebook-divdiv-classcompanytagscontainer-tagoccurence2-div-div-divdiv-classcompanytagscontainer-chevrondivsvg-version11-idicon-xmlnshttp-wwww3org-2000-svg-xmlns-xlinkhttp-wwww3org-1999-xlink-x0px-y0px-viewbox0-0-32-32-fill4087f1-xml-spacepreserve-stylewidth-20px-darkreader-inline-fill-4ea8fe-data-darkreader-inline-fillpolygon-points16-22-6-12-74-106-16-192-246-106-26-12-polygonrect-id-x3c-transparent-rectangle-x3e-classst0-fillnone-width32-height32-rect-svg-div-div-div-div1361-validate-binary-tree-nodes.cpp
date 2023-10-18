class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftchild, vector<int> &rightchild)
    {

        vector<int> par(n, -1);
        vector<int> ind(n, 0);

        for (int i = 0; i < n; ++i)
        {
            if (leftchild[i] != -1)
            {
                if (par[i] == leftchild[i])
                    return false;

                if (par[i] == -1)
                    par[leftchild[i]] = i;
                else
                {
                    par[leftchild[i]] = par[i];
                }
                ind[leftchild[i]]++;
                if (ind[leftchild[i]] >= 2)
                    return false;
            }
            if (rightchild[i] != -1)
            {
                if (par[i] == rightchild[i])
                    return false;
                if (par[i] == -1)
                    par[rightchild[i]] = i;
                else
                {
                    par[rightchild[i]] = par[i];
                }
                ind[rightchild[i]]++;
                if (ind[rightchild[i]] >= 2)
                    return false;
            }
        }
        int ct = 0;
        for (int i = 0; i < n; ++i)
        {
            if (par[i] == -1)
            {
                ct++;
            }
        }
        if (ct != 1)
            return false;

        return true;
    }
};