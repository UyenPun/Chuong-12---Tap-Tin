#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> arr; // Khai báo mảng vector chứa kiểu số nguyên.

	// Cách 1:
	//int n = 5;
	//arr.resize(n); // cấp phát sẵn ra n ô

	//// gán phần tử
	//arr[0] = 1;
	//arr[1] = 2;
	//arr[2] = 3;
	//arr[3] = 4;
	//arr[4] = 5;

	// 1 2 3 4 5
	// Cách 2: push_back: Thêm vào đầu.
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	//arr.pop_back();

	// Thêm số 69 vào vị trí 3
	//arr.insert(arr.begin() + 3, 69);

	// Thêm 5 lần số 70 vào vị trí 3
	//arr.insert(arr.begin() + 3, 5, 70);

	//arr.erase(arr.begin() + 2); // xóa vị trí 2

	// xuất vector

	// lấy ra số lượng phần tử hiện tại vector đang chứa
	int sophantu = arr.size();

	for(int i = 0; i < sophantu; i++)
	{
		cout << arr[i] << "   ";
	}

	system("pause");
	return 0;
}