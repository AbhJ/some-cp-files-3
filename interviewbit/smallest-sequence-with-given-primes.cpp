vector<int> Solution::solve(int A, int B, int C, int D) {
    set<int> s {A, B, C};
    vector<int> v;
    while (D--) {
        int x = *s.begin();
        s.erase (s.begin());
        s.emplace (x * A);
        s.emplace (x * B);
        s.emplace (x * C);
        v.emplace_back (x);
    }
    return v;
}
