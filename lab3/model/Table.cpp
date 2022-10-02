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

std::ostream &operator<<(std::ostream &os, const Table &table) {
    std::cout << "Table:" << std::endl;
    for (const auto &item: table) {
        std::cout << "Item key: " << item.getKey() << "; data: " << item.getData() << std::endl;
    }
    return os;
}


bool Table::add(const Item &item) {
    int index = indexOf(item.getKey());
    if (index >= 0) return false;
    if (data == nullptr) data = new Item[capacity];
    if (size == capacity) resize();
    int insertionPoint = -index - 1;
    const auto &last = data[size - 1];
    for (int i = size; i >= insertionPoint + 1; --i) {
        data[i] = data[i - 1];
    }
    data[insertionPoint] = item;
    ++size;
    return true;
}

/**
 * @return the index of the search key, if it is contained in the table data;
 * otherwise, (-(insertion point) - 1). The insertion point is defined as the point at which the key would be inserted into the list: the index of the first element greater than the key, or size if all elements are less than the specified key. Note that this guarantees that the return value will be >= 0 if and only if the key is found.
 */
int Table::indexOf(int key) const {
    int low = 0;
    int high = size - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (data[mid].getKey() < key)
            low = mid + 1;
        else if (data[mid].getKey() > key)
            high = mid - 1;
        else
            return mid;
    }
    return -(low + 1);
}

void Table::resize() {
    int newCapacity = capacity * 3 / 2;
    Item *newData = new Item[newCapacity];
    for (int i = 0; i < size; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

Resource<Item> Table::getItem(int key) const {
    int index = indexOf(key);
    if (index < 0) return Resource<Item>();
    return Resource<Item>(&data[index]);
}

bool Table::update(const Item &item) {
    int index = indexOf(item.getKey());
    if (index < 0) return false;
    data[index] = item;
    return true;
}

bool Table::remove(int key) {
    int index = indexOf(key);
    if (index < 0) return false;
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
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


Table::Iterator::Iterator(Item *data, int current) : data(data), current(current) {}

Table::Iterator &Table::Iterator::operator++() {
    ++current;
    return *this;
}

Item &Table::Iterator::operator*() const {
    return data[current];
}


bool Table::Iterator::operator!=(const Table::Iterator &right) const {
    return current != right.current;
}
