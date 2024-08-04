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
#define 	AS 5000001
#define 	mod 1000000007

class dsu {
public:
	vector<ll> parent, rank;
	dsu(ll n) {
		parent.resize(n + 1);
		rank.resize(n + 1, 1);
		for (ll i = 0; i <= n; ++i)
		{
			parent[i] = i;
			rank[i] = 1;
		}
	}

	ll get(ll u) { // Get the leader of u
		if (parent[u] == u)  return u;

		return parent[u] = get(parent[u]);  // path compression
	}

	void union_set(ll u, ll v) {
		ll leader_u = get(u);
		ll leader_v = get(v);

		if (leader_u != leader_v) {
			if (rank[leader_v] > rank[leader_u]) {
				swap(leader_u, leader_v);
			}

			parent[leader_v] = leader_u;
			if (rank[leader_u] == rank[leader_v]) {
				rank[leader_u]++;
			}
		}
	}
};
class graph {
public:
	ll wt, u, v;
	graph() {}
	graph(ll wt, ll u, ll v) {
		this->wt  = wt;
		this->u  = u;
		this->v  = v;
	}
};

ll n, it = 0;
ll x[2005], y[2005], c[2005], k[2005];
graph edges[AS];
vector<ll> powerStation;
vector<vector<ll> > cities;

void kruskal() {
	sort(edges, edges + it, [ = ](graph a, graph b) {
		return a.wt < b.wt;
	});
	dsu d(n + 1);
	ll ans = 0;
	ll components = 0;
	for (int i = 0 ; i < it ; i++) {
		ll wt = edges[i].wt;
		ll u = edges[i].u;
		ll v = edges[i].v;

		ll leader_u = d.get(u);
		ll leader_v = d.get(v);

		if (leader_u != leader_v) {
			ans += wt;
			if (!u) powerStation.push_back(v);
			else if (!v) powerStation.push_back(u);
			else cities.push_back({u, v});

			d.union_set(u, v);
			components ++;

			if (components == n) break;
		}

	}

	cout << ans << endl;
	cout << powerStation.size() << endl;
	for (auto p : powerStation) cout << p << " ";
	cout << endl;
	cout << cities.size() << endl;
	for (auto city : cities) {
		cout << city[0] << " " << city[1] << endl;
	}
}

void solve() {

	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		ll xi, yi; cin >> xi >> yi;
		x[i] = xi;
		y[i] = yi;
	}

	F1(c, n);
	F1(k, n);

	for (int i = 1; i <= n; ++i) {
		edges[it++] = graph(c[i], i, 0);
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			ll distance = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			ll cost = k[i] + k[j];
			edges[it++] = graph(cost * distance, i, j);
		}
	}


	kruskal();

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











