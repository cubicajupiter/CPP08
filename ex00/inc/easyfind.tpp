/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 09:54:34 by jvalkama          #+#    #+#             */
/*   Updated: 2026/04/17 15:51:06 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	easyfind(T haystack, int needle) {
	auto end_iterator = std::find(haystack.begin(), haystack.end(), needle);
	if (end_iterator != haystack.end())
		return *end_iterator;
	throw std::out_of_range("Item not found!");
}