#include <iostream>
#include <map>
#include <string>

class AssociativeClass {
private:
    std::map<std::string, std::string> data;
    int errorCode;

public:
    // Конструктор за замовчуванням
    AssociativeClass() : errorCode(0) {}

    // Додати асоціативну пару
    void addAssociation(const std::string& key, const std::string& value) {
        data[key] = value;
    }

    // Перевантаження операції індексації []
    std::string& operator[](const std::string& key) {
        if (data.find(key) == data.end()) {
            errorCode = 1; // Код помилки: ключ не знайдено
            return data[key]; // Повертаємо посилання на елемент для зручності
        }
        return data[key];
    }

    // Функція виведення
    friend std::ostream& operator<<(std::ostream& os, const AssociativeClass& obj) {
        for (const auto& pair : obj.data) {
            os << "Електронна пошта: " << pair.first << ", ПІБ: " << pair.second << std::endl;
        }
        return os;
    }

    // Функція введення
    friend std::istream& operator>>(std::istream& is, AssociativeClass& obj) {
        std::string email, fullName;
        std::cout << "Введіть електронну пошту: ";
        is >> email;
        std::cout << "Введіть ПІБ: ";
        is.ignore(); // Щоб пропустити символ нового рядка після введення email
        std::getline(is, fullName);
        obj.addAssociation(email, fullName);
        return is;
    }

    // Функція-оператор виклику ()
    void operator()() {
        std::cout << "Об'єкт AssociativeClass викликаний.\n";
    }
};

int main() {
    AssociativeClass associations;

    // Додавання асоціативних пар
    associations.addAssociation("kardash.evelina@chnu.edu.ua", "Kardash Evelina");
    associations.addAssociation("kardash.evelina@chnu.edu.ua", "Kardash Evelina");

    // Використання оператора []
    std::cout << "ПІБ для kardash.evelina@chnu.edu.ua: " << associations["kardash.evelina@chnu.edu.ua"] << std::endl;
    std::cout << "ПІБ для non-existent@example.com: " << associations["non-existent@example.com"] << std::endl;

    // Перевантажена функція-оператор ()
    associations();

    // Використання оператора введення >>
    std::cin >> associations;

    // Використання оператора виведення <<
    std::cout << associations;

    return 0;
}
