#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the function below.
 */
#include <bits/stdc++.h>
using namespace std;

void superStack (vector<string> ops) {
	int n = ops.size();
	vector<long long> a (n), b (n);
	int k = 0;
	for (string op : ops) {
		stringstream strin (op);
		string optype;
		strin >> optype;
		if (optype == "push") {
			int x;
			strin >> x;
			a[k++] = x;
		}
		if (optype == "pop") {
			if (--k)
				b[k - 1] += b[k];
			b[k] = 0;
		}
		if (optype == "inc") {
			int x, y;
			strin >> x >> y;
			b[x - 1] += y;
		}
		if (not k)
			cout << "EMPTY";
		else
			cout << a[k - 1] + b[k - 1];
		cout << "\n";
	}
}
