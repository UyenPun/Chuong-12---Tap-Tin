#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void HoanVi(int &a, int &b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void SapXep(int *a, int n, char phanloai)
{
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

	int n; // số lượng phần tử.
	fscanf(FileIn, "%d", &n);

	// cấp phát bộ nhớ cho con trỏ.
	int *a = (int *)malloc(n * sizeof(int));

	// Duyệt hết mảng
	for(int i = 0; i < n; i++)
	{
		// Đọc vào mảng từng phần tử.
		fscanf(FileIn, "%d", &a[i]);
	}

	// B3: Đóng tập tin
	fclose(FileIn);

	// sắp xếp danh sách tăng dần.
	SapXep(a, n, 't');

	/* GHI DỮ LIỆU VÀO OUTPUT.TXT */

	// B1: Mở file
	FILE *FileOut;
	FileOut = fopen("OUTPUT.TXT", "w"); // tự động tạo mới nếu chưa có.


	// B2: Ghi file
	for(int i = 0; i < n; i++)
	{
		fprintf(FileOut, "%4d", a[i]);
	}

	// B3: Đóng file
	fclose(FileOut);

	free(a); // giải phóng con trỏ.

	getch();
	return 0;
}

