class Solution {
public:
	vector<vector<string>> mostPopularCreator(vector<string>& creator, vector<string>& ids, vector<int>& views) {
		int n = creator.size();
		map<string, int> best_id, sum;
		int best_creator = 0, max_sum = - 1;
		for(int i = 0; i < n; i++){
			if(best_id.count(creator[i]) == 0 or views[i] > views[best_id[creator[i]]] or (views[i] == views[best_id[creator[i]]]) and ids[best_id[creator[i]]] > ids[i])
				best_id[creator[i]] = i;
			sum[creator[i]] += views[i];
			if(sum[creator[i]] > max_sum)
				best_creator = i,  max_sum = sum[creator[i]];
		}
		set<string>s;
		for(int i = 0; i < n; i++){
			if(max_sum == sum[creator[i]])
				s.emplace(creator[i]);
		}
		vector<vector<string>> ans;
		for(auto S: s){
			ans.emplace_back(vector<string>{S, ids[best_id[S]]});
		}
		return ans;
	}
};