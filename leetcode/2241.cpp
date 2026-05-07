class ATM {
public:
	vector <int> den {
		20, 50, 100, 200, 500
	};
	vector <int> cnt;
	ATM() {
		cnt = vector <int> (5);
	}

	void deposit (vector<int> banknotesCount) {
		for (int i = 0; i < 5; i++) {
			cnt[i] += banknotesCount[i];
		}
	}

	vector<int> withdraw (int amount) {
		vector <int> formulate (5);
		for (int i = 4; ~i; i--) {
			int cnt1 = min (cnt[i], amount / den[i]);
			formulate[i] += cnt1;
			amount -= cnt1 * den[i];
		}
		if (amount)
			return vector <int> {- 1};
		for (int i = 0; i < 5; i++) {
			cnt[i] -= formulate[i];
		}
		return formulate;
	}
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */