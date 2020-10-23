
	#include <bits/stdc++.h>
	#define endl "\n"
	#define ll long long int
	#define vi vector<ll>
	#define vll vector<ll>
	#define vvi vector < vi >
	#define pii pair<ll,ll>
	#define pll pair<long long, long long>
	#define mod 1000000007
	#define inf 1000000000000000001;
	#define all(c) c.begin(),c.end()
	#define mp(x,y) make_pair(x,y) 
	#define mem(a,val) memset(a,val,sizeof(a))
	#define pb push_back
	#define f first
	#define s second
	
	using namespace std;
	
	signed main()
	{

	std::ios::sync_with_stdio(false);
	
	#ifndef ONLINE_JUDGE
      freopen("input.txt", "r", stdin);
      freopen("output.txt", "w", stdout);
     #endif

	int n; cin>>n;
	int a[n];
	bool p = true;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin>>a[i];
	}
	std::set<int> s;
	std::set<int> v;
	std::vector<int> q;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		if(s.size()==v.size()&&s.size()!=0){
				
					q.pb(2*s.size());
					s.clear();
					v.clear();
				}
		if(a[i]<0){
			if(s.count(-a[i]))
				if(v.count(-a[i])){
					p = false;
					break;
				}
				else
					v.insert(-a[i]);
			else{
				p=false;
				break;
			}
		}
		else{
			if(v.count(a[i])){
				if(s.size()!=v.size()){
					p = false;
					break;
				}
					q.pb(2*s.size());
					s.clear();
					v.clear();
			}
			else if(s.count(a[i])){
				p = false;
				break;
			}
			s.insert(a[i]);
		}
		}

		if(s.size()==v.size()){
			q.pb(2*s.size());
		}
		else
			p = false;
		if(p){
		cout<<q.size()<<endl;
		for (int i = 0; i < q.size(); ++i)
		{
			/* code */
			cout<<q[i]<<" ";
		}
	}
	else 
		cout<<-1<<endl;
	return 0;
	}
