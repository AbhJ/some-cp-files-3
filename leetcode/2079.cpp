class Solution {
public:
	int wateringPlants (vector<int> &plants, int capacity) {
		int count = 0, cur = capacity;
		for (int i = 0; i < plants.size(); i++) {
			if (cur < plants[i])
				cur = capacity - plants[i], count += (i << 1);
			else
				cur -= plants[i];
			count++;
		}
		return count;
	}
};
