#include "Node.h"
#include "Circular_linked_list.h"
#include <initializer_list>
#include <sstream>

namespace rut::miit::llist 
{
	Circular_linked_list::Circular_linked_list() : head(nullptr) {}

	Circular_linked_list::Circular_linked_list(const std::initializer_list<int>& values)
	{
		for (auto& val : values)
		{
			insert(val);
		}
	}

	std::string Circular_linked_list::print()
	{
		std::stringstream ss;
		Node* temp = head;
		if (head != nullptr)
		{
			do
			{
				ss << temp->data << " ";
				temp = temp->next;
			} while (temp != head);
		}
		return ss.str();
	}

	std::ostream& operator << (std::ostream& os, const Circular_linked_list& list)
	{
		os << list.print();
		return os;
	}

	bool Circular_linked_list::is_valid_index(size_t index)
	{
		if (index > range_list())
		{
			return false;
		}
		return true;
	}


	void Circular_linked_list::remove(int data)
	{
		if (!is_valid_index)
		{
			throw std::logic_error("wrong index!");
		}
		if (head == nullptr) 
		{
			return;
		}

		Node* temp = head;
		Node* prev = nullptr;

		do
		{
			if (temp->data == data)
			{
				if (temp == head)
				{
					head = head->next;
				}
				if (prev != nullptr)
				{
					prev->next = temp->next;
				}
				delete temp;
				return;
			}
			prev = temp;
			temp = temp->next;
		} while (temp != head);
	}

	int Circular_linked_list::find_element(int data)
	{
		if (head->data == data)
		{
			return 0;
		}
		Node* next_node = head->next;
		for (int i = 1; i <= range_list(); i++)
		{
			if (next_node->data == data)
			{
				return i;
			}
			next_node = next_node->next;
		}
		return -1;
	}

	Node* Circular_linked_list::find_element_ptr(int data)
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

	bool Circular_linked_list::modify(int index, int data)
	{
		if (!is_valid_index)
		{
			throw std::logic_error("wrong index!");
		}

		Node* node_mod = find_element_ptr(index);

		if (node_mod != nullptr)
		{
			node_mod->data = data;
			return true;
		}
		else
		{
			return false;
		}
	}

	Circular_linked_list::Circular_linked_list(Circular_linked_list&& other) noexcept
	{
		head = other.head;
		other.head = nullptr;
	}

	Circular_linked_list& Circular_linked_list::operator=(const Circular_linked_list& other)
	{
		Circular_linked_list temp(other);
		std::swap(this->head, temp.head);
		return *this;
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