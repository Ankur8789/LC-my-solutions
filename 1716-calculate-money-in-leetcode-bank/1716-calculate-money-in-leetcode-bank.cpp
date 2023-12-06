class Solution
{
public:
    int totalMoney(int n)
    {
        int a = (int)n / 7;
        int b = n % 7;
        int result = 7 * a * (a + 7) / 2;
        for (int i = 1; i <= b; i++)
            result += a + i;
        return result;
    }
};