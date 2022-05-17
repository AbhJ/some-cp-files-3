class CountIntervals {
public:
	map<int, int>m;
	int cnt;
	//  m made of l, r pairs
	CountIntervals() {
		m.clear();
		cnt = 0;
	}

	void add (int left, int right) {
		auto it = m.upper_bound (left);
		while (it != m.begin() and prev (it) -> second >= left)
			it = prev (it);
		int l = left, r = right, loss = 0;
		while (it != m.end() and it -> first <= right) {
			l = min (l, it -> first);
			r = max (r, it -> second);
			loss += it -> second - it -> first + 1;
			auto next_it = next (it);
			m.erase (it);
			it = next_it;
		}
		cnt += r - l + 1 - loss;
		m[l] = r;
	}

	int count() {
		return cnt;
	}
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
