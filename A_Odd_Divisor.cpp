#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
int32_t main()
{
  ibs;cti;
  int t;cin>>t;while(t--){
	  int n;cin >> n;
	  if(bitset<70>(n).count() != 1)cout << "YES\n";
	  else cout <<"NO\n";
  }
  return 0;
}