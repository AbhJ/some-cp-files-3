class Bitset {
public:
	string s;
	int cnt;
	bool f;
	Bitset (int size) {
		s = string (size, '0');
		f = 0;
		cnt = 0;
	}

	void fix (int idx) {
		if (s[idx] == '0' + (int)f) {
			s[idx] = '1' + '0' - s[idx];
			cnt++;
		}
	}

	void unfix (int idx) {
		if (s[idx] == '1' - (int)f) {
			s[idx] = '1' + '0' - s[idx];
			cnt--;
		}
	}

	void flip() {
		f ^= 1;
		cnt = s.length() - cnt;
	}

	bool all() {
		return cnt == s.length();
	}

	bool one() {
		return !!cnt;
	}

	int count() {
		return cnt;
	}

	string toString() {
		if (f == 1) {
			for (auto &c : s)
				c = '1' + '0' - c;
			f ^= 1;
		}
		return s;
	}
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
