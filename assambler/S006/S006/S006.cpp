// S006.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n";

	char strf[256]; //вводимая строка
	char Findstr[256];
	char f[] = "%s";//формат строки
	char fd[] = "%d";//формат числа
	cout << "string: ";
	char m[514] = "Search string ";//
	__asm
	{
		lea ebx, strf
		push ebx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8

		lea edx, m
		push edx
		lea ecx, f
		push ecx
		call printf
		add esp, 8

		lea edx, Findstr
		push edx
		lea ecx, f
		push ecx
		call scanf
		add esp, 8


		//zdes' perevorot  inc увелечения числа на 1, mov копирует содержимое из источника в приемник, cmp проверка числа, 
		lea ebx, strf
		

		//
		dec ebx

		lea ecx, Findstr

		b1 :
		inc ebx

			mov al, [ebx]
			cmp al, 0
			je b5
			cmp al, [ecx]
			jnz b1
			mov edx, ebx

			b2 :
		inc ebx
			inc ecx
			mov al, [ebx]
			cmp al, 0
			je b4
			mov al, [ecx]
			cmp al, 0
			je b7
			cmp al, [ebx]
			je b2
			mov ebx, edx
			lea ecx, Findstr
			jmp b1

			b4 :
		mov al, [ecx]
			cmp al, 0
			jne b5

			b7 :
		lea ebx, strf
			sub edx, ebx
			push edx
			jmp b6

			b5 :
		mov ebx, -1
			push ebx

			b6 :
		lea ebx, fd
			push ebx
			call printf
			add esp, 8
	}

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
