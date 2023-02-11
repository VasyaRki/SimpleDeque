#pragma once

#include <iostream>

template <typename type>
class deque
{
public:
	struct Node
	{
		type val;
		Node* next;
		Node* prev;
		Node(type _val) : val(_val), next(nullptr), prev(nullptr)
		{}
		Node() {};
	};
public:
	class Iterator;
	deque() : first(nullptr), last(nullptr) {}
	Iterator begin() { return Iterator(first); } // Ітератор на перший елемент списка
	Iterator end() { return Iterator(last->next); }

	int pop_back();
    int push_front(type _val);
	int pop_front();
    int push_back(type _val);
	int show();
	bool empty();
	size_t size() const {
		return length;
	}

private:
	Node* first, *last;
	size_t length = 0;
};


//Додавання елементу в кінець списку
template <typename T>
int deque<T>::push_back(T _val) {
	Node* ptr = new Node(_val);

	if (first == nullptr) {
		first = last = ptr;
		++length;
		return EXIT_SUCCESS;
	}

	last->next = ptr;
	ptr->prev= last;
	last = ptr;
	++length;
    return EXIT_SUCCESS;
}




//Видалення останнього елементу 
template <typename T>
int deque<T>::pop_back() {
	if (this->last == nullptr) {
		return EXIT_FAILURE;
	}

	if (this->first == this->last) {
		delete this->last;
		first = last = nullptr;
		--length;
		return EXIT_SUCCESS;
	}

	Node* last_delete = last;
	last = last->prev;
    last->next = nullptr;
	delete last_delete;
	--length;
	return EXIT_SUCCESS;
}

//Видалення першого елементу
template<typename T>
int deque<T>::pop_front()
{
	if (this->first == nullptr) {
		return EXIT_FAILURE;
	}

	if (this->first == this->last) {
		delete first;
		first = last = nullptr;

		--length;

		return EXIT_SUCCESS;
	}

	Node* node_tmp = first;
	first = first->next;
	delete node_tmp;
	--length;
	return EXIT_SUCCESS;
}

//Вивід елементів списка
template<typename T>
int deque<T>::show()
{
	std::cout << "[ ";
	for (Node* ptr = this->first; ptr != nullptr; ptr = ptr->next)
	{
		std::cout << ptr->val << " ";
	}
	std::cout << "]";
	return EXIT_SUCCESS;
}

//Повертає True, якщо список пустий
template<typename T>
bool deque<T>::empty() {
	if (this->begin() == nullptr) return true;
	return false;
}


//Клас ітератор для списка
template<typename T>
class deque<T>::Iterator
{
private:
	friend class deque;
	deque<T>::Node* node;

public:
	Iterator(deque<T>::Node* node) : node(node) {}
	Iterator() : node(nullptr) {}

	Iterator& operator =(deque<T>::Node* node) {
		this->node = node;
		return *this;
	}

	T& operator *() {
		return node->val;
	}

	bool operator == (const Iterator& other) {
		return this->node == other.node;
	}

	bool operator !=(const Iterator& other) {
		return this->node != other.node;
	}

	Iterator& operator++() {
		node = node->next;
		return *this;
	}

	Iterator& operator+(int value) {

		for (int i = 0; i < value; i++, node = node->next);
		return *this;
	}
};