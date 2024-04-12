#include <iostream>
#include <cstdlib>

class VectorLong {
private:
    long *ptr;
    int size;
    int codeError;

public:
    VectorLong() {
        size = 1;
        ptr = new long[size];
        ptr[0] = 0;
        codeError = 0;
    }

    explicit VectorLong(int s) {
        size = s;
        ptr = new long[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = 0;
        codeError = 0;
    }

    VectorLong(int s, long initValue) {
        size = s;
        ptr = new long[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = initValue;
        codeError = 0;
    }


    VectorLong(const VectorLong &vec) {
        size = vec.size;
        ptr = new long[size];
        for (int i = 0; i < size; ++i)
            ptr[i] = vec.ptr[i];
        codeError = vec.codeError;
    }


    ~VectorLong() {
        delete[] ptr;
    }


    VectorLong &operator++() {
        for (int i = 0; i < size; ++i)
            ++ptr[i];
        return *this;
    }

    const VectorLong operator++(int) {
        VectorLong temp(*this);
        operator++();
        return temp;
    }

    VectorLong &operator--() {
        for (int i = 0; i < size; ++i)
            --ptr[i];
        return *this;
    }

    const VectorLong operator--(int) {
        VectorLong temp(*this);
        operator--();
        return temp;
    }


    bool operator!() const {
        return size == 0;
    }


    VectorLong operator~() const {
        VectorLong result(*this);
        for (int i = 0; i < size; ++i)
            result.ptr[i] = ~result.ptr[i];
        return result;
    }


    VectorLong operator-() const {
        VectorLong result(*this);
        for (int i = 0; i < size; ++i)
            result.ptr[i] = -result.ptr[i];
        return result;
    }


    VectorLong &operator=(const VectorLong &vec) {
        if (this != &vec) {
            delete[] ptr;
            size = vec.size;
            ptr = new long[size];
            for (int i = 0; i < size; ++i)
                ptr[i] = vec.ptr[i];
            codeError = vec.codeError;
        }
        return *this;
    }


    VectorLong &operator+=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] += vec.ptr[i];
        return *this;
    }


    VectorLong &operator-=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] -= vec.ptr[i];
        return *this;
    }

    VectorLong &operator*=(long scalar) {
        for (int i = 0; i < size; ++i)
            ptr[i] *= scalar;
        return *this;
    }


    VectorLong &operator/=(long scalar) {
        if (scalar != 0) {
            for (int i = 0; i < size; ++i)
                ptr[i] /= scalar;
        } else {// Division by zero error
        }
        return *this;
    }


    VectorLong &operator%=(long scalar) {
        if (scalar != 0) {
            for (int i = 0; i < size; ++i)
                ptr[i] %= scalar;
        } else {
            codeError = 1;
        }
        return *this;
    }


    VectorLong &operator|=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] |= vec.ptr[i];
        return *this;
    }


    VectorLong &operator^=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] ^= vec.ptr[i];
        return *this;
    }


    VectorLong &operator&=(const VectorLong &vec) {
        for (int i = 0; i < size; ++i)
            ptr[i] &= vec.ptr[i];
        return *this;
    }


    VectorLong operator+(const VectorLong &vec) const {
        VectorLong result(*this);
        result += vec;
        return result;
    }


    VectorLong operator-(const VectorLong &vec) const {
        VectorLong result(*this);
        result -= vec;
        return result;
    }


    VectorLong operator*(long scalar) const {
        VectorLong result(*this);
        result *= scalar;
        return result;
    }

    VectorLong operator/(long scalar) const {
        VectorLong result(*this);
        result /= scalar;
        return result;
    }


    VectorLong operator%(long scalar) const {
        VectorLong result(*this);
        result %= scalar;
        return result;
    }


    VectorLong operator|(const VectorLong &vec) const {
        VectorLong result(*this);
        result |= vec;
        return result;
    }


    VectorLong operator^(const VectorLong &vec) const {
        VectorLong result(*this);
        result ^= vec;
        return result;
    }


    VectorLong operator&(const VectorLong &vec) const {
        VectorLong result(*this);
        result &= vec;
        return result;
    }


    long &operator[](int index) {
        if (index < 0 || index >= size) {
            codeError = 2;
            return ptr[size - 1];
        }
        return ptr[index];
    }


    void operator()() {
        std::cout << "VectorLong object called.\n";
    }


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


    friend std::istream &operator>>(std::istream &is, VectorLong &vec);

    friend std::ostream &operator<<(std::ostream &os, const VectorLong &vec);

};


std::istream &operator>>(std::istream &is, VectorLong &vec) {
    for (int i = 0; i < vec.size; ++i)
        is >> vec.ptr[i];
    return is;
}

std::ostream &operator<<(std::ostream &os, const VectorLong &vec) {
    for (int i = 0; i < vec.size; ++i)
        os << vec.ptr[i] << " ";
    return os;
}

int main() {

    VectorLong vec1(3, 5);
    VectorLong vec2(3);
    vec2 = vec1 + static_cast<const VectorLong>(3);
    std::cout << vec2 << std::endl;

    return 0;
}
