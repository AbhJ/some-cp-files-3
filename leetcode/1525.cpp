class Solution {
public:
	int numSplits (string s) {
		int cnt = 0;
		map <char, int> lef, rig;
		for (auto c : s)
			rig[c]++;
		for (auto c : s) {
			lef[c]++;
			rig[c]--;
			if (rig[c] == 0)
				rig.erase (c);
			if (lef.size() == rig.size())
				cnt++;
		}
		return cnt;
	}
};