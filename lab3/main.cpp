#include "TableController.h"
#include "Dialog.h"

int main() {
    TableController controller = TableController();
    Dialog dialog = Dialog();
    dialog.addAction("Add item",
                     [&controller]() {
                         controller.addItem();
                     });
    dialog.addAction("Print table",
                     [&controller]() {
                         controller.printTable();
                     });
    dialog.addAction("Find item",
                     [&controller]() {
                         controller.findItem();
                     });
    dialog.addAction("Update item",
                     [&controller]() {
                         controller.updateItem();
                     });
    dialog.addAction("Remove item",
                     [&controller]() {
                         controller.removeItem();
                     });
    dialog.addAction("Select items where key more than",
                     [&controller]() {
                         controller.selectWhereMore();
                     });
    dialog.run();
    return 0;
}