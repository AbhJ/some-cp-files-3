class Solution {
public:
	int cost (int mins, int secs, int startAt, int moveCost, int pushCost, int targetSeconds) {
		int ans = 0;
		if (mins < 0 or secs < 0 or mins >= 100 or secs >= 100)
			return 1e9;
		string s = to_string (mins * 100 + secs);
		s = string (1, (startAt + '0')) + s;
		for (int i = 1; i < s.length(); i++)
			ans += (s[i] != s[i - 1]) * moveCost + pushCost;
		return ans;
	}

	int minCostSetTime (int startAt, int moveCost, int pushCost, int targetSeconds) {
		int mins = targetSeconds / 60, secs = targetSeconds % 60;
		return min (cost (mins, secs, startAt, moveCost, pushCost, targetSeconds), cost (mins - 1, secs + 60, startAt, moveCost, pushCost, targetSeconds));
	}
};
