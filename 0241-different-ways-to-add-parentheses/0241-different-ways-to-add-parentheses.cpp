class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result;
        int n=expression.size();
        for(int i=0;i<n;i++)
        {
            char ch=expression[i];
            if(ch=='+'||ch=='-'||ch=='*')
            {
                vector<int> result1=diffWaysToCompute(expression.substr(0,i));
                vector<int> result2=diffWaysToCompute(expression.substr(i+1));
                for(auto j:result1)
                {
                    for(auto k:result2)
                    {
                        if(ch=='+')
                        result.push_back(j+k);
                        else if(ch=='-')
                        result.push_back(j-k);
                        else
                        result.push_back(j*k);
                    }
                }
            }
        }
        if(result.empty())
        result.push_back(stoi(expression));
        return result;
    }
};