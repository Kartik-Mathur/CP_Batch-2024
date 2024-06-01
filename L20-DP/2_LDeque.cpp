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

ll dp[3001][3001][3];
ll n;
ll a[3001];

ll game(ll i, ll j, ll player) {
	if (i > j) return 0;

	if (dp[i][j][player] != -1) return dp[i][j][player];


	if (player == 1) {
		// game(i+1,j,2): max score that p1 can make if p2 plays
		// for subarray [i+1,j]
		// game(i,j-1,2): max score that p1 can make if p2 plays
		// for subarray [i,j-1]
		return dp[i][j][player] = max(
		                              a[i] + game(i + 1, j, 2),
		                              a[j] + game(i, j - 1, 2)
		                          );
	}
	// Player 2 is playing the game here
	// We are calculating the profit which player 1 can make
	// Player 2 would never let p1 have the max score
	return dp[i][j][player] = min(
	                              game(i + 1, j, 1),
	                              game(i, j - 1, 1)
	                          );
}

void solve() {
	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], sum += a[i];
	memset(dp, -1, sizeof dp);

	ll x = game(1, n, 1);

	ll y = sum - x;

	cout << x - y << endl;
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











