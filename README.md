# 🙌Breadth First Search Algorithm Implementation
Implementation of breadth first search algorithm on binary tree in C++. It makes use of the queue to implement the algorithm. It was a lab task. The primary purpose was implementation of Breadth First Search Algorithm. It returns the path of the tree to be traversed in breadth first manner, in order to reach the desired key.

# 🎋 Binary Tree
Binary makes use of the following structure:

```
struct node {
	int key_value;
	node *left;
	node *right;
};

```
Project contains the implementation of following functions in binary tree:
* Breadth First Search (Returns Path)
* Search (Returns Index)
* Insert
* Memory Management (Destructor)

For this project, I have hard coded the values of the tree.
``` 
  btree newTree;
	newTree.insert(2);
	newTree.insert(1);
	newTree.insert(8);
	newTree.insert(4);
	newTree.insert(5);
	newTree.insert(3);
	newTree.insert(10);
  ```
  It can be extended to take input in any desired way.
  
  # 🍹 Breadth First Search Algorithm
  Breadth First Search Algorithm first of all pushes the root node into stack and then recursively performs the following steps until queue is not empty.
  1. Pop the first item of queue
  1. Checks if the value node is equal to required key (If yes, stops. Else prints and move on to step 2).
  3. Prints the node
  2. Pops out the node
  3. Push the child of the node
 
  Its implementation in C++ looks like this:
  ```
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
  ```
  
  
