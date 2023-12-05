#include <iostream>
using namespace std;

const int SIZE = 30;
const int LENGTH = 31;

// функция, реализующая шифроку и расшифровку
unsigned long long encryptionAndDecipher(int a, int n, int p)
{
	if (n == 0) return 1;
	if (n == 1) return a % p;
	long long res = encryptionAndDecipher(a, n / 2, p);
	if (n % 2 == 0)
	{
		return (res * res) % p;
	}
	else
	{
		return ((a * res) % p * res) % p;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\tРеализация шифрования RSA.";
	int P = 17, Q = 11;
	int D = 23; // D и N - открытые ключи шифрования 
	int N = P * Q;
	int L = (P - 1) * (Q - 1);
	cout << "\n\nПараметры системы шифрования (открытый ключ): D=" << D << ", N=" << N;

	int E = 1; // начальное значение закрытого ключа E
	while (true)
	{
		if ((E * D) % L == 1)
			break;
		else
			E++;
	}
	
	char inputText[LENGTH];
	int convertInputText[SIZE];
	int cipher[SIZE];

	cout << "\nВведите слово/предложение, которое необходимо зашифровать: ";
	cin.get(inputText, LENGTH, '\r');

	for (int i = 0; i < SIZE; i++) // конвертация массива типа char в массив типа int
	{
		convertInputText[i] = static_cast<int>(inputText[i]);
	}

	cout << "Введённое слово/предложение, переведённое в численный формат по таблице ASCII: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << convertInputText[i] << ' ';
	}

	cout << "\n\nПроизводим шифрацию...";
	for (int i = 0; i < SIZE; i++) // шифровка
	{
		int a = convertInputText[i];
		cipher[i] = encryptionAndDecipher(a, E, N);
	}
	cout << "\nЗашифрованное слово/предложение: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << cipher[i] << ' ';
	}
	cout << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << static_cast<char>(cipher[i]);
	}

	cout << "\n\nПроизводим дешифрацию...";
	for (int i = 0; i < SIZE; i++) // расшифровка
	{
		int a = cipher[i];
		cipher[i] = encryptionAndDecipher(a, D, N);
	}
	cout << "\nРасшифрованное слово/предложение: ";
	for (int i = 0; i < SIZE; i++)
	{
		cout << static_cast<char>(cipher[i]);
	}

	cout << endl;
	system("pause");
	return 0;
}