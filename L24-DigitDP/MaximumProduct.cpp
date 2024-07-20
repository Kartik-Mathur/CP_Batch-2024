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

string a, b;
pair<ll, string> dp[20][2][2][2];

pair<ll, string> solve(ll pos, ll tighta, ll tightb, ll st) {
	// base case
	if (pos == a.size()) {
		return {1, ""};
	}

	if (dp[pos][tighta][tightb][st].first != -1) return dp[pos][tighta][tightb][st];

	// recursive case
	ll lb = tighta ? a[pos] - '0' : 0;
	ll ub = tightb ? b[pos] - '0' : 9;
	pair<ll, string> ans = { -1, ""};
	ll val;
	for (int i = lb; i <= ub; ++i)
	{

		if (st == 0 and i == 0) {
			val = 1;
		}
		else {
			val = i;
		}

		auto x = solve(pos + 1, tighta & (i == lb), tightb & (i == ub), st | (i > 0));
		if (val * x.first > ans.first) {
			ans.first = val * x.first;

			if (st == 0 and i == 0) {
				ans.second = x.second;
			}
			else {
				reverse(x.second.begin(), x.second.end());
				x.second.push_back(i + '0');
				reverse(x.second.begin(), x.second.end());
				ans.second = x.second;
			}
		}
	}

	return dp[pos][tighta][tightb][st] = ans;
}


void solve() {
	cin >> a >> b;

	reverse(a.begin(), a.end());
	while (a.size() < b.size()) a.push_back('0');
	reverse(a.begin(), a.end());

	// Initialise DP array
	for (int i = 0; i < 20; ++i)
		for (int j = 0; j < 2; ++j)
			for (int k = 0; k < 2; ++k)
				for (int l = 0; l < 2; ++l)
					dp[i][j][k][l].first = -1;

	pair <ll, string > ans = solve(0, 1, 1, 0);

	cout << ans.second << endl;
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











