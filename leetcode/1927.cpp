class Solution {
public:
	bool sumGame(string num) {
		int lef = 0, rig = 0, n = num.length(), ques = 0, lefq = 0, rigq = 0, su, suq;
		for (int i = 0; i < n; i++) {
			if (num[i] != '?') {
				if ((i << 1) < n)
					lef += num[i] - '0';
				else
					rig += num[i] - '0';
			} else {
				if ((i << 1) < n)
					lefq++;
				else
					rigq++;
			}
		}
		su = rig - lef;
		suq = rigq - lefq;
		if (suq & 1)
			return true;
		return (su + ((suq >> 1) * 9) != 0);
	}
};