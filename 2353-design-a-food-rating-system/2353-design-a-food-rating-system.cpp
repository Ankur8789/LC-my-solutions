class FoodRatings
{
public:
    unordered_map<string, int> foora;
    unordered_map<string, string> foocu;
    unordered_map<string, set<pair<int, string>>> cufoo;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
            foora[foods[i]] = ratings[i];
        for (int i = 0; i < foods.size(); i++)
            foocu[foods[i]] = cuisines[i];
        for (int i = 0; i < cuisines.size(); i++)
        {
            cufoo[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        string cus = foocu[food];
        int old = foora[food];
        cufoo[cus].erase({-old, food});
        foora[food] = newRating;
        cufoo[cus].insert({-newRating, food});
    }

    string highestRated(string cuisine)
    {
        return (cufoo[cuisine].begin())->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */