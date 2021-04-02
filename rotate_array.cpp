#include"rotate_array.h"

RotateArray::RotateArray(){}

RotateArray::~RotateArray(){}

RotateArray::RotateArray(string file_name, int num) {
	this->num = num;
	ifstream file;
	file.open(file_name, ios::binary);
	this->file_name = file_name;
	if (!file) {
		cout << "Fail to open file!" << endl;
		getchar();
		exit(0);
	}
	int size;
	file.seekg(0, ios::end);
	size = file.tellg();
	if (size > 2 * 1024 * 1024 * 8) {
		cout << "File over size limet(2MB)." << endl;
		getchar();
		exit(0);
	}
	file.seekg(0, ios::beg);
	int data;
	char* buffer = new char[4];
	while (!file.eof()){
		file.read(buffer, 4);
		data = *(int*)buffer;
		arr.push_back(data);
	}
	arr.pop_back();
	file.close();
	this->Rotate(num);
}

void RotateArray::Rotate(int num) {
	if (num <= 0) {
		printf("Illegal input.");
		return;
	}
	if (arr.size() < 2)   return;
	int n = arr.size();
	num %= n;
	for (int i = 0; i < num; i++) {
		int temp = arr[n - 1];
		for (int j = n - 1; j > 0; j--) {
			arr[j] = arr[j - 1];
		}
		arr[0] = temp;
	}
	ofstream file(this->file_name, ios::binary);
	file.seekp(0, ios::beg);
	char* data = new char[4];
	for (int i = 0; i < arr.size(); ++i) {
		data = (char*)&arr[i];
		file.write(data, 4);
	}
	file.close();
	cout << "Rotate complited." << endl;
}