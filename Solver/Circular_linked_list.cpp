#include "Node.h"
#include "Circular_linked_list.h"
#include <initializer_list>
#include <iostream>

namespace rut::miit::llist 
{
	Circular_linked_list::Circular_linked_list(const std::initializer_list<int>& values)
	{
		Node* prev = nullptr;
		for (int val : values)
		{
			Node* new_node = new Node(val);
			if (prev)
			{
				prev->next = new_node;

			}
			prev = new_node;
			if (!head)
			{
				head = new_node;
			}
		}
		if (prev)
		{
			prev->next = head;
		}
	}

	bool Circular_linked_list::is_empty()
	{
		return (head->next == head->next);
	}

	void Circular_linked_list::print()
	{
		std::cout << head->data << std::endl;
		Node* next_node = head->next;
		while (next_node->next != head)
		{
			std::cout << next_node->data << std::endl;
			next_node = next_node->next;
		}
	}

	void Circular_linked_list::check_index(int index)
	{
		if (index < 0 || index > range_list())
		{
			throw std::out_of_range("Индекс находится за границей массива!");
		}
	}

	void Circular_linked_list::remove_first()
	{
		Node* current = head;
		Node* last = nullptr;
		for (int i = 0; i <= range_list(); i++)
		{
			if (current->next == head)
			{
				last = current;
			}
			current = current->next;
		}
		last->next = head->next;
		delete head;
	}

	void Circular_linked_list::remove_last() 
	{

	}

	void Circular_linked_list::remove(int data)
	{
		check_index(data);
		if (data == 0) 
		{
			remove_first();
		}
		else
		{

		}

	}

	int Circular_linked_list::range_list()
	{
		int count = 0;
		Node* next_node = head;
		while (next_node->next != head)
		{
			count += 1;
			next_node = next_node->next;
		}
		return count;
	}

	Node* Circular_linked_list::find_element(int data)
	{
		if (head->data == data)
		{
			return head;
		}
		Node* next_node = head->next;
		for (int i = 1; i <= range_list(); i++)
		{
			if (next_node->data == data)
			{
				return next_node;
			}
			next_node = next_node->next;
		}
		return nullptr;
	}

	Circular_linked_list::~Circular_linked_list()
	{
		Node* current = head;
		Node* next = nullptr;

		do
		{
			next = current->next;
			delete current;
			current = next;
		} while (current != head);
	}
}