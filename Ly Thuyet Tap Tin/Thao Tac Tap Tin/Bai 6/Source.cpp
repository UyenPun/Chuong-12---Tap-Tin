#include <iostream>
#include <fstream> // thư viện hỗ trợ file của C++
#include <vector>
using namespace std;

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void SapXep(vector<int> &a, char phanloai)
{
	int n = a.size();
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(phanloai == 't')
			{
				if(a[i] > a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
			else if(phanloai == 'g')
			{
				if(a[i] < a[j])
				{
					HoanVi(a[i], a[j]);
				}
			}
		}
	}
}

void DocFile(ifstream &FileIn)
{
	FileIn.open("INPUT.TXT", ios_base::in);
	
	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT ! Xin kiem tra lai !";
		system("pause");
		exit(0);
	}
}

int main()
{
	// B1: Mở file

	ifstream FileIn; // Khai báo file.
	DocFile(FileIn);
	

	// B2: Đọc dữ liệu từ tập tin vào chương trình.

	// đọc dữ liệu từ tập tin vào chương trình <=> nhập dữ liệu từ bàn phím vào chương trình.
	// ghi dữ liệu từ chương trình ra tập tin <=> xuất dữ liệu ra màn hình.

	vector<int> arr;

	while(!FileIn.eof())
	{
		int Number;
		FileIn >> Number; // Đọc dữ liệu từ file vào Number

		arr.push_back(Number); // Thêm Number vào vector.
	}

	// B3: Đóng tập tin
	FileIn.close();

	// sắp xếp danh sách tăng dần.
	SapXep(arr, 't');

	/* GHI DỮ LIỆU VÀO OUTPUT.TXT */

	// B1: Mở file
	ofstream FileOut;

	FileOut.open("OUTPUT.TXT", ios_base::out);


	// B2: Ghi file
	int n = arr.size();
	for(int i = 0; i < n; i++)
	{
		FileOut << arr[i] << "   ";
	}

	// B3: Đóng file
	FileOut.close();

	system("pause");
	return 0;
}

