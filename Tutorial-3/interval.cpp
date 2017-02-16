/*
 *
 * interval.cpp
 */

#include <iostream>
#include <utility>

// Include the prototype of the Interval Tree class
#include "interval.h"

using namespace std;

#define INF 1000000000

// Definition of the functions of Interval Class

// Constructor
Interval::Interval()
{
	root = NULL;
}

// Insert an interval
void Interval::insert(int l, int r)
{
	root = this->insert_helper(root, l, r);
	return;
}

// Recursively traverse and insert an interval
node * Interval::insert_helper(node *current, int l, int r)
{
	if (current == NULL)
        return new node(l, r);
 
    if (l < current->r.first)
        current->left = insert_helper(current->left, l, r);
 
    else
        current->right = insert_helper(current->right, l, r);
 
    if (current->max_right < r)
        current->max_right = r;
 
    return current;
}

// Search for an interval
range Interval::search(int l, int r)
{
	return this->search_helper(root, l, r);
}

// Recursively traverse and search for an interval
range Interval::search_helper(node *current, int l, int r)
{
	if(current == NULL)
	{
		return range(INF, INF);
	}

	if(current->overlap(l, r))
	{
		return current->r;
	}

	if(current->left != NULL && current->left->max_right >= l)
		return this->search_helper(current->left, l, r);

	return this->search_helper(current->right, l, r);
}

// Remove an interval
void Interval::remove(int l, int r)
{
	root = this->remove_helper(root, l, r);
}

// Recursively search and remove that interval
node * Interval::remove_helper(node *current, int l, int r)
{
	if(current == NULL) return NULL;


	if(current->r.first > l)
	{
		current->left = this->remove_helper(current->left, l, r);
	}

	else if(current->r.first < l)
	{
		current->right = this->remove_helper(current->right, l, r);
	}

	else
	{
		// If only 1 or 0 child
		if(current->left == NULL)
		{
			node * temp = current->right;
			delete current;
			return temp;
		}

		else if(current->right == NULL)
		{
			node * temp = current->left;
			delete current;
			return temp;
		}
		// Left most node in the right subtree should replace this node
		node * temp = current->right;
		while(temp->left != NULL)
		{
			temp = temp->left;
		}

		// Remove the replaced node
		current->r = temp->r;
		current->right = this->remove_helper(current->right, l, r);
	}

	// Update max_right in this subtree
	current = update_max(current);
	return current;
}


// Helper Function
node * Interval::update_max(node *current)
{
	if(current == NULL) return NULL;

	this->update_max(current->left);
	this->update_max(current->right);

	if(current->right != NULL)
	{
		if(current->left != NULL)
		{
			current->max_right = max(current->r.second, max(current->left->max_right, current->right->max_right));
		}
		else
		{
			current->max_right = max(current->r.second, current->right->max_right);
		}
	}
	else
	{
		if(current->left != NULL)
		{
			current->max_right = max(current->r.second, current->left->max_right);
		}
		else
		{
			current->max_right = current->r.second;
		}
	}

	return current;
}

int main()
{
	//Code
	Interval tree;

	// Insert some dummy intervals
	tree.insert(5, 6);
	tree.insert(5, 10);
	tree.insert(1, 6);
	tree.insert(15, 20);
	tree.insert(0, 2);

	// Search for an interval
	range r = tree.search(5,6);
	cout << r.first << " " << r.second << endl;

	// Remove an interval 
	tree.remove(5,6);

	// Search for the removed interval
	r = tree.search(5,6);
	cout << r.first << " " << r.second << endl;



	return 0;
}