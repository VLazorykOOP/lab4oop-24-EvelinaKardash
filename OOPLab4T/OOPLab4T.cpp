#include <iostream>
#include <cstdlib>

class VectorLong {
private:
    long *ptr; // вказівник на динамічний масив цілих чисел
    int size; // розмір вектора
    int codeError; // змінна стану для коду помилки

public:
    // Конструктор без параметрів
    VectorLong() {
        size = 1;
        ptr = new long[size]; // виділення пам'яті для одного елемента
        ptr[0] = 0; // ініціалізація значенням нуль
        codeError = 0;
    }

// Конструктор з одним параметром - розмір вектора
    explicit VectorLong(int s) {
        size = s;
        ptr = new long[size]; // виділення пам'яті для s елементів
        for (int i = 0; i < size; ++i)
            ptr[i] = 0; // ініціалізація всіх елементів значенням нуль
        codeError = 0;
    }
    // Конструктор з двома параметрами - розмір вектора і значення ініціалізації
    VectorLong(int s, long initValue) {
        size = s;
        ptr = new long[size]; // виділення пам'яті для s елементів
        for (int i = 0; i < size; ++i)
            ptr[i] = initValue; // ініціалізація всіх елементів значенням initValue
        codeError = 0;
    }

// Конструктор копіювання
    VectorLong(const VectorLong &vec) {
        size = vec.size;
        ptr = new long[size]; // виділення пам'яті для копіювання значень
        for (int i = 0; i < size; ++i)
            ptr[i] = vec.ptr[i]; // копіювання значень з іншого вектора
        codeError = vec.codeError;
    }

    // Деструктор
    ~VectorLong() {
        delete[] ptr; // звільнення пам'яті, виділеної для масиву
    }

// Префіксний та постфіксний оператори ++ та --
    VectorLong &operator++() {
        for (int i = 0; i < size; ++i)
            ++ptr[i]; // збільшення кожного елемента на 1
        return *this;
    }

    const VectorLong operator++(int) {
        VectorLong temp(*this);
        operator++();
        return temp;
    }

    VectorLong &operator--() {
        for (int i = 0; i < size; ++i)
            --ptr[i]; // зменшення кожного елемента на 1
        return *this;
    }

    const VectorLong operator--(int) {
        VectorLong temp(*this);
        operator--();
        return temp;
    }

    // Унарний логічний !
    bool operator!() const {
        return size == 0;
    }

    // Унарний побітовий ~
    VectorLong operator~() const {
        VectorLong result(*this);
        for (int i = 0; i < size; ++i)
            result.ptr[i] = ~result.ptr[i]; // побітове заперечення для кожного елемента
        return result;
    }

    // Унарний арифметичний -
    VectorLong operator-() const {
        VectorLong result(*this);
        for (int i = 0; i < size; ++i)
            result.ptr[i] = -result.ptr[i]; // зміна знаку для кожного елемента
        return result;
    }

    // Присвоєння =
    VectorLong &operator=(const VectorLong &vec) {
        if (this != &vec) {
            delete[] ptr;
            size = vec.size;
            ptr = new long[size]; // виділення пам'яті для копіювання значень
            for (int i = 0; i < size; ++i)
                ptr[i] = vec.ptr[i]; // копіювання значень з іншого вектора
            codeError = vec.codeError;
        }
        return *this;
    }

// Присвоєння +=
    VectorLong &operator+=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] += vec.ptr[i]; // додавання значень кожного елемента
        return *this;
    }

// Присвоєння -=
    VectorLong &operator-=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] -= vec.ptr[i]; // віднімання значень кожного елемента
        return *this;
    }
    // Присвоєння *= з скаляром
    VectorLong &operator*=(long scalar) {
        for (int i = 0; i < size; ++i)
            ptr[i] *= scalar; // множення кожного елемента на скаляр
        return *this;
    }

    // Присвоєння /= з скаляром
    VectorLong &operator/=(long scalar) {
        if (scalar != 0) {
            for (int i = 0; i < size; ++i)
                ptr[i] /= scalar; // ділення кожного елемента на скаляр
        } else {
            codeError = 1; // помилка ділення на нуль
        }
        return *this;
    }

    // Присвоєння %= з скаляром
    VectorLong &operator%=(long scalar) {
        if (scalar != 0) {
            for (int i = 0; i < size; ++i)
                ptr[i] %= scalar; // обчислення остачі від ділення кожного елемента на скаляр
        } else {
            codeError = 1; // помилка ділення на нуль
        }
        return *this;
    }
    // Побітове присвоєння |=
    VectorLong &operator|=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] |= vec.ptr[i]; // побітове додавання значень кожного елемента
        return *this;
    }

// Побітове присвоєння ^=
    VectorLong &operator^=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] ^= vec.ptr[i]; // побітове додавання за модулем 2 значень кожного елемента
        return *this;
    }
    // Побітове присвоєння &=
    VectorLong &operator&=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] &= vec.ptr[i]; // побітове множення значень кожного елемента
        return *this;
    }
