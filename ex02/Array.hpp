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
		/* Default constructor — empty array */
		Array(void) : _elements(NULL), _size(0) {}

		/* Parametric constructor — n elements initialized by default */
		Array(unsigned int n) : _elements(new T[n]()), _size(n) {}

		/* Copy constructor — deep copy */
		Array(Array const &src) : _elements(NULL), _size(0)
		{
			*this = src;
		}

		/* Destructor */
		~Array(void)
		{
			delete[] _elements;
		}

		/* Assignment operator — deep copy */
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

		/* Subscript operator */
		T &operator[](unsigned int index)
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}

		/* Const subscript operator */
		T const &operator[](unsigned int index) const
		{
			if (index >= _size)
				throw OutOfBoundsException();
			return _elements[index];
		}

		/* size() member function */
		unsigned int size(void) const
		{
			return _size;
		}

		/* Exception class */
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
