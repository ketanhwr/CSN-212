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

Interval::Interval()
{
	root = NULL;
}

void Interval::insert(int l, int r)
{
	node *temp = this->insert_helper(root, l, r);
	return;
}

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

range Interval::search(int l, int r)
{
	return this->search_helper(root, l, r);
}

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

void Interval::remove(int l, int r)
{
	node *temp = this->remove_helper(root, l, r);
}

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
		if(current->left == NULL)
		{
			node * temp = current->right;
			delete current;
			return temp;
		}

		else if(current->right = NULL)
		{
			node * temp = current->left;
			delete current;
			return temp;
		}

		node * temp = current->right;
		while(temp->left != NULL)
		{
			temp = temp->left;
		}

		current->r = temp->r;
		current->right = this->remove_helper(current->right, l, r);
	}

	current = update_max(current);
	return current;
}

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

	tree.insert(5, 6);
	tree.insert(5, 10);
	tree.insert(1, 6);
	tree.insert(15, 20);
	tree.insert(0, 2);

	range r = tree.search(1,10);
	cout << r.first << " " << r.second << endl;

	tree.remove(1,10);

	r = tree.search(1,10);
	cout << r.first << " " << r.second << endl;

	return 0;
}