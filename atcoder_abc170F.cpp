//Coded by Abhijay Mitra
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
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb push_back
#define res(v) v.resize(unique(v.begin(), v.end()) - v.begin());
#define cnt_res(v) std::distance(v.begin(),std::unique(v.begin(), v.end())); 
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
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
const double Pi = 3.14159265;
#define F first
#define S second
vvi dp,vis,visa;vector<string>s;int X1,Y1,X2,Y2,K,ans=inf;int h,w;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(int i,int j){
  queue<pair<pii,int>>q;
  q.push({{i,j},0});
  while(q.empty()==0){
    auto z=q.front();q.pop();
    if(z.F==mp(X2,Y2)){ans=min(ans,z.S);break;}
    vis[z.F.F][z.F.S]=1;
    visa[z.F.F][z.F.S]=1;
    rep(k,0,3)
      rep(I,1,K){
        int x=z.F.F+I*dx[k],y=z.F.S+I*dy[k];
        if(x<h and x>=0 and y<w and y>=0 and s[x][y]=='.'){
          if(vis[x][y]==0)q.push({{x,y},z.S+1}),vis[x][y]=1;
        }
        if(x<h and x>=0 and y<w and y>=0 and s[x][y]=='@')break;
        if(x<h and x>=0 and y<w and y>=0 and visa[x][y]==1)break;
        if(x>=h or x<0 or y<0 or y>=w)break;
      }
  }
}
void solve(){
  cin>>h>>w>>K;
  s=vector<string>(h);
  dp=vis=visa=vvi(h,vi(w,0));
  cin>>X1>>Y1>>X2>>Y2;
  rep(i,0,h-1)cin>>s[i];
  X1--,Y1--,X2--,Y2--;
  bfs(X1,Y1);
  if(ans==inf)cout<<-1;else
  cout<<ans;
}
int32_t main()
{
  ibs;cti;
  solve()
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  // int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}