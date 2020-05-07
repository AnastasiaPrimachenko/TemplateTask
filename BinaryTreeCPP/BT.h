#include <string>
#include <iostream>
using namespace std;
template <typename T>
class BT
{
private:
	T data;
	int level;
	BT* parent;
	BT* left;
	BT* right;
public:
	BT() {
		this->data;
		this->level = 0;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	BT(T d) {
		this->data = d;
		this->level = 0;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	void add_node(T d) { //adding nodes to the binary search tree
		if (this->left == nullptr && this->data > d) {
			this->left = new BT(d);
			this->left->level = this->level + 1;
			this->left->parent = this;
		}
		else if (this->right == nullptr && this->data < d) {
			this->right = new BT(d);
			this->right->level = this->level + 1;
			this->right->parent = this;
		}
		else {
			if (this->data > d) this->left->add_node(d);
			else if (this->data < d) this->right->add_node(d);
		}
	}
	void traverse() { //traversing the tree
		cout << this->data << "  ";
		if (this->left != nullptr)this->left->traverse();
		if (this->right != nullptr)this->right->traverse();
	}
	BT& search(T n) { //searcing for the node with the specific value	
		if (this->data == n) {
			return *this;
		}
		if (this->data > n && this->left!=nullptr) this->left->search(n);
		else if (this->data < n && this->right!=nullptr)this->right->search(n);
		else {
			cout << "This node does not exist" << endl;
		}
	}
	void full_print() { //printing the full tree
		string space = "";
		for (int i = 0; i < this->level; ++i) {
			space += "  ";
		}
		cout << space << this->data << endl;
		if (left != nullptr && right != nullptr) {
			left->full_print();
			right->full_print();
		}
		else if (left == nullptr && right != nullptr) right->full_print();
		else if (left != nullptr && right == nullptr) left->full_print();
		else return;
	}
	void leaves_print() { //prints only leaves
		if (left == nullptr && right == nullptr) {
			cout << this->data << endl;
		}
		if (right != nullptr) right->leaves_print();
		if (left != nullptr) left->leaves_print();
	}
	void delete_node(T data) { //deletes the node
		BT* n = &(this->search(data));
		if (n->data != 258498796) {
			BT* p = n->parent;

			if (n->left == nullptr && n->right == nullptr) { //deleting the leaf
				if (p->left == n) p->left = nullptr;
				else if (p->right == n) p->right = nullptr;
			}
			else if (n->left == nullptr || n->right == nullptr) { //when the element we want to delete has one child
				if (n->left == nullptr)
					if (p->left == n) p->left = n->right;
					else p->right = n->right;
				else
					if (p->left == n) p->left = n->right;
					else p->right = n->right;
			}
			else { //when the element we want to delete has two children
				BT* s = n->right;
				n->data = s->data;
				if (s->parent->left == s) {
					s->parent->left = s->right;
					if (s->right != nullptr) s->right->parent = s->parent;
				}
				else {
					s->parent->right = s->left;
					if (s->left != nullptr) s->right->parent = s->parent;
				}
			}
		}
	}
	T get_parent() {
		if (this->parent != nullptr)return this->parent->data;
	}
	T get_data() {
		return this->data;
	}
	T get_left() {
		if (this->left != nullptr) return this->left->data;
		else return 0;
	}
	T get_right() {
		if (this->right != nullptr)return this->right->data;
		else return 0;
	}
};