/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:40:32 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/06 17:03:21 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Topic 3: Container Adapters and Protected Members (For Ex02: Mutated abomination)
Exercise 02 requires you to make std::stack iterable by creating a MutantStack class. 
By default, std::stack intentionally hides iterators to enforce LIFO (Last-In-First-Out) behavior.

Concepts to Research:
Container Adapters: Understanding how std::stack wraps an underlying container (like std::deque by default).
The c Protected Member: std::stack has a protected member variable named c which is the actual 
underlying container. Inheriting from std::stack allows you to access c.
Type Aliasing (using vs. typedef): How to expose the iterators of the underlying container using 
modern C++ using declarations (e.g., using iterator = typename std::stack<T>::container_type::iterator;).

Resources:
cppreference: std::stack https://en.cppreference.com/w/cpp/container/stack
StackOverflow: How to iterate over a std::stack? 
(This thread discusses the exact "hack" needed for this exercise). 
https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators
LearnCpp: Type aliases https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
*/

#include "MutantStack.h"
#include <iostream>
#include <list>
#include <string>

int	main() {
	{
		std::cout << "\tSUBJECT TEST\n";
		MutantStack<int>	mstack;
	
		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << "\n";

		mstack.pop();

		std::cout << mstack.size() << "\n\n";

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}

		std::stack<int> s(mstack);
	}
	{
		std::cout << "\n\n\tLIST FOR COMPARISON (should be the same as above)\n";

		std::list<int>	list;
		
		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << "\n";	//.back() is the closest equivalent to .top()

		list.pop_back();

		std::cout << list.size() << "\n\n";

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		//[...]
		list.push_back(0);

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << "\n";
			++it;
		}
	}
	{
		std::cout << "\n\n\tSTRING OBJECTS & ALL ITERATORS\n";

		MutantStack<std::string>	s;
		std::cout << "Building a mutant-stack of three strings and printing it using mutant-stack iterators:\n";
		for (int i = 0; i < 3; ++i) {
			s.push("String nbr " + std::to_string(i));
		}
		MutantStack<std::string>::iterator 				it = s.begin();
		MutantStack<std::string>::iterator 				ite = s.end();
		MutantStack<std::string>::rev_iterator 			rit = s.rbegin();
		MutantStack<std::string>::rev_iterator			rite = s.rend();
		MutantStack<std::string>::const_iterator 		cit = s.cbegin();
		MutantStack<std::string>::const_iterator 		cite = s.cend();
		MutantStack<std::string>::const_rev_iterator 	crit = s.crbegin();
		MutantStack<std::string>::const_rev_iterator 	crite = s.crend();
		{
			std::cout << "Forward iterator:	'";
			while (it != ite) {
				std::cout << *it << "', ";
				++it;
			}
			std::cout << "\n";
		}
		{
			std::cout << "Reverse iterator:	'";
			while (rit != rite) {
				std::cout << *rit << "', ";
				++rit;
			}
			std::cout << "\n";
		}
		{
			std::cout << "Forward const iter:	'";
			while (cit != cite) {
				std::cout << *cit << "', ";
				++cit;
			}
			std::cout << "\n";
		}
		{
			std::cout << "Reverse const iter:	'";
			while (crit != crite) {
				std::cout << *crit << "', ";
				++crit;
			}
			std::cout << "\n";
		}
	}
	std::cout << std::endl;

	return 0;
}