#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <utility>
#include <numeric>
#define pb push_back
#define mk make_pair
#define endl "\n"
#define mod 1000000007
#define mod1 1610612741
#define mul 31
#define PI 3.14159265358979323846264
//#include bits/stdc++.h
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long int lli;
typedef long double ld;
typedef pair<lli, lli> ii;
//priority_queue <lli, vector<lli>, greater<lli> > ti;
//priority_queue<pair<lli,pair<lli,lli>>>e;
vector <lli> p[300005], q[300005], f(400005), a(300005), b(300005);
//vector<set<lli>>s(200005);
//set<pair<lli,lli>>s;
//vector<vector<lli>> dp(200005,vector<lli>(25,0));
//vector<lli>f(10000005);
//lli b[1000005],l[1000005];
//vector<vector<lli>> d(300005,vector<lli>(18,0));
//vector<pair<lli,ii>>p[300005];
//map<pair<lli,lli>,lli>mp;
//vector<pair<pair<lli, lli>,lli> > st;
//queue<lli> qy;
lli gcd(lli a, lli b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);

}
lli bpow(lli a, lli b) {
	lli res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return res % mod;
}
void fact(lli i)
{
	f[0] = 1;
	for (lli k = 1; k <= i; k++)
	{
		(f[k] = f[k - 1] * k) %= mod;
	}
}
lli isprime(lli n)
{
	if (n == 1)
		return 0;
	for (lli i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return 0;
	return 1;
}
lli find(lli x)
{
	if (f[x] == x)
		return x;
	else
		return f[x] = find(f[x]);
}
bool cmp(lli x, lli y)
{
	return x < y;
}
void check()
{
	cout << "HI" << endl;
}
lli comb(lli i, lli j)
{
	if (j > i)return 0;
	lli k = f[i];
	lli g = (f[j] * (f[i - j])) % mod;
	lli h = bpow(g, mod - 2);
	return (k * h) % mod;
}
pair<ld, ld>az(ld a, ld b, ld c, ld d, ld u)
{
	ld x1 = (a - c) * cos(u) - (b - d) * sin(u) + c;
	ld y1 = (a - c) * sin(u) + (b - d) * cos(u) + d;
	return {x1, y1};
}
/*void sieve()
{
    for(lli i=2;i<=sqrt(10000000);i++)
    {
        if(b[i]==0)
        {
            k.pb(i);
        for(lli j=2;i*j<=sqrt(10000000);j++)
        {
            b[i*j]=1;
        }
        }
    }
}*/

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t; cin >> t;
	while (t--)
	{
		lli n; cin >> n;
		vector<lli>x(n - 1);
		for (lli i = 0; i < n - 1; i++)
		{
			cin >> x[i];
		}
		lli s = 1000;
		vector<lli>ans;
		ans.pb(s);
		for (lli i = 0; i < x.size(); i++)
		{
			ans.pb(ans.back() + x[i]);
		}
		for (lli i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;

	}


}
