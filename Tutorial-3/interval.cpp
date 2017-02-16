/*
 *
 * interval.cpp
 */

#include <iostream>

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

}

void Interval::insert_helper(node *current, int l, int r)
{

}

range Interval::search(int l, int r)
{
	return this->search_helper(root, int l, int r);
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

}

void Interval::remove_helper(node *current, int l, int r)
{

}

int main()
{
	//Code


	return 0;
}