class Solution {
public:
	bool canReach (string s, int minJump, int maxJump) {
		vector <bool> isP (s.length());
		isP [0] = 1;
		int cn = 0;
		for (int i = 1; i < s.length(); i++) {
			if (i - maxJump - 1 >= 0 and isP[i - maxJump - 1])
				cn++;
			if (i - minJump >= 0 and isP[i - minJump])
				cn--;
			if (s[i] == '0' and cn)
				isP[i] = true;
		}
		return isP.back();
	}
};