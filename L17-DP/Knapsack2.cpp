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
ll dp[105][100005] = {0};

void solve() {
	ll N, capacity;
	ll price[100005], wt[100005];
	cin >> N >> capacity;
	ll maxProfit = 0;
	for (ll i = 0; i < N; ++i)
	{
		cin >> wt[i] >> price[i];
		maxProfit += price[i];
	}

	for (ll profit = 1; profit <= maxProfit; ++profit)
		dp[0][profit] = INT_MAX;

	dp[0][0] = 0;

	for (ll n = 1; n <= N; ++n)
	{
		for (ll profit = 1; profit <= maxProfit; ++profit)
		{
			ll op1 = INT_MAX, op2 = INT_MAX;
			if (price[n - 1] <= profit) {
				if (dp[n - 1][profit - price[n - 1]] != INT_MAX)
					op1 = wt[n - 1] + dp[n - 1][profit - price[n - 1]];
			}
			op2 = dp[n - 1][profit];
			dp[n][profit] = min(op1, op2);
		}
	}
	ll ans = 0;
	for (ll profit = 1; profit <= maxProfit; ++profit) {
		if (dp[N][profit] <= capacity) ans = profit;
	}

	cout << ans << endl;
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










