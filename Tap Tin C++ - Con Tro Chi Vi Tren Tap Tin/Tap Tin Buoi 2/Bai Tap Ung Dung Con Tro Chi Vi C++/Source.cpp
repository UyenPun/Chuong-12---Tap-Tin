/* 
Nguyen Viet Nam Son - 31/10/1994 - 7.5 - 8.5 - 9
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream FileIn("INPUT.TXT");

	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		return 0;
	}

	// xử lý
	string Ten;
	int ngay, thang, nam;
	float toan, ly, hoa;

	// Đọc tới ký tự '-' đứng lại.
	getline(FileIn, Ten, '-');

	// Xóa khoảng trắng cuối cùng.
	Ten.erase(Ten.begin() + Ten.length() - 1);
	
	
	FileIn >> ngay;

	FileIn.seekg(1, SEEK_CUR); // bỏ dấu '/'

	FileIn >> thang;

	FileIn.seekg(1, SEEK_CUR); // bỏ dấu '/'

	FileIn >> nam;

	FileIn.seekg(2, SEEK_CUR);

	FileIn >> toan;

	FileIn.seekg(2, SEEK_CUR);

	FileIn >> ly;

	FileIn.seekg(2, SEEK_CUR);

	FileIn >> hoa;
	
	FileIn.close(); // Đóng tập tin lại

	cout << "\nTen: " << Ten;
	cout << "\nSinh ngay " << ngay << " thang " << thang << " nam " << nam; 
	cout << "\nToan = " << toan;
	cout << "\nLy = " << ly;
	cout << "\nHoa = " << hoa;

	system("pause");
	return 0;
}