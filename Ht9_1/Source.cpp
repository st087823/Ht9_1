#include<iostream>
#include<string>
#include<clocale>
#include <iomanip>
#include <cmath>
using namespace std;

void resolveError(int errorCode) 
{
	string Code1[2] = { "Встретился неопознанный символ", "Странный символ, ожидалось число (например: 56780 или 54387.098)" };
	string Code2[2] = { "Число не соответсвует требованиям программы", "Число не входит в дозволенный диапозон" };
	if (errorCode == 1)
	{
		cout << Code1[rand() % 2 + 1] << endl;
	}
	else
	{
		cout << Code2[rand() % 2 + 1] << endl;
	}
}

void trim(string& str)
{
	int startIndex = 0;
	while (str[startIndex] == ' ') 
	{
		startIndex++;
	}
	str = str.substr(startIndex);
}

bool isDigit(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

int readDouble(double& number, string& str)
{
	double number = 0;
	int signum = 1;
	if (str[0] == '-')
	{
		str = str.substr(1);
		signum = -1;
	}
	while (isDigit(str[0]))
	{
		number = 10 * number + str[0] - '0';
		str = str.substr(1);
	}
	if (str[0] != '.' && !empty(str))
	{
		number = 0;
		return 1;
	}
	if (str[0] == '.')
	{
		str = str.substr(1);
		double remain = 0;
		while (isDigit(str[0]))
		{
			remain = 10 * remain + str[0] - '0';
			str = str.substr(1);
		}
		if (!empty(str))
		{
			number = 0;
			return 1;
		}
		while (remain > 1)
		{
			remain /= 10;
		}
		number += remain;
	}
	number *= signum;
	return 0;
}

int readInt(long long& number, string& str)
{
	number = 0;
	int signum = 1;
	int j = 0;
	if (str[0] == '-')
	{
		str = str.substr(1);
		signum = -1;
		j = 1;
	}

	string size = "9223372036854775807";
	if (str.size() == 19)
	{
		for (int i = j; size[i] != '\0'; i++) 
		{
			if (str[i] > size[i])
				return 2;
		}
	}

	while (isDigit(str[0]))
	{
		number = 10 * number + str[0] - '0';
		str = str.substr(1);
	}

	if (str[0] == ' ')
	{
		number *= signum;
		return 0;
	}

	number = 0;
	return 1;
}


int main()
{
	//setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	
	string str;
	long long numb1;
	double numb2;
	int er1 = -1;
	int er2 = -1;

	while (er1 != 0 && er2 != 0)
	{
		string str;
		getline(cin, str);
		trim(str);

		if (str.size() > 20)
		{
			numb1 = 0;
			numb2 = 0;
			return 2;
		}

		er1 = readInt(numb1, str);
		er2 = readDouble(numb2, str);

		resolveError(er1);
		resolveError(er2);
	}

	cout << "number1 + number2 = " << numb1 + numb2 << endl;
	return 0;
}
