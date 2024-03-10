#include <iostream>
#include <queue>
#include <functional>
using namespace std;

class Pair {
public:
	string name;
	int salary;

	Pair(string name, int salary) {
		this->name = name;
		this->salary = salary;
	}
};

class myClass {
public:
	bool operator()(Pair a, Pair b) {
		return a.salary < b.salary;
	}
};

int main() {

	// priority_queue<int, vector<int>, greater<int> > q;
	// priority_queue<int, vector<int>, less<int> > q;
	// priority_queue<int, vector<int>, less<int> > q;
	priority_queue<Pair, vector<Pair>, myClass > q;

	// q.push(1);
	// q.push(2);
	// q.push(3);
	// q.push(4);


	q.push({"Abhishek", 100});
	q.push({"Aman", 200});
	q.push({"Nikhil", 150});

	while (!q.empty()) {
		cout << q.top().name << ", " << q.top().salary << endl;
		q.pop();
	}
	cout << endl;


	return 0;
}
















