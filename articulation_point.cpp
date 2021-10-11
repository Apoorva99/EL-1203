#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define f(i,a,b) for(i=a;i<b;i++)
#define fr(i,a,b) for(i=a;i>=b;i--)
#define endl '\n'
#define ll long long int
#define ff first
#define ss second
#define pb push_back
using namespace std;

vector<int> adj[100], parent(100), ap(100), low(100), tin(100),visit(100);
int timer;

void dfs(int x)
{
    visit[x]=1;
    low[x]=tin[x]=++timer;
    int child=0;
    for(auto y: adj[x])
    {
        if(!visit[y])
        {
            child++;
            parent[y]=x;
            dfs(y);
            if(parent[x]==0 and child>1)
                ap[x]=1;
            if(parent[x]!=0 and tin[x]<=low[y])
                ap[x]=1;
            low[x]=min(low[x], low[y]);
        }
        else if(x!=parent[y])
            low[x]=min(low[x], tin[y]);
    }
}

int main()
{
    fast;
    int n,m,x,y,i;
    cin>>n>>m;
    f(i,0,m)
        cin>>x>>y, adj[x].pb(y), adj[y].pb(x);

    dfs(1);
    f(i,1,n+1)
        if(ap[i])
            cout<<i<<' ';
}