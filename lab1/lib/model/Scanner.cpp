#include "Scanner.h"

Scanner::Scanner(std::istream &in) : in(in) {}

int Scanner::nextInt() const {
    int number;
    in >> number;
    if (in.bad() || in.eof()) {
        throw std::runtime_error("Wrong input");
    }
    while (!in.good()) {
        in.clear();
        std::string trash;
        std::getline(in, trash);
        std::cout << "Wrong input, try again" << std::endl;
        in >> number;
    }
    return number;
}

int Scanner::nextInt(const std::string &message) const {
    std::cout << message << std::endl;
    return nextInt();
}


int Scanner::nextInt(int min, int max) const {
    int x;
    do {
        x = nextInt();
        if (x < min || x > max) std::cout << "Value must be >= " << min << " and <= " << max << " , try again" << std::endl;
    } while (x < 0);
    return x;
}

int Scanner::nextInt(int min, int max, const std::string &message) const {
    int x;
    do {
        x = nextInt(message);
        if (x < min || x > max) std::cout << "Value must be >= " << min << " and <= " << max << " , try again" << std::endl;
    } while (x < min || x > max);
    return x;
}


unsigned Scanner::nextUnsigned() const {
    int x;
    do {
        x = nextInt();
        if (x < 0) std::cout << "Value must be unsigned, try again" << std::endl;
    } while (x < 0);
    return x;
}

unsigned Scanner::nextUnsigned(const std::string &message) const {
    int x;
    do {
        x = nextInt(message);
        if (x < 0) std::cout << "Value must be unsigned, try again" << std::endl;
    } while (x < 0);
    return x;
}

int Scanner::nextInt(int exclude, const std::string &message) {
    int x;
    do {
        x = nextInt(message);
        if (x == exclude) std::cout << "Value must not be equals " << exclude << std::endl;
    } while (x == exclude);
    return x;
}


