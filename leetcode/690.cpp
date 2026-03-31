/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
	map <int, Employee*> m;
	int dfs (Employee* u) {
		if (u == NULL)
			return 0;
		int ans = 0;
		for (auto i : u -> subordinates) {
			ans += dfs (m[i]);
		}
		return u -> importance + ans;
	}
	int getImportance (vector<Employee*> employees, int id) {
		for (Employee * e : employees) {
			m[e -> id] = e;
		}
		return dfs (m[id]);
	}
};