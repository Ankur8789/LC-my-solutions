class Solution
{
   public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> freq(26);
        if (n == 0)
            return tasks.size();

        for (int i = 0; i < tasks.size(); i++)
        {
            int x = tasks[i] - 'A';
            freq[x]++;
        }
        sort(freq.begin(), freq.end());
        int frameSize = (freq[25] - 1);
        int vacate = (freq[25] - 1) * n;
        for (int i = 0; i < 25; i++)
        {
            vacate -= min(frameSize, freq[i]);
        }

        return vacate > 0 ? tasks.size() + vacate : tasks.size();
    }
};
