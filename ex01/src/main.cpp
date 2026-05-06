/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 16:00:16 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/06 16:48:44 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <numeric>
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

		std::cout << "Now contains: ";
		sp.printContent();
		std::cout << "Shortest span: ";
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: ";
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nFILLING AN EMPTY VECTOR AND BASIC COMPARISONS";
		
		Span sp = Span(3);
		std::cout << "\nNow contains: ";
		sp.printContent();

		try {std::cout << sp.shortestSpan() << std::endl;} catch (std::exception& e) {std::cout << e.what() << "\n";};
		try {std::cout << sp.longestSpan() << std::endl;} catch (std::exception& e) {std::cout << e.what() << "\n";};
		
		std::cout << "\t--adding in the integer 7--\n";
		sp.addNumber(7);
		std::cout << "Now contains: ";
		sp.printContent();
		
		std::cout << "Shortest span: ";
		try {std::cout << sp.shortestSpan() << std::endl;} catch (std::exception& e) {std::cout << e.what() << "\n";};
		std::cout << "Longest span: ";
		try {std::cout << sp.longestSpan() << std::endl;} catch (std::exception& e) {std::cout << e.what() << "\n";};
		
		std::cout << "\t--adding in the integer 2--\n";
		sp.addNumber(2);
		std::cout << "Now contains: ";
		sp.printContent();
		
		std::cout << "Shortest span: ";
		try {std::cout << sp.shortestSpan() << std::endl;} catch (std::exception& e) {std::cout << e.what() << "\n";};
		std::cout << "Longest span: ";
		try {std::cout << sp.longestSpan() << std::endl;} catch (std::exception& e) {std::cout << e.what() << "\n";};
	}
	{
		std::cout << "\nRANGE OF ITERATORS -INSERTION FROM C-STYLE ARRAY\n";
		Span 	sp = Span(20);
		int		arr[25]{6, 5, 11, 4, 3, 53, 2, 1, 9, 26, 42, 13, 8, 18, 28, 38, 48, 58, 68, 78, 55, 56, 57, 58, 59};

		try {
			sp.addRange(arr, arr + 25);
		} catch (std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "Now contains: ";
		sp.printContent();
		std::cout << "Shortest span: ";
		std::cout << sp.shortestSpan() << "\n";
		std::cout << "Longest span: ";
		std::cout << sp.longestSpan() << "\n";
	}
	{
		std::cout << "\nRANGE OF ITERATORS -INSERTION FROM ARRAY\n";
		Span 				sp = Span(10);
		std::array			arr{6, 5, 11, 4, 3, 53, 2, 1, 9, 26, 42, 13, 8, 18, 28};

		try {
			sp.addRange(arr.begin(), arr.end());
		} catch (std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "Now contains: ";
		sp.printContent();
		std::cout << "Shortest span: ";
		std::cout << sp.shortestSpan() << "\n";
		std::cout << "Longest span: ";
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		std::cout << "\nA 10000 NUMBER VECTOR\n";
		Span 				sp = Span(10000);
		std::vector<int>	arr(10000);

		std::iota(arr.begin(), arr.end(), 1);

		try {
			sp.addRange(arr.begin(), arr.end());
		} catch (std::out_of_range& e) {
			std::cout << e.what() << "\n";
		}
		std::cout << "Shortest span: ";
		std::cout << sp.shortestSpan() << "\n";
		std::cout << "Longest span: ";
		std::cout << sp.longestSpan() << std::endl;
	}
	
	return 0;
}