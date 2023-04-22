typedef long long ll;
ll parent[200001];
ll siz[200001];
void make(ll v)
{
	parent[v]=v;
	siz[v]=1;
}
ll find(ll v)
{
	if(parent[v]==v)
	return v;
	else  //path compresssion
	return parent[v]=find(parent[v]);
}
void Union(ll a,ll b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{   //union by size
		if(siz[a]<siz[b])
		swap(a,b);
		parent[b]=a;
		siz[a]+=siz[b];
	}
}
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string bs) 
    {
        for(ll i=0;i<26;i++)make(i);
        for(ll i=0;i<s1.length();i++)
        Union(s1[i]-'a',s2[i]-'a');
        string ans="";
        for(ll i=0;i<bs.size();i++)
        {
            ll x=find(bs[i]-'a');
            for(ll i=0;i<26;i++)
            {
                if(parent[i]==x)
                {
                    ans+=char(i+'a');
                    break;
                }
            }
        }
        return ans;
    }
};