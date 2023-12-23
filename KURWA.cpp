#include <iostream>
#include <string>
using namespace std;

int main() {
	setlocale(0, "");
	string z;
	while (1) {
		cout << "Выберите Лабу:\n1 Типы данных и их внутреннее представление в памяти\n 2 Одномерные статические массивы\n 3 Двумерные статические массивы. Указатели\n 4 У четвертрой на Степике нет названия\nX Выход\n";
		cin >> z;
		if (z == "1") {
		}
		else if (z == "2") {
		}
		else if (z == "3") {
		}
		else if (z == "4") {
		}
		else if (z == "x" || z == "X") {
			break;
		}
		else if (z != "1" || z != "2" || z != "3" || z != "4" || z != "X" || z != "x") {
			cout << "Недопустимое значение\n";
			system("pause");
			system("cls");
		}

	}
}
