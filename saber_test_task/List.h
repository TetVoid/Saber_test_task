#pragma once

#include <iostream>
#include<string>

// структуру ListNode модифицровать нельзя
struct ListNode {
    ListNode* prev;
    ListNode* next;
    ListNode* rand; // указатель на произвольный элемент данного списка, либо NULL
    std::string     data;
};

class List {
public:
    void Serialize(FILE* file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
    void Deserialize(FILE* file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
    ListNode* add(std::string data);
private:
    std::string goDeep(ListNode* node);
    ListNode* head;
    ListNode* tail;
    int count=0;
};
