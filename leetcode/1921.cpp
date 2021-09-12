class Solution {
public:
	int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
		for (int i = 0; i < (int)dist.size(); i++)
			dist[i] = (dist[i] + speed[i] - 1) / speed[i];
		sort(dist.begin(), dist.end());
		for (int i = 0; i < (int)dist.size(); i++)
			if (dist[i] < i + 1)
				return i;
		return (int)dist.size();
	}
};