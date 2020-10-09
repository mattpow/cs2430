// Author: Matthew Powell
// Date: September 23, 2020
// Class: CS 2430
// Purpose: To generate, traverse, output, insert, and delete nodes from an
// ordered linked list
//
// Inputs: N/A
// Outputs: OutputA.txt, OutputB.txt containing the linked list

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Node
{
  int data;
  Node* next;
};

// Inserts node with data value val into the list in ascending order
void insert(Node*& list, int val);

// Delete instances of node with data value val from the list
void deleteVal(Node*& list, int val);

// Deletes the node from the list at the specific index
void deleteIndex(Node*& list, int index);

// Traverses list and outputs list data values to file
void print(Node* list, ofstream& outs);

// Deletes the entire list
void deleteAll(Node*& list);

// Generates a randomized list of size (size). Only contains values between
// 1 (inclusive) and 10000 (exclusive)
void constructList(Node*& list, int size);

Node* head = nullptr;

int SIZE = 80;

int main()
{
  ofstream output;

  constructList(head, SIZE);

  output.open("OutputA.txt");
  print(head, output);
  output.close();

  deleteIndex(head, 0);
  deleteIndex(head,  SIZE - 2);
  deleteIndex(head, rand() % (SIZE - 3) + 1);

  output.open("OutputB.txt");
  print(head, output);
  output.close();

  deleteAll(head);

  return 0;
}

void print(Node* list, ofstream& outs)
{
  while (list != nullptr) {
    outs << list->data << endl;
    list = list->next;
  }
}

void insert(Node*& list, int val)
{
  Node* temp = new Node;
  Node* ptr = list;
  temp->data = val;

  if (list == nullptr || temp->data < list->data) {
    temp->next = list;
    list = temp;
  } else {
    while (ptr->next != nullptr && ptr->next->data < temp->data) {
      ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
  }
}

void deleteVal(Node*& list, int val)
{
  Node* ptr = list;
  if (ptr != nullptr) {
    if (ptr->data == val) {
      ptr = ptr->next;
      list = ptr;
    } else {
      while(ptr->next != nullptr && ptr->next->next != nullptr) {
        if (ptr->data == val) {
          ptr->data = ptr->next->data;
          delete ptr->next;
          ptr->next = ptr->next->next;
        }
        ptr = ptr->next;
      }
      if (ptr->next->data == val) {
        delete ptr->next;
        ptr->next = nullptr;
      }
    }
  }
}

void deleteAll(Node*& list)
{
  Node* temp;
  while (list != nullptr) {
    temp = list;
    list = list->next;
    delete temp;
  }
}

void constructList(Node*& list, int size)
{
  for (int i = 0; i < size; i++) {
    insert(list, rand() % 9999 + 1);
  }
}

void deleteIndex(Node*& list, int index)
{
  Node* ptr = list;
  int currIndex = 0;
  if (ptr != nullptr) {
    while (ptr->next != nullptr && currIndex < index) {
      currIndex++;
      ptr = ptr->next;
    }
    deleteVal(list, ptr->data);
  }
}