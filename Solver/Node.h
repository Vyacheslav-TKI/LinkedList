
namespace rut::miit::llist
{
	struct Node
	{
	public:
		/**
		* @brief значение узла
		*/
		int data;

		/**
		* @brief указатель на следующий узел
		*/
		Node* next;
		Node(int number);
	};
}


