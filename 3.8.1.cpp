#include <iostream>
using namespace std;

class bad_lenght : public std::exception
{
public:
    const char* what() const override { return "Вы ввели слово запретной длины! До свидания!"; }
};

int function(string str, int forbidden_lenght) {
    
    if (str.length() == forbidden_lenght) {
        throw bad_lenght();
    }
    else return str.length();
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
        try{
        function(str, a);
        }
        catch (bad_lenght& e) {
            cout << e.what(); continue;
        }
        cout << "Длина слова " << str << " равна " << str.length() << endl;
    }
    return 0;
}