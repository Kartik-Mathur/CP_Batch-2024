#include <iostream>
using namespace std;

class Person {
	string name;
	int salary;
	const int legs;
public:

	Person(string n, int s) : name(n), salary(s), legs(2) {
	}

	bool operator>(Person &p) {
		return salary > p.salary;
	}

};


int main() {

	Person abhishek("Abhishek", 5000000);
	Person aman("Aman", 50000000);

	if (aman > abhishek) {
		cout << "Aman ki salary jyada hai\n";
	}







	return 0;
}
















