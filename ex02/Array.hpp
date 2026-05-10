/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhiguita <rhiguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:11:00 by rhiguita          #+#    #+#             */
/*   Updated: 2026/04/30 00:11:00 by rhiguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
#include <cstddef>

template <typename T>

class Array
{
	private:
		T				*_elements;
		unsigned int	_size;

	public:
		Array(void) : _elements(NULL), _size(0) {}

		Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

		Array(Array const &src) : _elements(NULL), _size(0)
		{
			*this = src;
		}


		~Array(void)
		{
			delete[] _elements;
		}

		Array &operator=(Array const &rhs)
		{
			if (this != &rhs)
			{
				delete[] _elements;
				_size = rhs._size;
				_elements = new T[_size]();
				for (unsigned int i = 0; i < _size; i++)
					_elements[i] = rhs._elements[i];
			}
			return *this;
		}

		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}

		T const &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}

		unsigned int size(void) const
		{
			return _size;
		}

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return "Error: index out of bounds";
				}
		};
};

#endif
