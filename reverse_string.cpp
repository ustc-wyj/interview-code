#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool checkChar(char a)
{
	if (((a <= 'z') && (a >= 'a')) || ((a <= 'Z') && (a >= 'A')) || ((a <= '9') && (a >= '0')))
	{
		return true;
	}
	else {
		return false;
	}
}

string fun(string str) {
	if (str.size() <= 1)
		return str;
	string str1;
	for (int i = 0; i < str.size(); i++) {
		if (checkChar(str[i])) {
			str1 += str[i];
		}
		else {
			if ((i > 0) && (i < str.size() - 1)) {
				if ((str[i] == '-') && (checkChar(str[i - 1])) && (checkChar(str[i + 1])))
				{
					str1 += '-';
				}
			}
			if ((i > 0) && (checkChar(str[i - 1]))) {
				while ((!checkChar(str[i])) && (i < str.size())) {
					i++;
				}
				if (checkChar(str[i]))
				{
					str1 += ' ';
					str1 += str[i];
				}
			}
			if (i == 0) {
				while ((!checkChar(str[i])) && (i < str.size())) {
					i++;
				}
				if (checkChar(str[i]))
				{
					str1 += str[i];
				}

			}

		}
	}
	reverse(str1.begin(), str1.end());
	auto iter1 = str1.begin();
	auto iter2 = str1.begin();
	while ((iter1 != str1.end()) && ((iter2 != str1.end())))
	{
		if (*iter2 == ' ')
		{
			reverse(iter1, iter2);
			iter2++;
			iter1 = iter2;
		}
		else
			iter2++;
	}
	if (iter2 == str1.end())
	{
		reverse(iter1, iter2);
	}
	return str1;
}

int main()
{
	string str;
	char a;
	
	str = "123   456";
	string str1 = fun(str);
	cout << str1 << endl;
	return 0;
}