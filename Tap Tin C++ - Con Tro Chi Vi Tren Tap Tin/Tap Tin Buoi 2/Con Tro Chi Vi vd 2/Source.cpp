/* 
31/10/1994
*/

#include <stdio.h>
#include <conio.h>


int main()
{
	FILE *FileIn = fopen("INPUT.TXT", "r");

	if(!FileIn)
	{
		printf("\nKhong tim thay tap tin INPUT.TXT");
		getch();
		return 0;
	}

	// xử lý
	int ngay, thang, nam;

	fscanf(FileIn, "%d", &ngay);

	fseek(FileIn, 1, SEEK_CUR); // bỏ qua dấu '/' đầu tiên

	fscanf(FileIn, "%d", &thang);

	fseek(FileIn, 1, SEEK_CUR); // bỏ qua dấu '/' đầu tiên

	fscanf(FileIn, "%d", &nam);

	fclose(FileIn);

	printf("\nSinh ngay %d thang %d nam %d", ngay, thang, nam);

	getch();
	return 0;
}