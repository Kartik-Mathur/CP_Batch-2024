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

ll len, k;
string s;

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

void solve() {
	w(t) {
		cin >> len >> k;

		cin >> s;

		dsu d(len);
		// Combine all palindrome indexes
		for (int i = 0; i < len; ++i)
		{
			d.union_set(i, len - i - 1);
		}

		// Combine all k words
		for (int i = 0; i < len; ++i)
		{
			ll u = i;
			ll v = i + k;
			if (v < len) d.union_set(u, v);
		}

		vector<vector<ll> > freq(len, vector<ll> (26, 0));
		for (int i = 0; i < len; ++i)
		{
			char ch = s[i];
			ll leader = d.get(i);
			freq[leader][ch - 'a']++;
		}

		// Finding our answer
		ll ans = 0;
		for (int i = 0; i < len; ++i)
		{
			ll totalCharactersCount = 0;
			ll maxCharacterCount = 0;
			for (int j = 0; j < 26; ++j)
			{
				totalCharactersCount += freq[i][j];
				maxCharacterCount = max(maxCharacterCount, freq[i][j]);
			}
			ans += totalCharactersCount - maxCharacterCount;
		}

		cout << ans << endl;
	}

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











