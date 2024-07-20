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
vector<ll> order;
ll cost[AS];

void dfs(ll src, vector<ll> x[], bool *visited) {
	visited[src] = true;
	for (auto child : x[src]) {
		if (!visited[child]) dfs(child, x, visited);
	}
	order.push_back(src);
}

void dfsR(ll src, vector<ll> x[], bool *visited,
          vector<int> ans[], int component) {
	visited[src] = true;
	ans[component].push_back(src);
	for (auto child : x[src]) {
		if (!visited[child]) dfsR(child, x, visited, ans, component);
	}
}

void kosaraju(vector<ll> g[], vector<ll> rg[], ll N) {
	// 1. DFS on normal graph
	bool visited[100000] = {0};


	for (ll i = 1; i <= N; i++) {
		if (!visited[i]) dfs(i, g, visited);
	}
	// 2. find the reverse graph
	// We already have it

	// 3. DFS on reverse graph
	bool reverse_visited[100000] = {0};
	ll component = 1;
	vector<int> ans[N + 1];
	for (ll i = order.size() - 1 ; i >= 0 ; i--) {

		if (!reverse_visited[order[i]]) {
			// cout << "Component " << component << " : ";
			dfsR(order[i], rg, reverse_visited, ans, component);
			// cout << endl;
			component++;
		}
	}

	// for (ll i = 1; i < component; i++) {
	// 	cout << "Component " << i << " : ";
	// 	for (auto n : ans[i]) {
	// 		cout << n << " ";
	// 	}
	// 	cout  << endl;
	// }

	vector<pair<ll, ll> > minCost;


	for (ll i = 1; i < component ; ++i) {
		ll nodes = 1;
		ll mi = 1e15;
		for (auto n : ans[i]) {
			if (mi > cost[n]) {
				mi = cost[n];
				nodes = 1;
			}
			else if (mi == cost[n]) nodes++;
		}

		minCost.push_back({mi, nodes});
	}

	ll costSum = 0;
	ll ways = 1;
	for (auto n : minCost) {
		// cout << n.first << ", " << n.second << endl;
		costSum += n.first;
		ways = ((ways % mod) * (n.second % mod)) % mod;
	}

	cout << costSum << " " << ways << endl;
}

void solve() {
	ll N, edges, u, v;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> cost[i];
	}

	vector<ll> g[N + 1];
	vector<ll> rg[N + 1];
	cin >> edges;

	for (ll i = 0; i < edges; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}

	kosaraju(g, rg, N);

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











