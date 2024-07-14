class Solution
{
public:
    string countOfAtoms(string formula)
    {
        std::map<string, int> stats;
        std::reverse(formula.begin(), formula.end());
        compute(formula, stats);
        string result;

        for (auto &kv : stats)
        {
            result += kv.first;
            if (kv.second > 1)
            {
                result += std::to_string(kv.second);
            }
        }
        return result;
    }

private:
    void compute(string &formula, std::map<string, int> &stats)
    {
        int n = formula.size();

        std::stack<int> stk;
        stk.push(1);

        string elem;
        int factor = 1;
        for (int i = 0; i < n; ++i)
        {
            auto &c = formula[i];
            if (isdigit(c))
            {
                int val = 0, expo = 1;
                do
                {
                    val += (c - '0') * expo;
                    ++i;
                    expo *= 10;
                } while (isdigit(c = formula[i]));
                factor = val;

                i -= 1;
            }
            else if (c == ')')
            {
                stk.push(factor * stk.top());
                factor = 1;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                elem += c;
                std::reverse(elem.begin(), elem.end());
                stats[elem] += factor * stk.top();
                factor = 1;
                elem.clear();
            }
            else if (c >= 'a' && c <= 'z')
            {
                elem += c;
            }
            else
            {
                stk.pop();
            }
        }
    }
};