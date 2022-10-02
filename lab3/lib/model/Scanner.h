#pragma once


#include <iostream>

class Scanner {
private:
    std::istream &in;
public:
    explicit Scanner(std::istream &in) : in(in) {}

    template<class T>
    T next() const {
        T data;
        in >> data;
        if (in.bad() || in.eof()) {
            throw std::runtime_error("Wrong input");
        }
        while (!in.good()) {
            in.clear();
            std::string trash;
            std::getline(in, trash);
            std::cout << "Wrong input, try again" << std::endl;
            in >> data;
        }
        return data;
    }

    template<class T>
    T next(const std::string &message) const {
        std::cout << message << std::endl;
        return next<T>();
    }

    template<class T>
    T next(T min, T max) const {
        int x;
        do {
            x = next<T>();
            if (x < min || x > max) std::cout << "Value must be >= " << min << " and <= " << max << " , try again" << std::endl;
        } while (x < 0);
        return x;
    }

    template<class T>
    T next(T min, T max, const std::string &message) const {
        T x;
        do {
            x = next<T>(message);
            if (x < min || x > max) std::cout << "Value must be >= " << min << " and <= " << max << " , try again" << std::endl;
        } while (x < min || x > max);
        return x;
    }

    template<class T>
    T next(T exclude, const std::string &message) const {
        T x;
        do {
            x = next<T>(message);
            if (x == exclude) std::cout << "Value must not be equals " << exclude << std::endl;
        } while (x == exclude);
        return x;
    }

};