#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;

struct node {
	int key_value;
	node *left;
	node *right;
};

/*
* Class Declaration
*/
class btree {
public:
	btree();
	~btree();

	void insert(int key);
	node *search(int key);
    void destroy_tree();
    void bfs(node*, int);
	node *root; // keeping it public so I don't have to implement getter/setter

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	node *search(int key, node *leaf);
};



int main() {

	btree newTree;
	newTree.insert(2);
	newTree.insert(1);
	newTree.insert(8);
	newTree.insert(4);
	newTree.insert(5);
	newTree.insert(3);
	newTree.insert(10);
	newTree.bfs(newTree.root, 7);
	return 0;
}


void btree:: bfs(node* head, int key) {
	queue<node*> qu;
	if (head != NULL) {
		qu.push(head);
		while (!qu.empty()) {
			node* t = qu.front();
			if ( t->key_value == key ) break;
			cout << t->key_value << "\t";
			//path.insert(t->key_value);
			qu.pop();
			if (t->left != NULL) {
				qu.push( t->left );
			}
			if (t->right != NULL) {
				qu.push(t->right);
			}
		}
	}
}


btree::btree() {
	root = NULL;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node *leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf) {
	if (key< leaf->key_value) {
		if (leaf->left != NULL) {
            insert(key, leaf->left);
        } else {
			leaf->left = new node;
			leaf->left->key_value = key;
			leaf->left->left = NULL;    //Sets the left child of the child node to null
			leaf->left->right = NULL;   //Sets the right child of the child node to null

		}
	} else if (key >= leaf->key_value) {
		if (leaf->right != NULL) {
            insert(key, leaf->right);
        } else {
			leaf->right = new node;
			leaf->right->key_value = key;
			leaf->right->left = NULL;  //Sets the left child of the child node to null
			leaf->right->right = NULL; //Sets the right child of the child node to null
		}
	}
}


node *btree::search(int key, node *leaf) {
	if (leaf != NULL) {
		if (key == leaf->key_value)
			return leaf;
		if (key<leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
    else 
        return NULL;
}

void btree::insert(int key) {
	if (root != NULL)
		insert(key, root);
	else {
		root = new node;
		root->key_value = key;
		root->left = NULL;
		root->right = NULL;
	}
}


node *btree::search(int key) {
	return search(key, root);
}


void btree::destroy_tree() {
	destroy_tree(root);
}