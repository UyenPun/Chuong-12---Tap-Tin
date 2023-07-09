#include <iostream>
#include <fstream> // thư viện hỗ trợ tập tin
#include <string> // thư viện hỗ trợ chuỗi.
using namespace std;

int main()
{
	ifstream FileIn; // Khai báo tập tin để đọc.
	ofstream FileOut; // Khai báo tập tin để ghi.

	// Mở tập tin để đọc

	// open("INPUT.txt", "r");
	FileIn.open("INPUT.TXT", ios_base::in);

	// Kiểm tra tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin INPUT.TXT";
		system("pause");
		return 0;
	}



	// Xử lý tập tin.
	/* 
	int a;
	fscanf(FileIn, "%d", &a); // Bên C
	cin >> a; // từ bàn phím bên C++
	FileIn >> a; // từ file Bên C++

	fprintf(FileOut, "%d", a); // Bên C
	cout << a; // từ bàn phím xuất ra màn hình
	FileOut << a; // xuất ra file Bên C++

	Đọc chuỗi bên C
	char str[30];
	cách 1: fscanf(FileIn, "%s", &str);
	cách 2: fgets(str, 30, FileIn);

	giả sử str là: "Nguyen Viet Nam Son"
	cách 1: đọc vào sẽ đc chuỗi là "Nguyen"
	cách 2: đọc vào sẽ đc chuỗi là "Nguyen Viet Nam Son"

	Đọc chuỗi bên C++
	string str;
	cách 1: FileIn >> str;
	cách 2: getline(FileIn, str)

	giả sử str là: "Nguyen Viet Nam Son"
	cách 1: đọc vào sẽ đc chuỗi là "Nguyen"
	cách 2: đọc vào sẽ đc chuỗi là "Nguyen Viet Nam Son"

	*/

	string timkiem;
	cout << "\nBan muon tim kiem tu khoa nao: ";
	getline(cin , timkiem);

	int dem = 0;
	// Bên C: while(!feof(FileIn))
	while(!FileIn.eof()) // Vòng lặp đọc từ dòng đầu tới dòng cuối.
	{
		string str;
		//getline(FileIn, str); // đọc nguyên 1 dòng trong file và lưu vào biến str.
		FileIn >> str; // đọc từng từ.
		//cout << str << endl;
		if(str == timkiem)
		{
			dem++;
		}
	}

	// Bên C: fclose(FileIn)
	FileIn.close(); // Đóng file lại.

	// Mở tập tin để ghi
	FileOut.open("OUTPUT.TXT", ios_base::out);

	// ghi tập tin
	FileOut << timkiem << " => " << dem << " lan";

	// đóng tập tin lại.
	FileOut.close();

	system("pause");
	return 0;
}