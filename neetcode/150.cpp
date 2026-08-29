/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }w
 * }
 */

class Solution {
public:
	int minMeetingRooms (vector<Interval>& intervals) {
		int j = 0, rooms = 0;
		vector <int> s, e;
		for (auto i : intervals) {
			s.emplace_back (i.start);
			e.emplace_back (i.end);
		}
		sort (s.begin(), s.end());
		sort (e.begin(), e.end());
		for (auto i : s) {
			if (i < e[j])
				rooms++;
			else
				j++;
		}
		return rooms;
	}
};
