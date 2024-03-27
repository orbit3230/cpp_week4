#include "database.h"
#include <iostream>
using namespace std;

typedef struct Database Database;

int main() {
    Database* db = new Database;
    string command;
    while(true) {
        cout << "command (list, add, get, del, save, exit): ";
        cin >> command;
    }
}