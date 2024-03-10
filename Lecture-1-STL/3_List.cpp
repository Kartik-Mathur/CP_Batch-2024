#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

int main() {

	forward_list<int> l;

	forward_list<int>::iterator it;

	l.push_front(0);
	l.push_front(1);
	l.push_front(2);
	l.push_front(3);
	l.push_front(4);

	for (it = l.begin(); it != l.end(); ++it)
	{
		if (*it == 3) {
			break;
		}
	}
	l.insert_after(it, 10);
	it = l.begin();
	while (it != l.end()) {

		cout << *it << "-->";
		it++;
	}

	// for (auto d : l) {
	// 	cout << d << " ";
	// }
	// cout << endl;


	return 0;
}
















