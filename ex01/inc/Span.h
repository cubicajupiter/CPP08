/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 15:53:27 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/06 16:48:46 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <stdexcept>

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
		unsigned				getCurrentI() const;
		void					printContent() const;

		
		template <typename InIter>
		void		addRange(InIter first, InIter end) {
			while (first != end && current_i_ < N_) {
				data_.push_back(*first);
				current_i_++;
				++first;
			}
			if (current_i_ >= N_  && first != end)
				throw std::out_of_range("Cannot add any more numbers!");
		}
};