#include <bits/stdc++.h>
using namespace std;

const int N =7;
vector<int> adj[N];
bool visited[N];
int dist_source[N];
queue<int>q;

//this is the graph

        /*     1-----2------3
               |     |      |
               |     |      |
               |     |      |
               4     5------6     */

               //output_will : 1->2->4->3->5->6

void bfs(int x)
{
    dist_source[x]=0;
    visited[x]=true;
    q.push(x);


    while(!q.empty())
    {
        int s=q.front();
        cout<<s<<" ";
        q.pop();
        for(auto c: adj[s])
        {
            if(visited[c])continue;
            visited[c]=true;
            dist_source[c]=dist_source[s]+1;

            q.push(c);
        }
    }
    cout<<endl;
    for(int i=1;i<N;i++)
    {
        cout<<"Distance from source to "<<i<< " "<<dist_source[i]<<endl;
    }

}
int main()
{
    freopen("out.txt","w",stdout);
    //freopen("in.txt","r+",stdin);
    
   
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[2].push_back(5);
    adj[5].push_back(2);
    adj[3].push_back(6);
    adj[6].push_back(3);
    adj[6].push_back(5);
    adj[5].push_back(6);
    adj[1].push_back(4);
    adj[4].push_back(1);
    

    bfs(1);


    
    return 0;
}