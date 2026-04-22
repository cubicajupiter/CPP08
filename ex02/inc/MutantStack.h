/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:40:38 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/21 12:54:00 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	private:
		using std::stack<T>::c;
	public:
		using container 			= typename std::stack<T>::container_type;

		using iterator				= typename container::iterator;
		using rev_iterator			= typename container::reverse_iterator;
		using const_iterator		= typename container::const_iterator;
		using const_rev_iterator	= typename container::const_reverse_iterator;


		//CONSTRUCTOR
		MutantStack() : std::stack<T>() {}

		//COPY CONSTRUCTOR
		MutantStack(const MutantStack& other) : std::stack<T>(other) {}

		//DESTRUCTOR
		~MutantStack() {}

		//COPY ASSIGNMENT OPERATOR OVERLOAD
		MutantStack&	operator=(const MutantStack& other) {
			if (this != &other) {
				std::stack<T>::operator=(other);
			}
			return *this;
		}


		//ACCESS TO ALL THE ITERATORS OF DEQUE
		iterator	begin() {
			return c.begin();
		}

		iterator	end() {
			return c.end();
		}

		rev_iterator	rbegin() {
			return c.rbegin();
		}

		rev_iterator	rend() {
			return c.rend();
		}

		const_iterator	cbegin() {
			return c.cbegin();
		}

		const_iterator	cend() {
			return c.cend();
		}

		const_rev_iterator	crbegin() {
			return c.crbegin();
		}

		const_rev_iterator	crend() {
			return c.crend();
		}

};