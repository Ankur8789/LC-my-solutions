class Solution {
public:
    char f(char ch){
        if(ch=='z')
            return 'a';
        else
            return ch+1;
    }
    bool canMakeSubsequence(string str1, string str2) {
        int n=str1.size(),m=str2.size(),i=0,j=0;
        while(i<n && j<m){
            char a=str1[i],b=f(str1[i]);
            if(str2[j]==a || str2[j]==b){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return j==m;
    }
};