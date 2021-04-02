#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class RotateArray {
public:
	RotateArray();
	RotateArray(string, int);
	~RotateArray();

private:
	vector<int> arr;
	string file_name;
	int num;  // number of rotate

	void Rotate(int);
};