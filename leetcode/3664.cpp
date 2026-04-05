class Solution {
public:
	int score (vector<string>& cards, char x) {
		int cnt1 = 0, cnt2 = 0, cnt3 = 0, f1 = 0, f2 = 0, ans = 0;
		map <char, int> m1, m2;
		for (auto card : cards) {
			if (card[0] == x and card [1] != x) {
				m1[card[1]]++;
				f1 = max (m1[card[1]], f1);
				cnt1++;
			}
			if (card[1] == x and card [0] != x) {
				m2[card[0]]++;
				f2 = max (m2[card[0]], f2);
				cnt2++;
			}
			if (card[0] == x and card [1] == x)
				cnt3++;
		}
		if (f1 > cnt1 - f1) {
			ans += cnt1 - f1;
			cnt1 = f1 - (cnt1 - f1);
		}
		else {
			ans += cnt1 / 2;
			cnt1 %= 2;
		}
		if (f2 > cnt2 - f2) {
			ans += cnt2 - f2;
			cnt2 = f2 - (cnt2 - f2);
		}
		else {
			ans += cnt2 / 2;
			cnt2 %= 2;
		}
		int pairsWithDoub = min (cnt1 + cnt2, cnt3);
		cnt3 -= pairsWithDoub;
		ans += pairsWithDoub + min (ans, cnt3 / 2);
		// int y = min ((cnt1 % 2) + (cnt2 % 2), cnt3);
		// cnt3 -= y;
		// // cnt3 / 2 needs to be discarded because of requirement in last line
		// return (cnt1 / 2) + (cnt2 / 2) + y;
		return ans;
	}
};