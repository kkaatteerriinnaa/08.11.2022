#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <tchar.h>
#include <Windows.h>

using namespace std;

void TabSpace(_TCHAR* a)
{
	for (int i = 0; i < _tcslen(a); i++)
	{
		if (a[i] == ' ')
			a[i] = '\t';
	}
}

void Print(_TCHAR* a)
{
	for (int i = 0; i < _tcslen(a); i++)
	{
		wcout << a[i];
	}
	wcout << endl;
}

void SymbolsTypeCount(_TCHAR* a)
{
	int sym = 0, num = 0, ch = 0;
	for (int i = 0; i < _tcslen(a); i++)
	{
		if ((int)a[i] >= 48 && (int)a[i] <= 57)
			num++;
		else if ((int)a[i] >= 65 && (int)a[i] <= 90 || (int)a[i] >= 97 && (int)a[i] <= 122)
			ch++;
		else if ((int)a[i] >= 1040 && (int)a[i] <= 1103)
			ch++;
		else
			sym++;
	}
	cout << "\nSym: " << sym;
	cout << "\nNum: " << num;
	cout << "\nCh: " << ch;
}

void CountWord(_TCHAR* a)
{
	int words = 0;
	for (int i = 0; i < _tcslen(a); i++)
	{
		if ((int)a[i] == ' ' || (int)a[i] == '\t' || (int)a[i] == '\n')
		{
			words++;
			while (true)
			{
				if ((int)a[i + 1] == ' ' || (int)a[i + 1] == '\t' || (int)a[i + 1] == '\n')
					i++;
				else
					break;
			}
		}
	}
	words++;
	cout << "\nWords: " << words;
}

void MirrorCheck(_TCHAR* a)
{
	_TCHAR buf[255];
	_tcscpy(buf, a);
	bool mirror = false;
	int i = 0, j = _tcslen(a) - 1;
	while (true)
	{
		if (i > j)
			break;
		if (a[i] == buf[j])
			mirror = true;
		else
		{
			mirror = false;
			break;
		}
		i++;
		j--;
	}
	cout << "\nMirror: " << mirror;
}

void PosDelete(_TCHAR* a, int pos)
{
	_TCHAR buf[255];
	int i, j;
	pos--;
	for (i = j = 0; i < _tcslen(a); i++)
		if (pos != i)
			buf[j++] = a[i];
	buf[j] = '\0';
	_tcscpy(a, buf);
}

void ChDelete(_TCHAR* a, const char ch)
{
	_TCHAR buf[255];
	int i, j;
	for (i = j = 0; i < _tcslen(a); i++)
	{
		if (ch >= 0)
		{
			if ((int)a[i] != (int)ch)
				buf[j++] = a[i];
		}
		else
		{
			if ((int)a[i] != (int)ch + 1104)
				buf[j++] = a[i];
		}
	}
	buf[j] = '\0';
	_tcscpy(a, buf);
}

void PutChar(_TCHAR* a, int pos, char ch)
{
	_TCHAR buf[255];
	int i, j;
	pos--;
	for (i = j = 0; i < _tcslen(a); i++)
	{
		if (pos == i)
		{
			if (ch >= 0)
			{
				if ((int)a[i] == (int)ch)
					buf[j++] = ch;
			}
			else
			{
				if ((int)a[i] == (int)ch + 1104)
					buf[j++] = ch + 1104;
			}
		}
		else
			buf[j++] = a[i];
	}
	buf[++j] = '\0';
	_tcscpy(a, buf);
}

int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	_TCHAR arr[255] = _TEXT("òîïîò");
	Print(arr);
	TabSpace(arr);
	Print(arr);
	SymbolsTypeCount(arr);
	CountWord(arr);
	MirrorCheck(arr);
	PosDelete(arr, 5);
	cout << endl;
	Print(arr);
	ChDelete(arr, 'î');
	Print(arr);
	PutChar(arr, 3, 'ò');
	Print(arr);
}