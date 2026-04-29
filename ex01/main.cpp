/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:11:00 by rhiguita          #+#    #+#             */
/*   Updated: 2026/04/30 00:11:00 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T const &elem)
{
	std::cout << elem << std::endl;
}

void increment(int &n)
{
	n++;
}

void toUpper(std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = static_cast<char>(std::toupper(s[i]));
}

int main(void)
{
	std::cout << "=== Int array ===" << std::endl;
	int intArr[] = {0, 1, 2, 3, 4};
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== After increment ===" << std::endl;
	::iter(intArr, 5, increment);
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== String array ===" << std::endl;
	std::string strArr[] = {"hello", "world", "forty-two"};
	::iter(strArr, 3, print<std::string>);

	std::cout << "\n=== After toUpper ===" << std::endl;
	::iter(strArr, 3, toUpper);
	::iter(strArr, 3, print<std::string>);

	std::cout << "\n=== Double array ===" << std::endl;
	double dblArr[] = {1.1, 2.2, 3.3};
	::iter(dblArr, 3, print<double>);

	return 0;
}
