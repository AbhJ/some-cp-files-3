//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 04 in 08 : 40 : 35
//title - E_Oversleeping.cpp
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
#include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
pii inv_gcd(int a, int b) {
    a = ((a + b) % b);
    if (a == 0) return {b, 0};
    int s = b, t = a;
    int m0 = 0, m1 = 1;
    while (t) {
        int u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    if (m0 < 0) m0 += b / s;
    return pii{s, m0};
}
pii crt_solution(const vi &r, const vi &m) {
    assert(r.size() == m.size());
    int n = (int)(r.size());
    int r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        assert(1 <= m[i]);
        int r1 = ((r[i] + m[i]) % m[i]), m1 = m[i];
        if (m0 < m1) {
            std::swap(r0, r1);
            std::swap(m0, m1);
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return {0, 0};
            continue;
        }
        int g, im;
        std::tie(g, im) = inv_gcd(m0, m1);
        int u1 = (m1 / g);
        if ((r1 - r0) % g) return pii{0, 0};
        int x = (r1 - r0) / g % u1 * im % u1;
        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0) r0 += m0;
    }
	//ans, lcm of all m s
	//0, 0 is returned if no solution
    return pii{r0, m0};
}
int isprime(int x){
	rep(i, 2, sqrt(x))
		if(x % i == 0)
			return 0;
	return 1;
}
int x, y, p, q;vi v;
void solve(){
	cin >> x >> y >> p >> q;
	v.clear();
	rep(i, p, p + q - 1)
		rep(j, x, x + y - 1){
			// if(isprime(i) and isprime(j))
				if(crt_solution(vi{i, j}, vi{p + q, 2 * (x + y)}).S != 0)
					v.pb(crt_solution(vi{i, j}, vi{p + q, 2 * (x + y)}).F);
		}
	(v.empty() == 1) ? (cout << "infinity") : (cout << *min_element(all(v)));
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}