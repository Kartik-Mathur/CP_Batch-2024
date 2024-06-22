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
ll n, q;
ll arr[AS];
vector<vector<pair<ll, ll> > > queries(AS);

void fun() {
	set<ll> s;
	s.insert(0);
	ll ans = 1;
	vector<ll> finalAns(q + 1, 0);

	for (int i = 1; i <= n; ++i)
	{
		if (s.find(arr[i]) != s.end()) {
			ans = ((ans % mod) * 2) % mod;
		}
		else {
			vector<ll> temp;
			for (auto v : s) temp.push_back(v ^ arr[i]);
			for (auto v : temp) s.insert(v);
		}

		for (auto p : queries[i]) {
			int indx = p.first;
			int xor_required = p.second;
			if (s.find(xor_required) != s.end()) {
				finalAns[indx] = ans;
			}
			else {
				finalAns[indx] = 0;
			}
		}
	}

	for (int i = 1; i <= q; ++i)
	{
		cout << finalAns[i] << endl;
	}
}

void solve() {
	cin >> n;
	cin >> q;

	F1(arr, n);
	for (int i = 1; i <= q; ++i)
	{
		ll l, x; cin >> l >> x;
		queries[l].push_back({i, x});

	}

	fun();
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











