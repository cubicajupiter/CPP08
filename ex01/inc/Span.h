/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:53:27 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/20 17:47:22 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>

#include <iostream>

class Span {
	private:
		unsigned			N_;
		unsigned			current_i_;
		std::vector<int>	data_;
	public:
		Span();
		Span(unsigned N);
		Span(const Span& other);
		~Span();
		Span&	operator=(const Span& other);

		void		addNumber(int number);
		unsigned	shortestSpan();
		unsigned	longestSpan() const;

		unsigned				getN() const;
		const std::vector<int>&	getData() const;

		
		template <typename InIter>
		void		addRange(InIter first, InIter end) {
			while (first != end && current_i_ < N_) {
				data_[current_i_++] = *first;
				++first;
			}
			if (current_i_ >= N_  && first != end)
				throw std::out_of_range("Cannot add any more numbers!");
		}
};