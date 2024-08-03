#include <bits/stdc++.h>
using namespace std;

#define 	ll long long int
#define 	new(a,n) ll*a = new ll[n]
#define 	new1(a,n,m) ll**a = new ll*[n]; for(ll i = 0 ; i < n ; i++) a[i] = new ll[m];
#define 	mp make_pair
#define 	pb push_back
#define 	fi first
#define 	pii pair<ll,ll>
#define 	si second
#define 	fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define 	F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define 	F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define 	P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define 	P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define 	NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define 	NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define 	PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define 	PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define 	init(a,n,v) for(int i = 0 ; i <n ; i++) a[i]=v;
#define 	init2(a,n,m,v) for(int i=0;i<=n;i++){for(int j=0;j<=m;j++){a[i][j]=v;}}
#define 	w(t) int t;cin>>t;while(t--)
#define 	f(n) for(int __i=0;__i<n;__i++)
#define 	AS 200001
#define 	mod 1000000007

vector<ll> g[AS];
ll n, edges, m;
vector<ll> path;


void navigation() {
	ll des = path[m - 1], src = path[0];
	vector<ll> distance(n + 1, -1);
	vector<ll> cnt(n + 1, 0);

	queue<ll> q;
	q.push(des);
	distance[des] = 0;

	while (!q.empty()) {
		ll parent = q.front();
		q.pop();

		for (auto child : g[parent]) {
			if (distance[child] == -1) {
				distance[child] = distance[parent] + 1;
				q.push(child);
			}
			else if (distance[child] == distance[parent] + 1) {
				cnt[child] = 1;
			}
		}
	}

	// Count Rebuilds
	int max_R = 0, min_R = 0;

	for (int i = 0; i < m - 1; ++i)
	{
		ll u = path[i], v = path[i + 1];
		if (distance[u] != distance[v] + 1) max_R++, min_R++;
		else if (cnt[u]) max_R++;
	}
	cout << min_R << " " << max_R << endl;
}



void solve() {

	cin >> n >> edges;

	for (int i = 0; i < edges; ++i)
	{
		ll u, v; cin >> u >> v;
		g[v].push_back(u); // Reverse Graph
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		ll x; cin >> x;
		path.push_back(x);
	}
	navigation();
}

int main() {
	fastIO
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}



























