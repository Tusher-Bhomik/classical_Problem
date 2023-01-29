#include <bits/stdc++.h>
using namespace std;
vector<int> V;
int solve(int x)
{
    if(x<0) return INT16_MAX;
    if(x==0)return 0;
    int best=INT16_MAX;
    for(auto c :V)
    {
        best=min(best,solve(x-c)+1);
    }
    return best;
}

int main()
{
    freopen("out.txt","w",stdout);
    freopen("in.txt","r+",stdin);
    int n,x,total;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        V.push_back(x);
    }
    cin>>total;

    cout<<solve(total)<<endl;

    return 0;
}