// Бінарне арифметичне +
    VectorLong operator+(const VectorLong &vec) const {
        VectorLong result(*this);
        result += vec; // додавання значень кожного елемента
        return result;
    }
// Бінарне арифметичне -
    VectorLong operator-(const VectorLong &vec) const {
        VectorLong result(*this);
        result -= vec; // віднімання значень кожного елемента
        return result;
    }

// Бінарне арифметичне * з скаляром
    VectorLong operator*(long scalar) const {
        VectorLong result(*this);
        result *= scalar;  // множення значень кожного елемента на скаляр
        return result;
    }
    // Бінарне арифметичне / з скаляром
    VectorLong operator/(long scalar) const {
        VectorLong result(*this);
        result /= scalar; // ділення значень кожного елемента на скаляр
        return result;
    }

// Бінарне арифметичне % з скаляром
    VectorLong operator%(long scalar) const {
        VectorLong result(*this);
        result %= scalar; // обчислення остачі від ділення значень кожного елемента на скаляр
        return result;
        return result;
    }
    // Побітове бінарне |
    VectorLong operator|(const VectorLong &vec) const {
        VectorLong result(*this);
        result |= vec; // побітове додавання значень кожного елемента
        return result;
    }
    // Побітове бінарне ^
    VectorLong operator^(const VectorLong &vec) const {
        VectorLong result(*this);
        result ^= vec; // побітове додавання за модулем 2 значень кожного елемента
        return result;
    }

// Побітове бінарне &
    VectorLong operator&(const VectorLong &vec) const {
        VectorLong result(*this);
        result &= vec; // побітове множення значень кожного елемента
        return result;
    }

// Оператор індексації []
    long &operator[](int index) {
        if (index < 0 || index >= size) {
            codeError = 2; // помилка виходу за межі діапазону індексів
            return ptr[size - 1];  // повертає останній елемент
        }
        return ptr[index];
    }
    // Оператор виклику функції ()
    void operator()() {
        std::cout << "VectorLong object called.\n";
    }
    // Оператори порівняння
    bool operator==(const VectorLong &vec) const {
        if (size != vec.size)
            return false;
        for (int i = 0; i < size; ++i) {
            if (ptr[i] != vec.ptr[i])
                return false;
        }
        return true;
    }

    bool operator!=(const VectorLong &vec) const {
        return !(*this == vec);
    }

    bool operator>(const VectorLong &vec) const {
        for (int i = 0; i < size; ++i) {
            if (ptr[i] <= vec.ptr[i])
                return false;
        }
        return true;
    }

    bool operator>=(const VectorLong &vec) const {
        for (int i = 0; i < size; ++i) {
            if (ptr[i] < vec.ptr[i])
                return false;
        }
        return true;
    }

    bool operator<(const VectorLong &vec) const {
        for (int i = 0; i < size; ++i) {
            if (ptr[i] >= vec.ptr[i])
                return false;
        }
        return true;
    }

    bool operator<=(const VectorLong &vec) const {
        for (int i = 0; i < size; ++i) {
            if (ptr[i] > vec.ptr[i])
                return false;
        }
        return true;
    }

// Дружні функції для операцій зсуву бітів
    friend std::istream &operator>>(std::istream &is, VectorLong &vec);
    friend std::ostream &operator<<(std::ostream &os, const VectorLong &vec);

};
// Оператор вводу >>
std::istream &operator>>(std::istream &is, VectorLong &vec) {
    for (int i = 0; i < vec.size; ++i)
        is >> vec.ptr[i]; // введення значень кожного елемента
    return is;
}
// Оператор виводу <<
std::ostream &operator<<(std::ostream &os, const VectorLong &vec) {
    for (int i = 0; i < vec.size; ++i)
        os << vec.ptr[i] << " "; // виведення значень кожного елемента
    return os;
}

int main() {
    // Створення об'єкту вектора з розміром 5 та значеннями за замовчуванням
    VectorLong vec1(5);

    // Введення значень для вектора з клавіатури
    std::cout << "Enter values for vector vec1:" << std::endl;
    std::cin >> vec1;

    // Виведення значень вектора
    std::cout << "Vector vec1: " << vec1 << std::endl;

    // Збільшення значень вектора на 1 та виведення результату
    std::cout << "Vector vec1 after incrementing: " << ++vec1 << std::endl;

    // Множення значень вектора на 2 та виведення результату
    std::cout << "Vector vec1 multiplied by 2: " << vec1 * 2 << std::endl;

    // Створення другого вектора та присвоєння його значень першому
    VectorLong vec2(5);
    std::cout << "Enter values for vector vec2:" << std::endl;
    std::cin >> vec2;
    vec1 = vec2;

    // Порівняння двох векторів та виведення результату
    std::cout << "Are vec1 and vec2 equal? " << (vec1 == vec2 ? "Yes" : "No") << std::endl;

    return 0;
}
