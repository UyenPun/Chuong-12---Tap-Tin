#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

float TinhDiemTrungBinh(float toan, float ly, float hoa)
{
	return (toan + ly + hoa) / 3;
}

char* XepLoai(float Dtb)
{
	// 0 --> <2: Kém
	// 2 --> <5: Yếu
	// 5 --> <7: Trung Bình
	// 7 --> <8: Khá
	// 8 --> <9: Giỏi
	// 9 --> 10: Xuất Sắc

	if(Dtb < 2)
	{
		return "Kem";
	}

	if(Dtb < 5)
	{
		return "Yeu";
	}

	if(Dtb < 7)
	{
		return "Trung Binh";
	}

	if(Dtb < 8)
	{
		return "Kha";
	}

	if(Dtb < 9)
	{
		return "Gioi";
	}
	return "Xuat Sac";
}

// Mở con trỏ thông qua 1 hàm thì con trỏ đó phải truyền vào dạng tham chiếu.
void MoFile(FILE *&FileIn)
{
	FileIn = fopen("INPUT.TXT", "r");

	// Kiểm tra xem file co ton tai hay khong ?
	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin.");
		getch();
		exit(0); // kết thúc toàn bộ chương trình.
	}
}

int main()
{
	// Mở file INPUT.TXT và đọc dữ liệu

	// B1: Mở file
	FILE *FileIn;

	MoFile(FileIn);

	// B2: Đọc file
	char ten[30];
	float toan, ly, hoa;

	fgets(ten, 30, FileIn);
	fscanf(FileIn, "%f%f%f", &toan, &ly, &hoa);

	// B3: Đóng file
	fclose(FileIn);

	/*printf("\nTen: %s", ten);
	
	printf("\nToan = %f", toan);
	printf("\nLy = %f", ly);
	printf("\nHoa = %f", hoa);*/

	FILE* FileOut = fopen("OUTPUT.TXT", "w");

	fprintf(FileIn, "%s", ten);
	float Dtb = TinhDiemTrungBinh(toan, ly, hoa);
	char xeploai[30];
	strcpy(xeploai, XepLoai(Dtb));

	fprintf(FileOut, "\nDtb = %f", Dtb);
	fprintf(FileOut, "\nXep loai: %s", xeploai);


	// đóng file lai.
	fclose(FileOut);

	getch();
	return 0;
}