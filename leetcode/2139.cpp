class Solution {
public:
	int minMoves (int target, int maxDoubles) {
		int step = 0;
		while (1 < target and maxDoubles--) {
			step++;
			step += target & 1;
			target >>= 1;
		}
		return target + step - 1;
	}
};
