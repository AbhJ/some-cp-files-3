/**
 * @author      : abhj
 * @created     : Sunday Aug 01, 2021 17:36:12 IST
 * @filename    : a.cpp
 */

#include "bits/stdc++.h"
#define int          long long int
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int n    =     5e6 + 10;
int M = 52 * 52 * 52;
int char_to_int(char c) {
    if('A'<=c && c<='Z') return c-'A';
    else return c-'a'+26;
}
int string_to_int(char a,char b,char c) {
    return char_to_int(a) * 52 * 52 + char_to_int(b) * 52 + char_to_int(c);
}
void solve () {
    int n;
    cin >> n;
    vector<pair<int,int>> edge(n);
    vector<vector<int>> revGraph(M);
    vector<int> cnt(M);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        edge[i] = make_pair(string_to_int(s[0], s[1], s[2]), string_to_int(s[s.length()-3], s[s.length()-2], s[s.length()-1]));
        cnt[edge[i].first]++;
        revGraph[edge[i].second].pb(edge[i].first);
    }
    vector<int> ans(M, -1);
    queue<int> que;
    for(int i = 0; i < M; i++) if(cnt[i] == 0) {
            ans[i] = 0;
            que.push(i);
        }
    while(!que.empty()) {
        int t = que.front();
        que.pop();
        for(int x : revGraph[t]) if(ans[x] == -1) {
                cnt[x]--;
                if(ans[t] == 0) {
                    ans[x] = 1;
                    que.push(x);
                }
                else if(cnt[x] == 0) {
                    ans[x] = 0;
                    que.push(x);
                }
            }
    }
    for(int i = 0; i < n; i++) {
        if(ans[edge[i].second] == -1) cout << "Draw" << endl;
        if(ans[edge[i].second] == 0) cout << "Takahashi" << endl;
        if(ans[edge[i].second] == 1) cout << "Aoki" << endl;
    }
}

int32_t main() {
    solve();
    return 0;
}
