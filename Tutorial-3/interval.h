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
};

// If class Interval is not defined then define its prototype

#ifndef INTERVAL_H
#define INTERVAL_H

// The class for Interval Tree along with all the operations
class Interval
{


};

#endif