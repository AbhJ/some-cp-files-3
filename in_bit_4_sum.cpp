vector<vector<int> > Solution::fourSum (vector<int> &A, int B) {
	vector<vector<int>>ans;
	sort (A.begin(), A.end());
	//O(n*n*n) solution
	// set<vector<int>>s;set<long long>S;
	// for(int i=0;i!=A.size();i++){
	//     for(int j=i+1;j!=A.size();j++)
	//         for(int k=j+1;k!=A.size();k++){
	//             long long cur=A[i];cur+=A[j];cur+=A[k];
	//             vector<int> tmp{A[i],A[j],A[k],(long long)B-cur};
	//             sort(tmp.begin(),tmp.end());
	//             if(S.count((long long)B-cur))s.insert(tmp);
	//         }
	//     S.insert(A[i]);
	// }
	// for(auto i:s){
	//     ans.push_back(i);
	// }
	// sort(ans.begin(),ans.end());
	// return ans;
	set<vector<int>>s;
	for (int i = 0; i != A.size(); i++)
		for (int j = i + 1; j != A.size(); j++) {
			int l = j + 1, r = A.size() - 1;
			while (l < r) {
				long long sum = A[i];
				sum += A[j];
				sum += A[l];
				sum += A[r];
				if (sum == B)
					s.insert (vector<int> {A[i], A[j], A[l], A[r]});
				if (sum > B)
					r--;
				else
					l++;
			}
		}
	for (auto i : s)
		ans.push_back (i);
	return ans;
}
