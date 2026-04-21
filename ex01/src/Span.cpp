/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:06:32 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/20 17:47:21 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"

//DEFAULT CONSTRUCTOR
Span::Span() : N_(0), current_i_(0) {}

//PARAMETER CONSTRUCTOR
Span::Span(unsigned N) : N_(N), current_i_(0) {
	data_ = std::vector<int>(N);
	std::fill(data_.begin(), data_.end(), 0);
}

//COPY CONSTRUCTOR
Span::Span(const Span& other) : current_i_(0) {
	N_ = other.getN();
	data_ = std::vector<int>(N_);
	std::vector<int> other_data = other.getData();
	std::copy(other_data.begin(), other_data.end(), data_.begin());
}

//DESTRUCTOR
Span::~Span() {}

//ASSIGNMENT OPERATOR OVERLOAD
Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		N_ = other.getN();
		current_i_ = 0;
		data_ = std::vector<int>(N_);
		std::vector<int> other_data = other.getData();
		std::copy(other_data.begin(), other_data.end(), data_.begin());
	}
	return *this;
}



//SUBJECT METHODS
void	Span::addNumber(int number) {
	if (current_i_ >= N_)
		throw std::out_of_range("Cannot add any more numbers!");
	data_[current_i_++] = number;
}

unsigned	Span::shortestSpan() {
	std::vector<int>	output(current_i_);

	if (current_i_ < 2)
		throw std::logic_error("Need at least two values for a comparison.");
	std::sort(data_.begin(), data_.end());
	std::adjacent_difference(data_.begin(), data_.end(), output.begin());
	return *std::min_element(output.begin(), output.end());
}

unsigned	Span::longestSpan() const {
	if (current_i_ < 2)
		throw std::logic_error("Need at least two values for a comparison.");
	int max = *std::max_element(data_.begin(), data_.end());
	int min = *std::min_element(data_.begin(), data_.end());
	return max - min;
}



//GETTERS
unsigned	Span::getN() const {
	return N_;
}

const std::vector<int>&	Span::getData() const {
	return data_;
}
