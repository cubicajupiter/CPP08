/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:00:16 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/19 15:46:17 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include "Span.h"

int	main() {
	{
		std::cout << "SUBJECT TEST\n";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nRANGE OF ITERATORS -INSERTION FROM C-STYLE ARRAY\n";
		Span 	sp = Span(20);
		int		arr[25]{6, 5, 11, 4, 3, 53, 2, 1, 9, 26, 42, 13, 8, 18, 28, 38, 48, 58, 68, 78, 55, 56, 57, 58, 59};

		try {
			sp.addManyNumbers(arr, arr + 25);
		} catch (std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}
		
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << "\n";
	}
	{
		std::cout << "\nRANGE OF ITERATORS -INSERTION FROM ARRAY\n";
		Span 				sp = Span(10);
		std::array			arr{6, 5, 11, 4, 3, 53, 2, 1, 9, 26, 42, 13, 8, 18, 28};

		try {
			sp.addManyNumbers(arr.begin(), arr.end());
		} catch (std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}
		
		std::cout << sp.shortestSpan() << "\n";
		std::cout << sp.longestSpan() << std::endl;
	}
	
	return 0;
}