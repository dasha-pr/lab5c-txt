#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <io.h>
#include <fcntl.h>
#include <sys\stat.h>
using namespace std;

struct Movie {
	string producer;
	string name;
	int realeaseYear;
	string country;
	int price;
	int income;
	int profit;
};

Movie first{ "Jerzy Hoffman","Battle of Warsaw",1920,"Warsaw",56677,200000,12345 };
Movie second{ "Jerzy Hoffman","An Ancient Tale",2003,"Warsaw",73450,856600,567900 };

void infoOut()
{
	cout << "Jerzy Hoffman's movies: " << endl;
	cout << "1)\nMovie: " << first.name << endl;;
	cout << "Producer name: " << first.producer << endl;
	cout << "Realese year: " << first.realeaseYear << endl;
	cout << "Country: " << first.country << endl;
	cout << "Price: " << first.price << endl;
	cout << "Income: " << first.income << endl;
	cout << "Profit: " << first.profit << endl;
	cout << "2)\nMovie: " <<second.name << endl;;
	cout << "Producer name: " << second.producer << endl;
	cout << "Realese year: " << second.realeaseYear << endl;
	cout << "Country: " << second.country << endl;
	cout << "Price: " << second.price << endl;
	cout << "Income: " << second.income << endl;
	cout << "Profit: " << second.profit << endl;

};


int filesDemo()
{

	setlocale(0, "ru");

	int trd = 0, twr = 0, fsize;
	const char* name1 = "C:\\MyFile.txt", * name2 = "C:\\MyCopy.txt";
	char msg[1024] = "";


	FILE* f_in, * f_out;
	char ch;

	if ((f_in = fopen(name1, "rb")) == NULL)
	{
		perror("Ошибка открытия для чтения файла №1");
		return 3;
	}
	else
	{
		if ((f_out = fopen(name2, "wb")) == NULL)
		{
			perror("Ошибка открытия для записи файла №3");
			return 4;
		}
		else
		{
			fsize = 0;
			while (!feof(f_in))
			{
				ch = fgetc(f_in);

				if (!feof(f_in))
				{
					fsize++;
					fputc(ch, f_out);
				}
			}

			fclose(f_out);

			printf_s("\n2)  Копирование содержимого файла MyFile.txt по 1 символу при помощи функции FOPEN в файл MyCopy.txt\n");
			printf_s("Всего записано:\t\t%10d Б\n\n", fsize);
		}
	}
}

int main()
{
	infoOut();
	cout << filesDemo();
	return 0;
}

