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
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];

	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	/* Test: deep copy via copy constructor */
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	/* Test: values match mirror */
	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	/* Test: out-of-bounds access */
	try
	{
		numbers[-2];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		numbers[MAX_VAL];
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	/* Test: deep copy independence */
	{
		Array<int> copy(numbers);
		copy[0] = 42;
		if (numbers[0] == 42)
		{
			std::cerr << "Copy is not independent!" << std::endl;
			return 1;
		}
	}

	/* Test: assignment operator deep copy */
	{
		Array<int> assigned;
		assigned = numbers;
		assigned[0] = 0;
		if (numbers[0] == 0)
		{
			std::cerr << "Assignment is not a deep copy!" << std::endl;
			return 1;
		}
	}

	/* Test: empty array */
	{
		Array<int> empty;
		std::cout << "Empty array size: " << empty.size() << std::endl;
		try
		{
			empty[0];
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	/* Test: string array */
	{
		Array<std::string> strs(3);
		strs[0] = "Hello";
		strs[1] = "42";
		strs[2] = "Madrid";
		for (unsigned int i = 0; i < strs.size(); i++)
			std::cout << strs[i] << std::endl;
	}

	/* Test: const array access */
	{
		Array<int> base(5);
		for (unsigned int i = 0; i < base.size(); i++)
			base[i] = static_cast<int>(i * 10);

		const Array<int> constArr(base);
		for (unsigned int i = 0; i < constArr.size(); i++)
			std::cout << "constArr[" << i << "] = " << constArr[i] << std::endl;
	}

	delete[] mirror;
	return 0;
}
