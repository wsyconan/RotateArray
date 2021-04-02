#include"rotate_array.h"

int main() {
	string path;
	int num;
	cout << "Please enter the file path" << endl;
	cin >> path;
	while (true) {
		cin.clear();
		cin.ignore();
		cout << "Please enter the number of rotate" << endl;
		cin >> num;
		if (!cin.fail()) {
			break;
		}
	}
	RotateArray arr(path, num);
}