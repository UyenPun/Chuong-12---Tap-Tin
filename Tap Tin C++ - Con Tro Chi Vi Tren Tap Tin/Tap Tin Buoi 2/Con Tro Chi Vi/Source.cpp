/* 
Nguyen Viet Nam Son
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
	char str1[30], str2[30];
	fseek(FileIn, 7, SEEK_SET);

	fgets(str1, 5, FileIn); // Viet

	fseek(FileIn, -4, SEEK_END);
	fgets(str2, 30, FileIn); // Son

	fclose(FileIn);

	printf("%s\n%s", str1, str2);

	getch();
	return 0;
}