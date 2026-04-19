/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 10:09:30 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/17 15:52:27 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <iostream>
#include <vector>
#include <array>


int	main() {
	std::vector<int>	int_vec{1, 2, 3, 4, 5};
	std::array<int, 5>	int_arr{10, 30, 20, 4, 50};
	int					result;

	try {
		result = easyfind(int_vec, 4);
		std::cout << result << "\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n";
	}
	
	try {
		result = easyfind(int_arr, 20);
		std::cout << result << "\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n";
	}
	
	try {
		result = easyfind(int_vec, 10);
		std::cout << result << "\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n";
	}

	try {
		result = easyfind(int_arr, -5);
		std::cout << result << "\n";
	} catch (std::out_of_range& e) {
		std::cerr << e.what() << "\n";
	}
}