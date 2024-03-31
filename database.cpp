#include "database.h"
#include <iostream>
using namespace std;

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value) {
    Entry* entry = new Entry;
    entry->type = type;
    entry->key = key;
    entry->value = value;
    return entry;
}

// 데이터베이스를 초기화한다.
void init(Database &database) {
    database.length = 0;
    database.entries = new Entry[0];
}

// 데이터베이스에 엔트리를 추가한다.
void add(Database &database, Entry *entry) {
    Entry* newEntry = new Entry[database.length+1];
    database.length++;
    for(int i = 0 ; i < database.length-1 ; i++) {
        (newEntry+i)->key = (database.entries+i)->key;
        (newEntry+i)->type = (database.entries+i)->type;
        (newEntry+i)->value = (database.entries+i)->value;
    }

    (newEntry+(database.length-1))->key = entry->key;
    (newEntry+(database.length-1))->type = entry->type;
    (newEntry+(database.length-1))->value = entry->value;
    
    database.entries = newEntry;
}

void printArray(Array* array) {
    cout << "[";
    for(int i = 0 ; i < array->size ; i++) {
        if(array->type == INT) {
            int* items = (int*)array->items;
            cout << items[i];
            if(i != array->size-1)
                cout << ", ";
            else
                cout << "]";
        }
        else if(array->type == DOUBLE) {
            double* items = (double*)array->items;
            cout << items[i];
            if(i != array->size-1)
                cout << ", ";
            else
                cout << "]";
        }
        else if(array->type == STRING) {
            string* items = (string*)array->items;
            cout << "\"" << items[i] << "\"";
            if(i != array->size-1)
                cout << ", ";
            else
                cout << "]";
        }
        else if(array->type == ARRAY) {
            Array* items = (Array*)array->items;
            printArray(items + i);
            if(i != array->size-1)
                cout << ", ";
            else
                cout << "]";
        }
    }
}

// 엔트리 정보를 출력한다.
void printEntry(Entry *entry) {
    cout << entry->key << ": ";
    if(entry->type == INT) {
        int value = *((int*)entry->value);
        cout << value << endl;
    }
    else if(entry->type == DOUBLE) {
        double value = *((double*)entry->value);
        cout << value << endl;
    }
    else if(entry->type == STRING) {
        string value = *((string*)entry->value);
        cout << value << endl;
    }
    else if(entry->type == ARRAY) {
        Array* value = (Array*)entry->value;
        printArray(value);
        cout << endl;
    }
}

// 데이터베이스에서 키에 해당하는 엔트리를 찾는다.
Entry *get(Database &database, std::string &key) {
    for(int i = 0 ; i < database.length ; i++)
        if((database.entries+i)->key.compare(key) == 0) 
            return database.entries+i;

    cout << "not found" << endl;
    return NULL;
}

// 데이터베이스의 엔트리들을 모두 보여준다.
void list(Database &database) {
    for(int i = 0 ; i < database.length ; i++) {
        printEntry(database.entries+i);
    }
}

// 데이터베이스에서 키에 해당하는 엔트리를 제거한다.
void remove(Database &database, std::string &key) {
    int index = -1;
    for(int i = 0 ; i < database.length ; i++) {
        // get 함수를 이용하려했지만, 인덱스를 찾아주지 못함.
        if((database.entries+i)->key.compare(key) == 0) {
            index = i;
            break;
        }
    }
    if(index == -1) {
        cout << "not found" << endl;
    }
    else {
        // 덮어씌우기
        for(int i = index ; i < database.length - 1 ; i++) {
            database.entries[i] = database.entries[i + 1];
        }
        database.length--;
    }
}

// 데이터베이스를 해제한다.
void destroy(Database &database) {
    delete database.entries;
}