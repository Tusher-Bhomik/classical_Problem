#include <bits/stdc++.h>
using namespace std;
vector<int >v;
int ans_V[1000];
int main()
{
    freopen("out.txt","w",stdout);
    freopen("in.txt","r+",stdin);
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
        ans_V[x]=1;
    }
    for(int i=1;i<1000;i++)
    {
        ans_V[i]=INT16_MAX;
        for (auto c :v)
        {
            if(i-c>=0)
            ans_V[i]=min(ans_V[i],ans_V[i-c]+1);
        }
    }
    cin>>x;
    cout<<ans_V[x]<<endl;

    return 0;
}