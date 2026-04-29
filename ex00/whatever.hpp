/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:11:00 by rhiguita          #+#    #+#             */
/*   Updated: 2026/04/30 00:11:00 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>

void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	return (a < b) ? a : b;
}

template <typename T>
T const &max(T const &a, T const &b)
{
	return (a > b) ? a : b;
}

#endif
