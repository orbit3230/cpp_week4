#include "database.h"
#include <iostream>
using namespace std;

string getKey();
Type getType();
void* getValue(Type type);

int main() {
    Database* db = new Database;
    init(*db);
    string command;
    string key;
    Type type;
    void* value;
    // 명령어가 틀렸을 경우 예외처리를 제대로 주지 않았다.
    // 명령어가 틀리면 프로그램이 의도치않게 종료되거나, 심각한 문제가 생길 수 있다.
    // 틀린 명령어를 입력하지 않도록 주의하자.
    while(true) {
        cout << "command (list, add, get, del, exit): ";
        cin >> command;
        if(command.compare("list") == 0) {
            list(*db);
        }
        else if(command.compare("add") == 0) {
            key = getKey();
            type = getType();
            value = getValue(type);
            add(*db, create(type, key, value));
        }
        else if(command.compare("get") == 0) {
            key = getKey();
            printEntry(get(*db, key));
        }
        else if(command.compare("del") == 0) {
            key = getKey();
            remove(*db, key);
        }
        else if(command.compare("exit") == 0) {
            destroy(*db);
            break;
        }
        else
            cout << "invalid command" << endl;
        cout << "\n";
    }
    return 0;
}