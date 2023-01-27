#include<bits/stdc++.h>
#define pr pair<int, int>
#define S second
#define F first
#define ll long long int
#define DD double
using namespace std;




bool ComparePairs(const pair<DD, DD> &a, const pair<DD, DD> &b)
{
    return a.first > b.first;
}

int main()
{
    freopen("in.txt","r+",stdin);
    
    int n;
    cin >> n; // number of items
    DD w[n], v[n], W;
    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    cin >> W;
    vector<pair<DD, DD>> v_pWeight;
    for (int i = 0; i < n; i++)
    {
        v_pWeight.push_back({v[i] / w[i], w[i]});
    }

    sort(v_pWeight.begin(), v_pWeight.end(), ComparePairs);
    for (int i=0;i<n;i++)
    {
        cout<<v_pWeight[i].first<<" "<<v_pWeight[i].second<<endl;

    }

    DD q = 0;
    DD final_value = 0;
    int i = 0;
    bool flag = true;
    while (flag)
    {
        q += v_pWeight[i].second;
        if (q > W)
        {
            q -= v_pWeight[i].second;
            final_value += (W - q) * v_pWeight[i].first;
            flag=false;
        }
        else
        {
            final_value += v_pWeight[i].first * v_pWeight[i].second;
            cout<<final_value<<endl;
        }
        i++;
    }
    cout << "Total value in Knapsack: " << final_value << endl;
    return 0;
}