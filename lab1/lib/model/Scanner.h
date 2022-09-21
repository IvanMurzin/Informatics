#pragma once


#include <iostream>

class Scanner {
private:
    std::istream &in;
public:
    explicit Scanner(std::istream &in);

    int nextInt() const;

    int nextInt(const std::string &message) const;

    int nextInt(int min, int max) const;

    int nextInt(int exclude, const std::string &message);

    int nextInt(int min, int max, const std::string &message) const;

    __attribute__((unused)) unsigned nextUnsigned() const;

    unsigned nextUnsigned(const std::string &message) const;

};