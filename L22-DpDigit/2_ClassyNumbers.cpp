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

ll dp[20][2][20];
ll l, r;

ll classy(string &s, ll pos, ll cnt, ll tight) {
	// base case
	if (pos == s.size()) {
		return dp[pos][tight][cnt] =  cnt <= 3;
	}

	if (dp[pos][tight][cnt] != -1) {
		return dp[pos][tight][cnt];
	}

	// recursive case
	ll end = tight ? (s[pos] - '0') : 9;
	ll ans = 0;
	for (int i = 0; i <= end; ++i)
	{
		ans = ans + classy(s, pos + 1, cnt + (i > 0), tight & (i == end));
	}
	return dp[pos][tight][cnt] = ans;
}

void solve() {
	memset(dp, -1, sizeof dp);
	w(t) {
		cin >> l >> r;
		memset(dp, -1, sizeof dp);
		ll ans = 0;
		string x = to_string(r);
		ans = classy(x, 0, 0, 1);

		memset(dp, -1, sizeof dp);
		string y = to_string(l - 1);
		ans -= classy(y, 0, 0, 1);
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











