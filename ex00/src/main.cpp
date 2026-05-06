/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 10:09:30 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/06 15:45:26 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <array>

template <typename Cont>
static void	printContent(const Cont& container);

int	main() {
	std::vector<int>	int_vec{1, 2, 3, 4, 5};
	std::array<int, 5>	int_arr{10, 30, 20, 4, 50};
	int					result;

	std::cout << "Int vector:\n";
	printContent<std::vector<int>>(int_vec);
	std::cout << "Int array:\n";
	printContent<std::array<int, 5>>(int_arr);


	try {
		result = easyfind(int_vec, 4);
		std::cout << "Found " << result << " in vector!\n\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n\n";
	}
	
	try {
		result = easyfind(int_arr, 20);
		std::cout << "Found " << result << " in array!\n\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n\n";
	}
	
	try {
		result = easyfind(int_vec, 10);
		std::cout << result << "\n\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n\n";
	}

	try {
		result = easyfind(int_arr, -5);
		std::cout << result << "\n\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n\n";
	}
}

template <typename Cont>
static void	printContent(const Cont& container) {
	std::copy(
		container.begin(),
		container.end(),
		std::ostream_iterator<typename Cont::value_type>(std::cout, " "));
	std::cout << "\n\n";
}