#include <iostream>
#include <time.h>
using namespace std;

void save() {
	FILE* fs = nullptr;
	if (fopen_s(&fs, "test.bin", "wb")) {
		cout << "The system cannot find the file specified \n";
		exit(2);
	}

	char name[] = "The system cannot find the file specified";
	// fwrite(name, strlen(name), 1, fs);
	fwrite(name, sizeof(*name), strlen(name) + 1, fs);
	int a = 3639; // &a=> int* implicit void*
	fwrite(&a, sizeof(a), 1, fs);
	double b = 123.99; // &a=> double* implicit void*
	fwrite(&b, sizeof(b), 1, fs);
	fclose(fs);
}
void save2() {
	FILE* fs = nullptr;
	if (fopen_s(&fs, "test.bin", "wb")) {
		cout << "The system cannot find the file specified \n";
		exit(2);
	}
	char name[] = "The system cannot find the file specified";
	int size = strlen(name) + 1;
	fwrite(&size, sizeof(size), 1, fs);

	fwrite(name, sizeof(*name), strlen(name) + 1, fs);
	int a = 3639; // &a=> int* implicit void*
	fwrite(&a, sizeof(a), 1, fs);
	double b = 123.99; // &a=> double* implicit void*
	fwrite(&b, sizeof(b), 1, fs);
	fclose(fs);
}
void Load() {
	FILE* fs = nullptr;
	if (fopen_s(&fs, "test.bin", "rb")) {
		cout << "The system cannot find the file specified \n";
		exit(2);
	}
	//char name[10]{0};
	//char name[10];
	/*   fread(name, sizeof(*name), 5, fs);
	   name[5]='\0';*/
	   /*int i = 0;
	   char name[10];
	   do {
		   fread(name + i, sizeof(*name), 1, fs);
	   } while (*(name + i++));*/

	int sizeText = 0;
	char t;
	do {
		fread(&t, sizeof(t), 1, fs);
		sizeText++;
	} while (t);
	fseek(fs, -sizeText, SEEK_CUR);


	char* name = new char[sizeText];
	fread(name, sizeof(char), sizeText, fs);

	int a; // &a=> int* implicit void*
	fread(&a, sizeof(a), 1, fs);
	double b;// &a=> double* implicit void*
	fread(&b, sizeof(b), 1, fs);
	fclose(fs);

	cout << name << endl << a << endl << b << endl;

	delete[] name;
}
void Load2() {
	FILE* fs = nullptr;
	if (fopen_s(&fs, "test.bin", "rb")) {
		cout << "The system cannot find the file specified \n";
		exit(2);
	}
	int sizeText = 0;
	fread(&sizeText, sizeof(sizeText), 1, fs);

	char* name = new char[sizeText];
	fread(name, sizeof(char), sizeText, fs);

	int a; // &a=> int* implicit void*
	fread(&a, sizeof(a), 1, fs);
	double b;// &a=> double* implicit void*
	fread(&b, sizeof(b), 1, fs);
	fclose(fs);

	cout << name << endl << a << endl << b << endl;

	delete[] name;
}
void SaveInt()
{
	int n = 5 + rand() % 10;
	int temp = 0;
	FILE* fs = NULL;
	if (fopen_s(&fs, "rnd.bin", "wb"))
	{
		cout << "Error create file";
		exit(2);
	}
	for (size_t i = 0; i < n; i++)
	{
		temp = rand() % 10;
		fwrite(&temp, sizeof(int), 1, fs);
	}
	fclose(fs);
}
void PrintINT()
{
	FILE* fs = NULL;
	int temp = 0;
	if (fopen_s(&fs, "rnd.bin", "rb"))
	{
		cout << "Error create file";
		exit(2);
	}
	fread(&temp, sizeof(int), 1, fs);
	while (!feof(fs))
	{
		cout << temp << '\t';
		fread(&temp, sizeof(int), 1, fs);
	}
	fclose(fs);
}

void PrintINT2()
{
	FILE* fs = NULL;
	int temp = 0;
	if (fopen_s(&fs, "rnd.bin", "rb"))
	{
		cout << "Error create file";
		exit(2);
	}
	//cout << ftell(fs) << endl;
	fseek(fs, 0, SEEK_END);
	//fread(&temp, sizeof(int), 1, fs);
	//cout << ftell(fs) << endl;
	int n = ftell(fs) / sizeof(int);
	fseek(fs, 0, SEEK_SET);
	for (size_t i = 0; i < n; i++)
	{
		fread(&temp, sizeof(int), 1, fs);
		cout << temp << '\t';
	}
	fclose(fs);
}

// 3 на -10
void Replace(int k = -10)
{
	FILE* fs = NULL;
	if (fopen_s(&fs, "rnd.bin", "r+b"))
	{
		cout << "Error create file";
		exit(2);
	}
	fseek(fs, 3 * sizeof(int), SEEK_SET);
	fwrite(&k, sizeof(int), 1, fs);
	fclose(fs);
}

int main()
{
	srand(time(0));
	/*save();
	Load();*/

	//save2();
	//Load2();

	SaveInt();
	//PrintINT();
	PrintINT2();
	cout << "\n---------------------------\n";
	Replace();
	PrintINT2();

	cout << "The end!\n";

	// зАПИСАТИ У фАЙЛ N випадкових чисел
	// Вивести всі числа на екран
	// Порахувати суму чисел
	//	МАСИВИ НЕ ВИКОРИСТОВУВАТИ



}