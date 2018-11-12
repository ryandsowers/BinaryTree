// ----------------------------------------------------------------
// Written by: Ryan Sowers
// Last edited on: November 29, 2017
// File name: Ryan_Sowers_binary_tree.h
// Description: this file contains information necessary to create
//	objects of the specified class type. This class also comes with
//	functions that can be used to access various data elements of 
//	the objects. These objects are binary trees that contain key 
//	and data-value pairs. Some of the functions can be used to find 
//	the smallest key, largest key, and the average of the data.
// Designed on MacOS.
// ----------------------------------------------------------------

struct node
{
    int key_value;
    int data;
    node *left;
    node *right;
};

//---------------------------------------
class btree
{
	node *root;
	int	 total; // total number of stored keys
	double avg_data; //***** my update **** sum of data to be averaged 
	
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf, int val);
	int  search(int key, node *leaf);
	void print_tree(node * t);
	node *copy_tree(node * t);
	void delete_(node * & tree, int item);
	void delete_node(node * & tree);
	void get_predecessor(node * tree, int & k, int & d);
    void print_vis(int depth, node * t);
    //***** my update ****
    double get_average(node * tempppp);

public:
	btree();
	btree(const btree &t);
	~btree();
	void insert(int key, int val);
	int  search(int key); // returns data associated with the key
						  // or -1 if not found
	void print();
	int  size();
	void delete_item(int item);
	void destroy_tree();
    void print_vis();
    //***** my update ****
    int smallest_key();
    int largest_key();
    double average_data();
};

//--------- definitions ------------
// normal constructor
btree::btree()
{
  root	= NULL;
  total = 0;
  avg_data = 0;
}

// copy constructor
btree::btree(const btree &t){
	root  = copy_tree(t.root);
	total = t.total;
	avg_data = t.avg_data;
}

// destructor
btree::~btree()
{
  destroy_tree();
}

void btree::destroy_tree()
{
	destroy_tree(root);
    root  = NULL;
    total = 0;
    avg_data = 0;
}

void btree::destroy_tree(node *leaf)
{
  if(leaf!=NULL)
  {
    destroy_tree(leaf->left);
    destroy_tree(leaf->right);
    delete leaf;
  }
}

void btree::insert(int key, node *leaf, int val)

{ if(key == leaf-> key_value){
    // the key already exists
	leaf-> data = val;  // update the data
	return;
  }
  if(key < leaf->key_value)
  {
    if(leaf->left!=NULL)
     insert(key, leaf->left, val);
    else
    {
      leaf->left=	new node;
      leaf->left->key_value	= key;
	  leaf->left->data		= val;
      leaf->left->left		= NULL; //Sets the left child of the node to null
      leaf->left->right		= NULL; //Sets the right child of the node to null
	  ++total;
    }  
  }
  else if(key > leaf->key_value)
  {
    if(leaf->right!=NULL)
      insert(key, leaf->right, val);
    else
    {
      leaf->right=	new node;
      leaf->right->key_value  = key;
	  leaf->right->data		  = val;
      leaf->right->left		  = NULL; //Sets the left child of the node to null
      leaf->right->right	  = NULL; //Sets the right child of the node to null
	  ++total;
    }
  }
}

int btree::search(int key, node *leaf)
{
  if(leaf!=NULL)
  {
    if(key == leaf->key_value)
      return leaf->data;
    if(key < leaf->key_value)
      return search(key, leaf->left);
    else
      return search(key, leaf->right);
  }
  else return -1;
}

void btree::insert(int key, int val)
{
  if(root!=NULL)
    insert(key, root, val);
  else
  {
    root =	new node;
    root-> key_value	= key;
	root-> data			= val;
    root-> left			= NULL;
    root-> right		= NULL;
	++total;
  }
}

int btree::search(int key)
{
  return search(key, root);
}

