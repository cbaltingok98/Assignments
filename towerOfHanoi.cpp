#include <iostream>

using namespace std;

void move(int count, int n1, int n3, int n2) {
	if (count > 0) {
		move(count - 1, n1, n2, n3);
		cout << "Move Disk " << count << " from " << n1 << " to " << n3 << "." << endl;
		move(count - 1, n2, n3, n1);
	}

}

int main() {
	int num;
	cout << "Enter the number of Disks >> ";
	cin >> num;
	cout << endl;
	move(num, 1, 3, 2);

	return 0;
}