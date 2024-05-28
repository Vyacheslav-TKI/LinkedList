#include <iostream>
#include "..\Solver\Circular_linked_list.h"
#include "..\Solver\Node.h"

/**
* @brief Точка входа в программу
* @return 0 Программа выполнена успешно
*/

int main()
{
	rut::miit::llist::Circular_linked_list list = { 1, 2, 3, 4 };

	list.insert(5);
	list.remove(3);

	std::cout << list << std::endl;

	return 0;
}