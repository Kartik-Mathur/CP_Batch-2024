#include <iostream>
#include <vector>
using namespace std;

int DONE;
int ans = 0;
vector<int> board;

void nQueen(int rowMask, int ld, int rd) {
	if (rowMask == DONE) {
		ans ++;

		for (auto e : board) {
			int temp = DONE;
			while (temp) {
				(e & 1) ? cout << "Q " : cout << "_ ";
				e = e >> 1;
				temp = temp >> 1;
			}
			cout << endl;
		}
		cout << endl;

		return;
	}

	int safeMask = DONE & (~(rowMask | ld | rd));

	while (safeMask) {
		int p = safeMask & (-safeMask);
		safeMask -= p;
		board.push_back(p);
		nQueen(rowMask | p, (ld | p) << 1, (rd | p) >> 1);
		board.pop_back();
	}
}

int main() {

	// int n; cin >> n;
	int n = 4;
	// If n is 4
	// DONE in binary: 1 1 1 1, representing har row mei ek queen place krni hai
	DONE = (1 << n) - 1;

	nQueen(0, 0, 0);
	cout << ans;



	return 0;
}
















