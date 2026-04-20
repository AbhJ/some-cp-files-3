class Solution {
public:
	int countVowelPermutation (int n) {
		int a = 1, e = 1, i = 1, o = 1, u = 1;
		int a_next, e_next, i_next, o_next, u_next;
		for (int j = 1; j < n; j++) {
			a_next = e;
			e_next = (a + i) % (int) (1e9 + 7);
			i_next = ((a + e) % (int) (1e9 + 7) + (o + u) % (int) (1e9 + 7)) % (int) (
			             1e9 + 7);
			o_next = (i + u) % (int) (1e9 + 7);
			u_next = a;
			a = a_next, e = e_next, i = i_next, o = o_next, u = u_next;
		}
		return ((a + e) % (int) (1e9 + 7) + ((i + o) % (int) (1e9 + 7) + u) % (int) (
		            1e9 + 7)) % (int) (1e9 + 7);
	}
};