// Domingos Soares do Carmo Neto - 32032889
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <string>
#include <iostream>


struct Node
{
	int id;
	std::string name;
	Node* previous;
	Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};


LinkedList* Create();

void Insert(LinkedList* list, int id, std::string);

bool InsertBefore(LinkedList* list, int beforeId, int id, std::string name);

bool InsertAfter(LinkedList* list, int afterId, int id, std::string name);

void Append(LinkedList* list, int id, std::string);

Node* RemoveHead(LinkedList* list);

Node* RemoveTail(LinkedList* list);

Node* RemoveNode(LinkedList* list, int id);

Node* GetHead(const LinkedList* list);

Node* GetTail(const LinkedList* list);

int Count(const LinkedList* list);

bool IsEmpty(const LinkedList* list);

void Clear(LinkedList* list);

Node* CreateNode(int id, Node* tail, Node* head, std::string name);

void Destroy(LinkedList* list);

void DestroyNode(Node* node);

#endif