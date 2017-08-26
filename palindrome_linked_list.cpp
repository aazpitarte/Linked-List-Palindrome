#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// basic linked list class
class linkedList {
public:

	class node {
	public:
		char val;
		node * next;
		
		node ( char c ) {
			val = c;
			next = NULL;
		}

	};
	
	node * head;

	linkedList() {
		head = NULL;
	}

	node * add( node * prev, char c ) {
		
		node * new_node = new node( c );
		
		if ( prev != NULL ) {
			prev->next = new_node;
		}
		else {
			head = new_node;
		}
		
		return new_node;
	}
	
	// make linked list out of string
	make_list( string input ) {
		
		node * temp = head;
		
		for ( char c : input ) {
			temp = add( temp, c );
		}
	}

	// print out linked list 	
	void show( linkedList * test ) {
		
		node * i = test->head;

		while( i != NULL ) {
			cout << i->val << endl;
			i = i->next;
		}

	}

	// check if linked list is palindrome
	bool is_palindrome( linkedList * h ) {
	
		if ( h == NULL )
			throw h;

		node * p = h->head; // for iterating through list
		node * mid_point = h->head;
		int twice = 0; // will always be half the size of the list iteration
		
		stack<char> half_list;
		
		// find middle of linked list,
		// add half of the list to a stack
		while ( p != NULL ) {

			if ( twice % 2 == 0)
				half_list.push( mid_point->val );
			else 
				mid_point = mid_point->next;

			p = p->next;
			twice++;
		}
		
		// compare second half of list to stack
		while( mid_point != NULL ) {

			if ( mid_point->val != half_list.top() )
				return false;
			mid_point = mid_point->next;
			half_list.pop();
		}

		return true;
	}
};

TEST_CASE( "Null and empty input" ) {
	linkedList l;
	try {
		l.is_palindrome( NULL );
	}
	catch ( ... ) {
		cerr << "Null Exception\n";
	}

	l.make_list( "" );
	
	REQUIRE( l.is_palindrome( &l ) == true );
}



TEST_CASE( "single input and special characters" ) {
	linkedList l1, l2, l3;
	l1.make_list( "a" );
	l2.make_list( "#" );
	l3.make_list( "!@$%$@!" );
	
	REQUIRE( l1.is_palindrome( &l1 ) == true );
	REQUIRE( l2.is_palindrome( &l2 ) == true );
	REQUIRE( l3.is_palindrome( &l3 ) == true );
}

TEST_CASE( "not a palindrome" ) {
	linkedList l1, l2, l3;
	l1.make_list( "abcdef" );
	l2.make_list( "qwerty" );
	l3.make_list( "helloworld!" );
	
	REQUIRE( l1.is_palindrome( &l1 ) == false );
	REQUIRE( l2.is_palindrome( &l2 ) == false );
	REQUIRE( l3.is_palindrome( &l3 ) == false );
}

TEST_CASE( "ARE palindromes" ) {
	linkedList l1, l2, l3;
	l1.make_list( "abcdef" );
	l2.make_list( "qwerty" );
	l3.make_list( "helloworld!" );
	
	REQUIRE( l1.is_palindrome( &l1 ) == false );
	REQUIRE( l2.is_palindrome( &l2 ) == false );
	REQUIRE( l3.is_palindrome( &l3 ) == false );
}
