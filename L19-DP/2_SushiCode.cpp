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
ll n;
double dp[301][301][301];

double sushi(ll x, ll y, ll z) {
	if (x < 0 || y < 0 || z < 0) return 0;
	// base case
	if (!x and !y and !z) return dp[x][y][z] = 0;
	if (dp[x][y][z] > -1) return dp[x][y][z];
	// recusive case
	double sum = n + x * sushi(x - 1, y, z) + y * sushi(x + 1, y - 1, z) +
	             z * sushi(x, y + 1, z - 1);

	return dp[x][y][z] = sum / (x + y + z);
}

void solve() {

	memset(dp, -1, sizeof dp);
	cin >> n;
	ll ones = 0, twos = 0, threes = 0;
	for (int i = 0; i < n; ++i)
	{
		ll t; cin >> t;
		if (t == 1) ones++;
		else if (t == 2) twos++;
		else if (t == 3) threes++;
	}

	cout << fixed << setprecision(10) << sushi(ones, twos, threes) << endl;

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











