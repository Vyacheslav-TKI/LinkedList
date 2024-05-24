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

		void check_index(int index);

		int range_list();

		Node* find_element(int data);

		void remove_last();

		void remove_first();

		void remove(int data);

		void modify(int index, int data);

		~Circular_linked_list();
	};

}

