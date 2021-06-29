template <typename T>
class Node
{
public:
	T data;
	Node* left;
	Node* right;

	Node(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
		//as it might store a garbage value
	}

	~Node() {
		delete left;
		delete right;
	}
};