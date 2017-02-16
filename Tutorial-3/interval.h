/**
 *
 * response.h
 */

#include <utility>	// To use pair<int,int>

// STL Template to hold a pair of integers
typedef pair<int,int> range;

// Structure of the node of an Interval Tree
struct node {
	// The interval range that the node holds
	range r;

	// The maximum 'right' value of a range in the subtree rooted at this node
	int max_right;
	
	// Pointer to left and right children
	node *left;
	node *right;

	// Constructor of the node structure
	node(int l, int r)
	{
		r = range(l, r);
		max_right = r;

		left = right = NULL;
	}
};

// If class Interval is not defined then define its prototype

#ifndef INTERVAL_H
#define INTERVAL_H

// The class for Interval Tree along with all the operations
class Interval
{
	private:
		node *root;

	public:
		// Constructor
		Interval();

		// Insert a range
		void insert(int, int);

		// Function called by insert() to recursively traverse and insert a range
		void insert_helper(node *, int, int);

		// Search for a range
		range search(int, int);

		// Function called by search() to search for a range
		range search_helper(node *, int, int);

		// Remove a range
		void remove(int, int);

		// Helper function to remove a range
		void remove_helper(node *, int, int);

};

#endif