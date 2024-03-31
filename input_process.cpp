#include "database.h"
#include <iostream>
#include <string>
using namespace std;

Array* getArray();

string getKey() {
    string key;
    cout << "key: ";
    cin >> key;
    return key;
}

Type getType() {
    Type type;
    string inputType;
    cout << "type (int, double, string, array): ";
    cin >> inputType;
    if(inputType.compare("int") == 0)
        type = INT;
    else if(inputType.compare("double") == 0)
        type = DOUBLE;
    else if(inputType.compare("string") == 0)
        type = STRING;
    else if(inputType.compare("array") == 0)
        type = ARRAY;
    else 
        cout << "invalid command" << endl;
    return type;
}

void* makeArray(Type type, int size) {
    if(type == INT) {
        int* array = new int[size];
        for(int i = 0 ; i < size ; i++) {
            cout << "item[" << i << "]: ";
            cin >> array[i];
        }
        return array;
    }
    if(type == DOUBLE) {
        double* array = new double[size];
        for(int i = 0 ; i < size ; i++) {
            cout << "item[" << i << "]: ";
            cin >> array[i];
        }
        return array;
    }
    if(type == STRING) {
        string* array = new string[size];
        for(int i = 0 ; i < size ; i++) {
            cout << "item[" << i << "]: ";
            cin >> array[i];
        }
        return array;
    }
    if(type == ARRAY) {
        Array* array = new Array[size];
        for(int i = 0 ; i < size ; i++) {
            cout << "item[" << i << "]: ";
            *(array+i) = *(getArray());
        }
        return array;
    }
}

Array* getArray() {
    Array* array = new Array;
    array->type = getType();
    cout << "size: ";
    cin >> array->size;
    array->items = makeArray(array->type, array->size);
    return array;
}

void* getValue(Type type) {
    void* value;
    cout << "value: ";
    if(type == ARRAY)
        value = getArray();
    else if(type == INT) {
        int* input = new int;
        cin >> *input;
        value = input;
    }
    else if(type == DOUBLE) {
        double* input = new double;
        cin >> *input;
        value = input;
    }
    else if(type == STRING) {
        string* input = new string;
        cin.ignore();
        getline(cin, *input);
        value = input;
    }
        
    return value;
}