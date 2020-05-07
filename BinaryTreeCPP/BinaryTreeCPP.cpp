#include "BT.h"
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{

	BT <int> root(15);
	for (int i = 0; i < 100; ++i) {
		root.add_node(getRandomNumber(1, 20));
	}
	cout << "Before deleting an element :" << endl;
	root.full_print();
	cout << "After deleting an element :" << endl;
	root.delete_node(4);
	root.full_print();
	cout << "Leaves :" << endl;
	root.leaves_print();
	cout << "Element search: " << endl;
	BT <int> node = root.search(15);
	cout << "Data: " << node.get_data() << endl;
	cout << "Parent: " << node.get_parent() << endl;
	cout << "Left child: " << node.get_left() << endl;
	cout << "Right child: " << node.get_right() << endl;
	cout << "Traverse: " << endl;
	root.traverse();
}