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
		Circular_linked_list();

		Circular_linked_list(const std::initializer_list<int>& values);

		std::string print();

		void check_index(int index);

		int range_list();

		Node* find_element(int data);

		void insert(int data);

		void remove(int data);

		bool modify(int index, int data);

		friend std::ostream& operator<<(std::ostream& os, const Circular_linked_list list);

		~Circular_linked_list();
	};

}

