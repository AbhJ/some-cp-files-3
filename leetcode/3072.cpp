// PBDS Headers
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Namespace for PBDS
using namespace __gnu_pbds;

// Defining the Order Statistic Tree
// template <Key, Mapped (use null_type for set), Comparator, Backend, Policy>
typedef tree <
int,
null_type,
std::greater_equal<int>,
rb_tree_tag,
tree_order_statistics_node_update
> ordered_set;

class Solution {
public:

	vector<int> resultArray (vector<int>& nums) {
		ordered_set a, b;
		vector <int> l, r;
		for (auto i : nums) {
			int n1 = a.order_of_key (i), n2 = b.order_of_key (i);
			if (l.empty() and r.empty()) {
				a.insert (i);
				l.emplace_back (i);
			}
			else if (!l.empty() and r.empty()) {
				b.insert (i);
				r.emplace_back (i);
			}
			else if (n1 > n2) {
				a.insert (i);
				l.emplace_back (i);
			}
			else if (n1 < n2) {
				b.insert (i);
				r.emplace_back (i);
			}
			else if (l.size() < r.size()) {
				a.insert (i);
				l.emplace_back (i);
			}
			else if (l.size() > r.size()) {
				b.insert (i);
				r.emplace_back (i);
			}
			else {
				a.insert (i);
				l.emplace_back (i);
			}
		}
		l.insert (l.end(), r.begin(), r.end());
		return l;
	}
};