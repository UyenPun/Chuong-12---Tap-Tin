/* 
31/10/1994
*/

#include <iostream>
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
	int ngay, thang, nam;

	FileIn >> ngay;

	FileIn.seekg(1, SEEK_CUR); // bỏ qua dấu '/' đầu tiên

	FileIn >> thang;
	
	FileIn.seekg(1, SEEK_CUR); // bỏ qua dấu '/' đầu tiên

	FileIn >> nam;

	FileIn.close();

	cout << "Sinh ngay " << ngay << " thang " << thang << " nam " << nam;
		 
	system("pause");
	return 0;
}