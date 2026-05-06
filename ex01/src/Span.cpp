/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:06:32 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/06 16:48:47 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <iostream>
#include <algorithm>

//DEFAULT CONSTRUCTOR
Span::Span() : N_(10), current_i_(0) {}

//PARAMETER CONSTRUCTOR
Span::Span(unsigned N) : N_(N), current_i_(0) {}

//COPY CONSTRUCTOR
Span::Span(const Span& other) : N_(other.getN()), current_i_(other.getCurrentI()) {
	data_ = std::vector<int>(current_i_);
	std::vector<int> other_data = other.getData();
	std::copy(other_data.begin(), other_data.end(), data_.begin());
}

//DESTRUCTOR
Span::~Span() {}

//ASSIGNMENT OPERATOR OVERLOAD
Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		N_ = other.getN();
		current_i_ = other.getCurrentI();
		data_ = std::vector<int>(current_i_);
		std::vector<int> other_data = other.getData();
		std::copy(other_data.begin(), other_data.end(), data_.begin());
	}
	return *this;
}



//SUBJECT METHODS
void	Span::addNumber(int number) {
	if (current_i_ >= N_)
		throw std::out_of_range("Cannot add any more numbers!");
	data_.push_back(number);
	current_i_++;
}

//current_i is two, but vector contains a third value, 0
//sorted, the vector is 0, 2, 7
unsigned	Span::shortestSpan() {
	std::vector<int>	output(current_i_);

	if (current_i_ < 2)
		throw std::logic_error("Need at least two values for a comparison.");
	std::sort(data_.begin(), data_.end());
	std::adjacent_difference(data_.begin(), data_.end(), output.begin());
	return *std::min_element(output.begin() + 1, output.end());
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

unsigned	Span::getCurrentI() const {
	return current_i_;
}

//PRINT DATA_ ITEMS
void	Span::printContent() const {
	std::copy(
		data_.begin(),
		data_.end(),
		std::ostream_iterator<typename std::vector<int>::value_type>(std::cout, " "));
	std::cout << "\n";
}