#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Activity {
public:
	int start;
	int end;
};

vector<Activity > activities;

bool compare(Activity a, Activity b) {
	return a.end < b.end;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;

		for (int i = 0; i < n; ++i)
		{
			int start, end; cin >> start >> end;
			activities.push_back({start, end});
		}

		sort(activities.begin(), activities.end(), compare);

		int totalCnt = 1;
		int currentEnd = activities[0].end;
		for (int i = 1; i < n; ++i)
		{
			if (currentEnd <= activities[i].start) {
				totalCnt ++;
				currentEnd = activities[i].end;
			}
		}

		cout << totalCnt << endl;

		activities.clear();
	}

	return 0;
}
















