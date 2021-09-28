#pragma once

#include <iostream>
#include<string>

// ��������� ListNode ������������� ������
struct ListNode {
    ListNode* prev;
    ListNode* next;
    ListNode* rand; // ��������� �� ������������ ������� ������� ������, ���� NULL
    std::string     data;
};

class List {
public:
    void Serialize(FILE* file);  // ���������� � ���� (���� ������ � ������� fopen(path, "wb"))
    void Deserialize(FILE* file);  // �������� �� ����� (���� ������ � ������� fopen(path, "rb"))
    ListNode* add(std::string data);
private:
    std::string goDeep(ListNode* node);
    ListNode* head;
    ListNode* tail;
    int count=0;
};
