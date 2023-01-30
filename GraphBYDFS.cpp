#include <bits/stdc++.h>
using namespace std;
const int N =7;
vector<int> v[N];
bool visited[N];


//this is the graph

        /*     1-----2------3
               |     |      |
               |     |      |
               |     |      |
               4     5------6     */

               //output_will : 1->2->3->6->5->4

void dfs(int x)
{
    if(visited[x])return;
    visited[x]=true;
    cout<<x<<" ";
    for(auto c:v[x])
    {
        dfs(c);
    }
}

int main()
{
   
    v[1].push_back(2);
    v[2].push_back(1);
    v[2].push_back(3);
    v[3].push_back(2);
    v[2].push_back(5);
    v[5].push_back(2);
    v[3].push_back(6);
    v[6].push_back(3);
    v[6].push_back(5);
    v[5].push_back(6);
    v[1].push_back(4);
    v[4].push_back(1);


    dfs(1);
   
    return 0;
}
