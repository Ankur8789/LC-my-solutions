class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
    {
         for(int i=0;i<image.size();i++)
         {
             reverse(image[i].begin(),image[i].end());
         }
         for(auto& t: image)
         {
             for(auto& x: t)
             {
                 if(x==1)
                     x=0;
                 else
                     x=1;
             }
         }
        return image;
    }
};