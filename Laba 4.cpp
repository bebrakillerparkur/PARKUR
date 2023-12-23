#include <iostream>
#include <fstream>
#include <string>
const int N = 501;
using namespace std;

void DELETE(char* s, int z) {
    s[z] = ' ';
    for (int i = z + 1; i < strlen(s); i++)
        swap(s[i - 1], s[i]);
}



void VTOROE(char* s) {
    for (int i = 2; i < strlen(s); i++) {
        if (((s[i - 1] == ' ') || (s[i - 1] == 'Ы')) && ((s[i] == ' ') || (s[i] == 'Ы')))
            s[i] = 'Ы';
        if (((s[i - 1] == ',') || (s[i - 1] == ';') || (s[i - 1] == '-') || (s[i - 1] == '!') || (s[i - 1] == '?') || (s[i - 1] == 'Ъ')) && ((s[i] == ',') || (s[i] == ';') || (s[i] == '-') || (s[i] == '!') || (s[i] == '?') || (s[i] == 'Ъ')))
            s[i] = 'Ъ';
        if (((s[i - 2] == '.') && (s[i - 1] == '.') && (s[i] != '.'))) {
            s[i - 1] = 'Ъ';
            s[i] = 'Ъ';
        }
        if ((s[i - 2] == '.') && (s[i - 1] != '.'))
            s[i - 1] = 'Ъ';
    }
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] == 'Ъ') || (s[i] == 'Ы')) {
            DELETE(s, i);
            i--;
        }
    }
    for (int i = 1; i < strlen(s); i++) {
        if (s[i - 1] != ' ')
            s[i] = tolower(s[i]);
    }
}


void TRET(char* s) {
    int i = 0;
    char s1[11];
    while (i < strlen(s)) {
        int n = 0;
        while ((s[i + n] != ' ') && (s[i + n] != ',') && (s[i + n] != ';') && (s[i + n] != '.') && (s[i + n] != '-') && (s[i + n] != '!') && (s[i + n] != '?') && (s[i + n] != '\0')) {
            s1[n] = s[i + n];
            n++;
        }
        s1[n] = '\0';
        int d = 0;
        for (int j = 0; j < strlen(s1); j++) {
            if (s1[j] != '0' && s1[j] != '1' && s1[j] != '2' && s1[j] != '3' && s1[j] != '4' && s1[j] != '5' && s1[j] != '6' && s1[j] != '7' && s1[j] != '8' && s1[j] != '9')
                d++;
        }
        if (d == strlen(s1))
            cout << s1 << " ";
        i = i + 1 + strlen(s1);
    }
    cout << "\n";
}


void CHETVERT(char* s) {
    cout << "Последовательность после преобразований:\n";
    int i = 0;
    char s1[11];
    while (i < strlen(s)) {
        int n = 0;
        while ((s[i + n] != ' ') && (s[i + n] != ',') && (s[i + n] != ';') && (s[i + n] != '.') && (s[i + n] != '-') && (s[i + n] != '!') && (s[i + n] != '?') && (s[i + n] != '\0')) {
            s1[n] = s[i + n];
            n++;
        }
        s1[n] = '\0';
        s1[0] = toupper(s1[0]);
        cout << s1 << " ";

        i = i + 1 + strlen(s1);

    }
    cout << "\n";
}

void PAT(char* s, char* smalls)
{
    int x = strlen(s);
    int y = strlen(smalls);
    bool isFind = false;
    for (int i = 0; i < x - y + 1; i++)
    {
        int j;
        for (j = 0; j < y; j++)
        {
            if (s[i + j] != smalls[j])
            {
                break;
            }
        }
        if (j == y)
        {
            cout << "Искомая подстрака найдена, индекс: " << i << '\n';
            isFind = true;
        }
    }
    if (!isFind)
    {
        cout << "Искомая подстрака не найдена\n";
    }
}


void MENU(char* s) {
    string z;
    while (1) {
        cout << "Ваша строка:\n" << s << "\n\n\n2 Редактирование исходного текста\n3 Вывести на экран слова последовательности, не содержащие цифр\n4 Вывести на экран ту же последовательность, заменив во всех словах первую букву соответствующей прописной буквой\n5 Найти все вхождения подстроки в строку\nX Назад\n";
        cin >> z;
        if (z == "2") {
            system("cls");
            cout << "Ваша строка:\n" << s << "\n\n";
            VTOROE(s);
            cout << "Строка после редактирования:\n" << s << "\n";
            system("pause");
            system("cls");
        }
        else if (z == "3") {
            system("cls");
            cout << "Ваша строка:\n" << s << "\n\n";
            TRET(s);
            system("pause");
            system("cls");
        }
        else if (z == "4") {
            system("cls");
            cout << "Ваша строка:\n" << s << "\n\n";
            CHETVERT(s);
            system("pause");
            system("cls");
        }
        else if (z == "5") {
            system("cls");
            cout << "Ваша строка:\n" << s << "\n\n";
            char k[N];
            cout << "Введите текст, который хотите найти\n";
            cin.ignore();
            cin.getline(k, N);
            PAT(s, k);
            system("pause");
            system("cls");
        }
        else if (z == "X" || z == "x") {
            system("cls");
            break;
        }
        else if (z != "1" || z != "2" || z != "3" || z != "4" || z != "X" || z != "x") {
            cout << "Недопустимое значение\n";
            system("pause");
            system("cls");
        }
    }
}





int main() {
    setlocale(0, "");
    char s[N];
    string z;
    while (1) {
        cout << "Выберите способ ввода последовательности:\n1 Ввод с клавиатуры\n2 Ввод из файла\nX Выход\n";
        cin >> z;
        if (z == "1") {
            system("cls");
            cout << "Введите последовательность из 50 слов, в каждом из которых от 1 до 10 латинских букв или цифр\n";
            cin.ignore();
            cin.getline(s, N);
            system("cls");
            MENU(s);
        }
        else if (z == "2") {
            string FileName = "C:\\Users\\artem\\OneDrive\\Рабочий стол\\НИКИТА АЛТУХОВ\\никита алтухов не далёкий.txt";
            ifstream NIKITA;
            NIKITA.open(FileName);
            if (!NIKITA.is_open()) {
                system("cls");
                cout << "Не удалось открыть файл\n";
                system("pause");
                break;
            }
            while (!NIKITA.eof()) {
                NIKITA.getline(s, N);
            }
            NIKITA.close();
            system("cls");
            system("cls");
            MENU(s);
        }
        else if (z == "X" || z == "x") {
            break;
        }
        else if (z != "1" || z != "2" || z != "X" || z != "x") {
            cout << "Недопустимое значение\n";
            system("pause");
            system("cls");
        }
    }
    return 0;
}