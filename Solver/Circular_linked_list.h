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

		/**
		* @brief Проверка валидности индекса
		* @param index индекс
		* @return true индекс валиден
		* @return false индекс невалиден
		*/
		bool is_valid_index(size_t index);

		/**
		* @brief Находит указатель по значению
		*/
		Node* find_element_ptr(int data);

	public:
		/**
		* @brief пустой коструктор
		*/
		Circular_linked_list();

		/**
		* @brief конструктор через initializer_list
		*/
		Circular_linked_list(const std::initializer_list<int>& values);

		/**
		* @brief сериализация массива в строку
		*/
		std::string print();

		/**
		* @brief находит длину списка
		*/
		int range_list();

		/**
		* @brief находит индекс по значению
		*/
		int find_element(int data);

		/**
		* @brief вставка в конец
		*/
		void insert(int data);

		/**
		* @brief удаление с конца
		*/
		void remove(int data);

		/**
		* @brief конструктор перемещения
		*/
		Circular_linked_list(Circular_linked_list&& other) noexcept;

		/**
		* @brief оператор перемещения
		*/
		Circular_linked_list& operator=(const Circular_linked_list& other);

		/**
		* @brief модифицирование элемента по индексу
		*/
		bool modify(int index, int data);

		/**
		* @brief переопределенный оператор
		*/
		friend std::ostream& operator<<(std::ostream& os, const Circular_linked_list list);

		/**
		* @brief деструктор
		*/
		~Circular_linked_list();
	};

}

