#include "TableController.h"

TableController::TableController() {
    bool withCapacity = in.next<bool>("Enter capacity? [1/0]");
    if (withCapacity) {
        int capacity = in.next<int>(1, 100000, "Enter capacity:");
        table = Table(capacity);
        return;
    }
    bool initItems = in.next<bool>("Init items? [1/0]");
    if (initItems) {
        int size = in.next<int>(1, 100, "Enter items size:");
        Item items[size];
        for (int i = 0; i < size; ++i) {
            items[i] = readItem();
        }
        table = Table(items, size);
    }
}

Item TableController::readItem() const {
    std::cout << "Input item:" << std::endl;
    bool defaultItem = in.next<bool>("Init item with default values? [1/0]");
    if (defaultItem) return {};
    bool keyOnly = in.next<bool>("Init item only with key? [1/0]");
    if (keyOnly) return Item(in.next<int>("Enter key:"));
    int key = in.next<int>("Enter key:");
    std::cout << "Enter data:" << std::endl;
    char data[SIZE];
    std::string trash;
    std::getline(std::cin, trash);
    std::cin.getline(data, SIZE);
    return {key, data};
}

void TableController::printTable() {
    std::cout << table << std::endl;
}

void TableController::addItem() {
    std::cout << (table.add(readItem()) ? "OK" : "REFUSE") << std::endl;
}

void TableController::findItem() const {
    int key = in.next<int>("Enter key:");
    const auto resource = table.getItem(key);
    if (resource.hasData()) {
        const auto &item = resource.getData();
        std::cout << "Found:" << std::endl;
        std::cout << "Item key: " << item.getKey() << "; data: " << item.getData() << std::endl;
    } else {
        std::cout << "Item not found" << std::endl;
    }
}

void TableController::updateItem() {
    std::cout << (table.update(readItem()) ? "OK" : "Item not found") << std::endl;
}

void TableController::removeItem() {
    int key = in.next<int>("Enter key:");
    std::cout << (table.remove(key) ? "OK" : "Item not found") << std::endl;
}

void TableController::selectWhereMore() const {
    int key = in.next<int>("Enter key:");
    for (const auto &item: table) {
        if (key > item.getKey()) {
            std::cout << "Item key: " << item.getKey() << "; data: " << item.getData() << std::endl;
        }
    }
}


