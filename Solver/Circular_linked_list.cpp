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