#include "Node.h"
#include <initializer_list>
namespace rut::miit::llist
{
	class Circular_linked_list
	{
	private:
		/**
		* @brief "голова" списка
		*/
		Node* head;
	public:
		Circular_linked_list(const std::initializer_list<int>& values);

		bool is_empty();

		void print();

		Node* find_element(int data);

		Node* operator[](const int index);

		void remove_first();

		void remove_last();

		void remove(int data);

		void modify(int index, int data);

		~Circular_linked_list();
	};

}

