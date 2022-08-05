#include <iostream>
using namespace std;

class bad_lenght : public exception
{
public:
    bad_lenght(string error) {
        cerr << "Вы ввели слово запретной длины! Длина запретное слово равно ";
        cerr << error.length()<<". И это слово: "<<error;
        cerr << ". До свидания!\n";
    }
};

int function(string str, int forbidden_lenght) {
    while (true) {
        if (str.length() == forbidden_lenght) {
            throw bad_lenght (str); 
        }
        else return str.length();
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    string str;
    int a = 0;
    cout << "Введите запретную длину: ";
    cin >> a;
    while (str.length() != a) {
        cout << "Введите слово: ";
        cin >> str;
        try {
            function(str, a);
        }
        catch (bad_lenght& e) {
            continue;
        };

        cout << "Длина слова " << str << " равна " << str.length() << endl;
    }
    
    return 0;
}