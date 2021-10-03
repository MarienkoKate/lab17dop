#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#ifndef S_
#define S_
template<class T> class set;

template<class T> std::ostream& operator<<(std::ostream&, const set<T>&);

template <class T>
class set {
private:
    size_t cap;
    size_t size;
    T* mas_val;
public:
    set() {
        mas_val = NULL;
        cap = 0;
        size = 0;
    }

    int rep(T num) {
        int b = 0;
        for (int i = 0; i != size; i++) {
            if (mas_val[i] == num) {
                b = 1;
            }
        }
        return b;
    }
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = size - 1; j > i; j--) {

                if (mas_val[j - 1] > mas_val[j]) {

                    T temp = mas_val[j - 1];
                    mas_val[j - 1] = mas_val[j];
                    mas_val[j] = temp;
                }
            }
        }
    }
    set(set& a);
    set& operator=(const set& a);
    void delete_(int ind);
    void insert(const T& value);
    set intersect(set& b);
    bool find(const T& val);
    size_t size_();
    friend std::ostream& operator<<<T>(std::ostream&, const set<T>&);

    ~set() {
        delete[] mas_val;
    }
};

//insert, bool find, cap, set interselect (пересечение)
template <typename T>
size_t set<T>::size_() {
    return size;
}
template <typename T>

std::ostream& operator<<<T>(std::ostream& out, const set<T>& s)
{
    //std::copy()
    for (int i = 0; i != s.size; i++) out << s.mas_val[i] << ' ';
    out << std::endl;

    return out;
}
template <typename T>

void set<T> ::delete_(int ind) {
    if (ind > size) exit(-1);
    for (int i = ind; i != size; i++) {
        this->mas_val[i] = this->mas_val[i + 1];
    }
    cap--;
    size--;
}

template <typename T>
set<T>& set<T> :: operator=(const set& a) {

    if (&a == this) return *this;

    delete[] mas_val;
    cap = a.cap;
    size = a.size;
    mas_val = new T[cap];
    std::copy(a.mas_val, &a.mas_val[cap], mas_val);
    //for (int i = 0; i != cap; i++)  mas_val[i] = a.mas_val[i];

    return *this;
}

template <typename T>

set<T> ::set<T>(set& a) {
    cap = a.cap;
    size = a.size;
    mas_val = new T[cap];
    for (int i = 0; i < cap; i++) mas_val[i] = a.mas_val[i];
}
template <typename T>

set<T> set<T> ::intersect(set& b) {

    if (size == 0 || b.size == 0) throw EmptySet();
    set<T> b_copy, a_copy;
    b_copy = b;
    //cout << b_copy.size_();
    a_copy = *this;
    //set new;
    set<T> povt;
    int n = 0;
    for (int i = 0; i != a_copy.size; i++) {
        for (int j = 0; j != b_copy.size; j++) {
            if (a_copy.mas_val[i] == b_copy.mas_val[j]) {
                povt.insert(b_copy.mas_val[j]);
                a_copy.delete_(i);
                b_copy.delete_(j);
                j--;
                i--;
            }
        }
    }

    delete[] a_copy.mas_val;
    a_copy.mas_val = new T[povt.size];
    a_copy.cap = povt.cap;
    a_copy.size = povt.size;

    for (int i = 0; i != a_copy.size; i++)
        a_copy.mas_val[i] = povt.mas_val[i];

    return a_copy;
}

template <typename T>

void set<T> ::insert(const T& value) {
    bool povt = 0;
    int ind = 0;
    //cout << value;
    if (mas_val == NULL) {
        cap = 1;
        mas_val = new T[cap];
        mas_val[size] = value;
        size++;
    }
    else {
        for (int i = 0; i != size; i++) {
            if (mas_val[i] < value) ind++;
            if (mas_val[i] == value) povt = 1;
        }
        if (povt == 0) {
            if (size == cap) {
                T* tmp = new T[cap];

                int j;
                for (j = 0; j < size; j++) {
                    tmp[j] = mas_val[j];
                }

                cap *= 2;
                mas_val = new T[cap];

                for (j = 0; j < ind; j++) {
                    mas_val[j] = tmp[j];
                }
                mas_val[ind] = value;

                for (int g = ind + 1; g != size + 1 && j != size; g++, j++) {

                    mas_val[g] = tmp[j];

                }


            }
            else {
                for (int j = size; j != ind - 1; j--) {

                    mas_val[j + 1] = mas_val[j];

                }
                mas_val[ind] = value;
            }

            size++;
        }

    }
}
template <typename T>

bool set<T>::find(const T& val) {
    for (int i = 0; i != size; i++) {
        if (mas_val[i] == val) return 1;
    }
    return 0;
}

#endif