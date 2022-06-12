class Solution {
public:
	bool checkValidString (string s) {
		int cnt_min = 0, cnt_max = 0;
		for (char i : s) {
			if (i == '(') {
				cnt_min++;
				cnt_max++;
			}
			if (i == ')') {
				cnt_min--;
				cnt_max--;
			}
			if (i == '*') {
				cnt_min--;
				cnt_max++;
			}
			if (cnt_max < 0)
				return false;
			cnt_min = max (cnt_min, 0);
		}
		return cnt_min == 0;
	}
};
