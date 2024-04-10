class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size(), 0);
        deque<int> d;

        for (int i = 0; i < deck.size(); i++)
        {
            d.push_back(i);
        }

        int i = 0;

        while (!d.empty())
        {
            int index = d.front();
            d.pop_front();
            res[index] = deck[i];
            i++;

            index = d.front();
            d.pop_front();
            d.push_back(index);
        }

        return res;
    }
};