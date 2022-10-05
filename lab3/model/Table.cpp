#include "Table.h"

Table::Table() : capacity(10) {}

Table::Table(int capacity) : capacity(capacity) {}

Table::~Table() {
    delete[] data;
}

Table::Table(Item *items, int size) : capacity(size > 10 ? size : 10) {
    data = new Item[capacity];
    for (int i = 0; i < size; ++i) {
        add(items[i]);
    }
}

int Table::getSize() const {
    return size;
}

Table::Iterator Table::begin() const {
    return {data, 0};
}

Table::Iterator Table::end() const {
    return {data, size};
}

Table &Table::operator=(const Table &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new Item[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

Table &Table::operator=(Table &&other) {
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->data;
    this->data = other.data;
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
    return *this;
}

Table::Table(const Table &other) {
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new Item[capacity];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

Table::Table(Table &&other) {
    this->size = other.size;
    this->capacity = other.capacity;
    delete[] this->data;
    this->data = other.data;
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

std::ostream &operator<<(std::ostream &os, const Table &table) {
    os << "Table:" << std::endl;
    for (const auto &item: table) {
        os << "Item key: " << item.getKey() << "; data: " << item.getData() << std::endl;
    }
    return os;
}


bool Table::add(const Item &item) {
    if (size == capacity) resize();
    Item *result = std::lower_bound(data, data + size, item.getKey(), [](const Item &current, int key) { return current.getKey() < key; });
    if (data == nullptr) data = new Item[capacity];
    if (result == nullptr) data[0] = item;
    else {
        if (result != data + size && result->getKey() == item.getKey()) return false;
        for (Item *p = data + size; p >= result + 1; --p) {
            *p = *(p - 1);
        }
        *result = item;
    }
    ++size;
    return true;
}

/**
 * @return the index of the search key, if it is contained in the table data;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as the point at which the key would be inserted into the list: the index of the first element greater than the key, or size if all elements are less than the specified key. Note that this guarantees that the return value will be >= 0 if and only if the key is found.
 */
//int Table::indexOf(int key) const {
//    int count = 0;
//    int low = 0;
//    int high = size - 1;
//    int mid;
//    while (low <= high) {
//        ++count;
//        mid = (low + high) / 2;
//        if (data[mid].getKey() < key)
//            low = mid + 1;
//        else if (data[mid].getKey() > key)
//            high = mid - 1;
//        else
//            return mid;
//    }
//    std::cout << "index of    iterations :" << count << std::endl;
//    return -(low + 1);
//}

void Table::resize() {
    int newCapacity = capacity * 3 / 2;
    Item *newData = new Item[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    std::cout << *this << std::endl;
}

Resource<Item> Table::getItem(int key) const {
    Item *result = std::lower_bound(data, data + size, key, [](const Item &current, int key) { return current.getKey() < key; });
    if (result == data + size || result->getKey() != key) return Resource<Item>();
    return Resource<Item>(result);
}

bool Table::update(const Item &item) {
    int key = item.getKey();
    Item *result = std::lower_bound(data, data + size, key, [](const Item &current, int key) { return current.getKey() < key; });
    if (result == data + size || result->getKey() != key) return false;
    *result = item;
    return true;
}

bool Table::remove(int key) {
    Item *result = std::lower_bound(data, data + size, key, [](const Item &current, int key) { return current.getKey() < key; });
    if (result == data + size || result->getKey() != key) return false;
    for (Item *i = result; i < data + size - 1; ++i) {
        *i = *(i + 1);
    }
    --size;
    return true;
}

int Table::getCapacity() const {
    return capacity;
}

bool Table::isDataNull() const {
    return data == nullptr;
}

Resource<Item> Table::operator[](int key) const {
    return getItem(key);
}

Table::Iterator::Iterator(Item *data, int current) : data(data), current(current) {}

Table::Iterator &Table::Iterator::operator++() {
    ++current;
    return *this;
}

Table::Iterator Table::Iterator::operator++(int) {
    Iterator old(*this);
    ++*this;
    return old;
}

Item &Table::Iterator::operator*() const {
    return data[current];
}


bool Table::Iterator::operator!=(const Table::Iterator &right) const {
    return current != right.current;
}

Item *Table::Iterator::operator->() const {
    return &data[current];
}

