// Domingos Soares do Carmo Neto - 32032889
#include <string>
#include <iostream>
#include "LinkedList.h"


LinkedList* Create()
{
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

Node* CreateNode(int id, Node* tail, Node* head, std::string name)
{
	Node* node = new Node;

	node->id = id;
	node->name = name;
	node->previous = tail;
	node->next = head;

	return node;
}

void Insert(LinkedList* list, int id, std::string name)
{
	Node* node = CreateNode(id, list->tail, list->head, name);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->head->previous = node;
		list->head = node;
	}

	list->tail->next = list->head;
	++list->count;
}

void Append(LinkedList* list, int id, std::string name)
{
	Node* node = CreateNode(id, list->tail, list->head, name);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	list->head->previous = list->tail;
	++list->count;
}

bool InsertBefore(LinkedList* list,int beforeId, int id, std::string name)//O(n) tempo de execução ---> essa função possui um "for", ou seja, interfere no Big-O do programa. Quanto maior a lista, maior o tempo de execução da lista.
{
	if (IsEmpty(list))
	{
		return false;
	}
	Node* ToInsert = CreateNode(id, nullptr, nullptr, name);
	Node* node = list->head;
	for (int i = 0; i < Count(list) - 1; i++)
	{
		if (beforeId == node->id)
			break;
		node = node->next;
	}
	if (node == list->tail && beforeId != node->id)
	{
		delete ToInsert;
		return false;
	}
	if (beforeId == list->head->id)
	{
		Insert(list, id, name);
		return true;
	}
	ToInsert->previous = node->previous;
	ToInsert->next = node;
	node->previous->next = ToInsert;
	node->previous = ToInsert;
	list->count++;
	return true;
}

bool InsertAfter(LinkedList* list, int afterId, int id, std::string name)//O(n) tempo de execução ---> essa função possui um "for", ou seja, interfere no Big-O do programa. Quanto maior a lista, maior o tempo de execução da lista.
{
	if (IsEmpty(list))
	{
		return false;
	}
	Node* ToInsert = CreateNode(id, nullptr, nullptr, name);
	Node* node = list->tail;
	for (int i = 0; i < Count(list) - 1; i++)
	{
		if (afterId == node->id)
			break;
		node = node->previous;
	}
	if (node == list->head && afterId != node->id)
	{
		delete ToInsert;
		return false;
	}
	if (afterId == list->tail->id)
	{
		Append(list, id, name);
		return true;
	}
	ToInsert->next = node->next;
	ToInsert->previous = node;
	node->next->previous = ToInsert;
	node->next = ToInsert;
	list->count++;
	return true;
}

void Destroy(LinkedList* list)
{
	Clear(list);
	delete list;
}

Node* RemoveHead(LinkedList* list)
{
	Node* removeH = list->head;

	if (removeH == nullptr)
	{
		return nullptr;
	}
	else {
		list->head = list->head->next;
		list->head->previous = list->tail;
		list->tail->next = list->head;

		list->count--;

		return removeH;
	}
}

Node* RemoveTail(LinkedList* list)
{
	Node* removeT = list->tail;

	list->tail = list->tail->previous;
	list->tail->next = list->head;
	list->head->previous = list->tail;

	list->count--;

	return removeT;
}

Node* RemoveNode(LinkedList* list, int elem)
{
	Node* toRemove = list->head;
	Node* previous = nullptr;
	while (toRemove != list->tail && toRemove->id != elem)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	if (toRemove->id != elem)
		return nullptr;
	else if (toRemove == list->head)
		return RemoveHead(list);
	else if (toRemove == list->tail)
		return RemoveTail(list);
	else if (toRemove != nullptr)
	{
		previous->next = toRemove->next;
		toRemove->next->previous = previous;
		--list->count;
		toRemove->next = toRemove->previous = nullptr;
		return toRemove;
	}
	return nullptr;
}


Node* GetHead(const LinkedList* list)
{
	return list->head;
}

Node* GetTail(const LinkedList* list)
{
	return list->tail;
}

void Clear(LinkedList* list)
{
	Node* node = list->head;
	Node* aux = nullptr;

	for (int i = 0; i < list->count; i++)
	{
		aux = node;
		node = node->next;

		delete aux;
	}

	list->head = nullptr;
	list->tail = nullptr;

	list->count = 0;

	node = nullptr;
	aux = nullptr;
}


int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}

void DestroyNode(Node* node)
{
	delete node;
}