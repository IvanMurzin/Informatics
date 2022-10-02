#pragma once

template<class T>
class Resource {
private:
    T *data = nullptr;
public:
    Resource() = default;

    Resource(T *data) : data(data) {}

    bool hasData() const{
        return data != nullptr;
    }

    const T &getData() const{
        return *data;
    }
};