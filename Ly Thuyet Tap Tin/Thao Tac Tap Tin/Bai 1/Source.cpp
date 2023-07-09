#include <stdio.h>
#include <conio.h>

int main()
{
	// B1: Mở file

	FILE *FileIn; // Khai báo con trỏ File.

	// Cho con trỏ trở tới vùng nhớ chứa file INPUT.TXT
	FileIn = fopen("INPUT.TXT", "r");
	
	// Kiểm tra xem tập tin có tồn tại hay không ?
	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT ! Xin kiem tra lai !");
		getch();
		return 0;
	}

	// B2: Đọc dữ liệu từ tập tin vào chương trình.

	// đọc dữ liệu từ tập tin vào chương trình <=> nhập dữ liệu từ bàn phím vào chương trình.
	// ghi dữ liệu từ chương trình ra tập tin <=> xuất dữ liệu ra màn hình.

	int a, b;

	// đọc dữ liệu vào chương trình.
	fscanf(FileIn, "%d%d", &a, &b);

	// B3: Đóng tập tin
	fclose(FileIn);

	// printf("\na = %d & b = %d", a, b);

	// Tìm Max
	int Max = a > b ? a : b;

	/* GHI DỮ LIỆU VÀO OUTPUT.TXT */

	// B1: Mở file
	FILE *FileOut;
	FileOut = fopen("OUTPUT.TXT", "w"); // tự động tạo mới nếu chưa có.


	// B2: Ghi file
	fprintf(FileOut, "\nMax = %d", Max);

	// B3: Đóng file
	fclose(FileOut);

	getch();
	return 0;
}

