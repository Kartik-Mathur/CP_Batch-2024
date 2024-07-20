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

ll d, m;
string l, r;
ll dp[2000][2000][2][2][2];

ll magicNumber(string &s, ll pos, ll tight, ll current_mod, bool st, bool even) {
	// base case
	if (pos == s.size()) {
		return (current_mod == 0);
	}

	if (dp[pos][current_mod][tight][st][even] != -1)
		return dp[pos][current_mod][tight][st][even];


	// recursive case
	ll ans = 0;
	ll end = (tight) ? s[pos] - '0' : 9;

	// leading zero ka case is here
	if (st == 0) {
		ans = (ans + magicNumber(s, pos + 1, tight & (s[pos] - '0'), current_mod, 0, 0) % mod ) % mod;
		for (int i = 1; i <= end; ++i)
		{
			ans = (ans +
			       magicNumber(s, pos + 1, tight & (i == end), current_mod, 1, 1) % mod ) % mod;
		}
	}
	else {
		for (int i = 0; i <= end; ++i)
		{
			if (i == d and even) {
				ans = (ans + magicNumber(s, pos + 1, tight & (i == end), (current_mod * 10 + i) % m, st, !even) % mod ) % mod;
			}
			else if (i != d and !even) {
				ans = (ans + magicNumber(s, pos + 1, tight & (i == end), (current_mod * 10 + i) % m, st, !even) % mod ) % mod;
			}
		}
	}

	return dp[pos][current_mod][tight][st][even] = ans;
}

void solve() {
	memset(dp, -1, sizeof dp);

	cin >> m >> d;
	cin >> l >> r;

	ll ans = 0;
	ans = magicNumber(r, 0, 1, 0, 0, 0);

	memset(dp, -1, sizeof dp);
	ans = (ans - magicNumber(l, 0, 1, 0, 0, 0) + mod) % mod;

	// Check whether l is magic number or not brute force
	bool isMagicL = true;
	int x = 0;
	for (int i = 0; i < l.size(); ++i)
	{
		int temp = l[i] - '0';
		x = (x * 10 + temp) % m;
		if (i % 2 == 0) { // Ispr d nahi hona chahiye
			if (temp == d) {
				isMagicL = false;
				break;
			}
		}
		else { // ispr d hona chahiye
			if (temp != d) {
				isMagicL = false;
				break;
			}
		}
	}

	if (isMagicL and !x) cout << (ans + 1) % mod << endl;
	else cout << ans << endl;
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











