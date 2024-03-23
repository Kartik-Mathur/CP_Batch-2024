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

const ll N = 1e7 + 1;
bitset<10000001> bs;
ll a[N] = {0}, csum[N] = {0};
ll n, mx = 0;

void sieve(int n) {
	bs.set(); // set all the bits to 1
	bs[0] = bs[1] = 0; // Not a prime number

	for (int i = 2; i * i <= n; ++i)
	{
		if (bs[i] == 1) {
			for (int j = i * i; j <= n; j += i)
			{
				bs[j] = 0;
			}
		}
	}
}


void solve() {
	sieve(10000001);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		ll x; cin >> x;
		a[x]++;
		mx = max(mx, x);
	}
	// Find cumulative sum
	for (int i = 2; i <= mx; ++i)
	{
		csum[i] = csum[i - 1];
		if (bs[i] == 0) continue;
		// csum[i] += a[i];
		for (int j = i; j <= mx; j += i)
		{
			csum[i] += a[j];
		}
	}
	// for (int i = 2; i <= mx; ++i)
	// {
	// 	cout << csum[i] << " ";
	// }
	// cout << endl;
	// queries
	ll m, li, ri; cin >> m;
	while (m--) {
		cin >> li >> ri;
		cout << csum[min(ri, mx)] - csum[min(li - 1, mx)] << endl;
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











