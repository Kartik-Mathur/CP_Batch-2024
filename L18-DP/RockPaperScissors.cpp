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

double dp[101][101][101];

double paperSurvives(ll r, ll p, ll s) {
	if (p == 0 || r == 0) return dp[p][r][s] = 0.0;
	if (s == 0) return dp[p][r][s] = 1.0;

	if (dp[p][r][s] > -1) return dp[p][r][s];

	double ans = 0;
	double total = r * s + r * p + s * p;
	ans += (r * s / total) * paperSurvives(r, p, s - 1); // rock kills scissor
	ans += (p * r / total) * paperSurvives(r - 1, p, s); // paper kills rock
	ans += (s * p / total) * paperSurvives(r, p - 1, s); // scissor kills paper
	return dp[p][r][s] = ans;
}

double scissorSurvives(ll r, ll p, ll s) {
	if (s == 0 || p == 0) return dp[p][r][s] = 0.0;
	if (r == 0) return dp[p][r][s] = 1.0;

	if (dp[p][r][s] > -1) return dp[p][r][s];

	double ans = 0;
	double total = r * s + r * p + s * p;
	ans += (r * s / total) * scissorSurvives(r, p, s - 1); // rock kills scissor
	ans += (p * r / total) * scissorSurvives(r - 1, p, s); // paper kills rock
	ans += (s * p / total) * scissorSurvives(r, p - 1, s); // scissor kills paper
	return dp[p][r][s] = ans;
}

double rockSurvives(ll p, ll r, ll s) {
	if (r == 0 || s == 0) return dp[p][r][s] = 0.0;
	if (p == 0) return dp[p][r][s] = 1.0;

	if (dp[p][r][s] > -1) return dp[p][r][s];

	double ans = 0;
	double total = r * s + r * p + s * p;
	ans += (r * s / total) * rockSurvives(p, r, s - 1); // rock kills scissor
	ans += (p * r / total) * rockSurvives(p, r - 1, s); // paper kills rock
	ans += (s * p / total) * rockSurvives(p - 1, r, s); // scissor kills paper
	return dp[p][r][s] = ans;
}

void solve() {
	w(t) {
		ll r, p, s;

		cin >> r >> s >> p;
		memset(dp, -1, sizeof dp);
		cout << fixed << setprecision(9) << rockSurvives(p, r, s) << " ";
		memset(dp, -1, sizeof dp);
		cout << fixed << setprecision(9) << scissorSurvives(r, p, s) << " ";
		memset(dp, -1, sizeof dp);
		cout << fixed << setprecision(9) << paperSurvives(r, p, s) << endl;
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











