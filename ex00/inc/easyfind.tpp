/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 09:54:34 by jvalkama          #+#    #+#             */
/*   Updated: 2026/05/06 15:45:24 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <stdexcept>

template <typename T>
int	easyfind(T haystack, int needle) {
	auto ite = std::find(haystack.begin(), haystack.end(), needle);
	if (ite != haystack.end())
		return *ite;
	throw std::out_of_range("Item not found!");
}