void btree::print_tree(node * t)
{
	if ( t != NULL ) {  // (Otherwise, there's nothing to print.)
		print_tree(t->left);			// Print items in left subtree.
		cout << "(key= "<< t->key_value << ", data= " << 
			    t-> data << ")\n"; // Print the root item.

		print_tree( t->right );			// Print items in right subtree.
	}
}

node * btree::copy_tree(node * t){
	
	if(!t) return NULL;
	
	node * p = new node;
	p-> key_value = t-> key_value;
	p-> data	  = t-> data;
	p-> left  = copy_tree(t-> left);
	p-> right = copy_tree(t-> right);
	return p;
}

void btree::print()
{
	cout<< "tree with "<< total << " nodes:\n";
	print_tree(root);
	cout<< endl;
}

int btree::size()
{
	return total;
}

void btree::delete_item(int item){
	delete_(root, item);
}

void btree::delete_(node * & tree, int item){
	
	if(!tree) return;// item was not found
	
	if (item < tree-> key_value)
		delete_(tree->left, item);   // Look in left subtree.
	else if (item > tree-> key_value)
		delete_(tree->right, item);  // Look in right subtree.
	else 
		delete_node(tree);           // node found; call delete_node()
}

void btree::delete_node(node * & tree){
	// Deletes the node pointed to by tree.
	// The user's data in the node pointed to by tree is no 
	// longer in the tree.  If tree is a leaf node or has only one
	// non-NULL child pointer the node pointed to by tree is 
	// deleted; otherwise, the key_value is replaced by its 
	// logical predecessor and the predecessor's node is deleted.
	{
	int k, d;
	node * tempPtr;
		
	tempPtr = tree;
	if (tree->left == NULL)
		{
			tree = tree->right;
			delete tempPtr;
			--total;
		}
	else if (tree->right == NULL)
		{
			tree = tree->left;
			delete tempPtr;
			--total;
		}
	else // tree has two children
		{
			get_predecessor(tree->left, k, d);
			tree-> key_value = k;
			tree-> data		 = d;
			delete_(tree->left, k);  // Delete predecessor node
		}
	}
}

void btree::get_predecessor(node * tree, int & k, int & d){
	// Sets data to the data member of the right-most node in tree.
	while (tree->right != NULL)
		tree = tree->right;
	k = tree->key_value;
	d = tree->data;
}

void btree::print_vis(){
    print_vis(0, root);
}

void btree::print_vis(int depth, node * t)
{
    if ( t != NULL ) {  // (Otherwise, there's nothing to print.)
        for(int i=0; i<depth;i++) cout<< ' ';
        cout << t->key_value << " \n";	// Print the root item.
        print_vis(depth+2, t->left);			// Print items in left subtree.
        print_vis(depth+2, t->right );			// Print items in right subtree.
    } 
    else {for(int i=0; i<depth;i++) cout<< ' ';
        cout<<"NULL\n";}
}

//***** my update ****
int btree::smallest_key()
{
	node * tempp;
	tempp = root;
	if (root != NULL)
	{	
		// Sets data to the data member of the left-most or least node in tree.
		while (tempp->left != NULL)
			tempp = tempp->left;

		return tempp->key_value;
	} 
	else return 0;	
}

int btree::largest_key()
{
	node * temppp;
	temppp = root;
	if (root != NULL)
	{
		// Sets data to the data member of the right-most or greatest node in tree.
		while (temppp->right != NULL)
			temppp = temppp->right;

		return temppp->key_value;
	} 
	else return 0;	
}

double btree::get_average(node * tempppp)
{
	if ( tempppp != NULL ) {  // Ensure the next branch is not empty
		avg_data += tempppp->data;
		get_average(tempppp->left);	// Add data in left subtree.

		get_average( tempppp->right );	// Add data in right subtree.
	}
	return avg_data/total;
}

double btree::average_data()
{	// used to collect data average from root
	if (root != NULL)
	{
		return get_average(root);
	}
	else return 0;
}















