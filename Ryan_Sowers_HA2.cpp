// ----------------------------------------------------------------
// Written by: Ryan Sowers
// Last edited on: November 29, 2017
// File name: Ryan_Sowers_HA2.cpp
// Description: this file creates objects of the type 'btree'.
//	These objects are binary trees that contain key and data-value
//	pairs. A variety of functions are then called on these trees 
//	to find the smallest key, largest key, and the average of the 
//	data. A visualiztion of the trees is also printed for the user.
// Designed on MacOS.
// ----------------------------------------------------------------
#include <iostream>
#include <cstdlib>		//for rand() use
using namespace std;

#include "Ryan_Sowers_binary_tree.h"

//------------------------------

int main(){
	btree a;
	btree b;	
	btree c;
	btree d;	
	btree e;
	
	//create a random tree
	for(int i=0; i<8; i++){
        // insert random key and random data
		a.insert(rand()%100, rand()%100);
	};

	//create a tree with one node
	c.insert(3, 50);	

	// create a tree with keys in acending order
	for(int j=0; j<8; j++){
        // insert keys and random data
		d.insert(j, rand()%100);
	};

	// create a tree with keys in descending order
	for(int k=8; k>0; k--){
        // insert keys and random data
		e.insert(k, rand()%100);
	};

	
	cout << endl << "Random tree:" << endl;	
	a.print();	// random tree
	cout << "Smallest key is: " << a.smallest_key() << endl;
	cout << "Largest key is: " << a.largest_key() << endl;
	cout << "Average of data is: " << a.average_data() << endl << endl;
	a.print_vis();

	cout << endl << "Empty tree:" << endl;	
	b.print();	// empty tree
	cout << "Smallest key is: " << b.smallest_key() << endl;
	cout << "Largest key is: " << b.largest_key() << endl;
	cout << "Average of data is: " << b.average_data() << endl << endl;
	b.print_vis();

	cout << endl << "Single node tree:" << endl;	
	c.print();	// one node
	cout << "Smallest key is: " << c.smallest_key() << endl;
	cout << "Largest key is: " << c.largest_key() << endl;
	cout << "Average of data is: " << c.average_data() << endl << endl;
	c.print_vis();

	cout << endl << "Tree with ascending keys:" << endl;	
	d.print();	// ascending keys
	cout << "Smallest key is: " << d.smallest_key() << endl;
	cout << "Largest key is: " << d.largest_key() << endl;
	cout << "Average of data is: " << d.average_data() << endl << endl;
	d.print_vis();

	cout << endl << "Tree with descending keys:" << endl;	
	e.print();	// descending keys
	cout << "Smallest key is: " << e.smallest_key() << endl;
	cout << "Largest key is: " << e.largest_key() << endl;
	cout << "Average of data is: " << e.average_data() << endl << endl;
	e.print_vis();

	
	return 0;
}
