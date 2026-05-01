<p align="center">
  <img src="https://github.com/higrub89/higrub89/blob/main/42_badge.png?raw=true" alt="42 Badge" width="120"/>
</p>

<h1 align="center">CPP Module 07 — C++ Templates</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C++98-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/42-Madrid-000000?style=for-the-badge&logo=42&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Grade-TBD-yellow?style=for-the-badge"/>
</p>

<p align="center">
  <i>Introduction to C++ generic programming through function and class templates.</i>
</p>

---

## 📋 Table of Contents

- [About](#-about)
- [Concepts Learned](#-concepts-learned)
- [Exercises](#-exercises)
- [Build & Run](#-build--run)
- [Project Structure](#-project-structure)
- [Key Takeaways](#-key-takeaways)

---

## 📖 About

**CPP Module 07** is part of the C++ learning track at [42 Madrid](https://www.42madrid.com/).
This module focuses entirely on **templates** — the foundation of generic programming in C++.
Templates allow writing code that works with any data type while maintaining full type safety at compile time.

> _"Templates are the C++ feature that enables generic programming — write once, use with any type."_

### Prerequisites
- Completion of CPP Modules 00–06
- Understanding of operator overloading, inheritance, and polymorphism
- Familiarity with the Orthodox Canonical Form (OCF)

---

## 🧠 Concepts Learned

| Concept | Description |
|---------|-------------|
| **Function Templates** | Generic functions that deduce types at compile time |
| **Class Templates** | Full class definitions parameterized by type |
| **Template Instantiation** | How the compiler generates concrete code from templates |
| **Explicit Instantiation** | Calling templated functions with explicit type `func<int>()` |
| **Template Specialization** | Understanding when and why the compiler chooses a specific overload |
| **Deep Copy in Templates** | Implementing copy constructors and assignment operators for templated containers |
| **Exception Safety** | Custom exception classes within template classes |
| **Header-Only Design** | Why template definitions must reside in headers (not `.cpp` files) |

---

## 📝 Exercises

### Exercise 00 — `Whatever`

> **Goal:** Implement three function templates: `swap`, `min`, and `max`.

Templates that operate on **any comparable type** using generic type deduction.

```cpp
template <typename T>
void swap(T &a, T &b);

template <typename T>
T const &min(T const &a, T const &b);

template <typename T>
T const &max(T const &a, T const &b);
```

**Key insight:** These functions work identically with `int`, `std::string`, or any type that supports `<` and `>` operators — zero code duplication.

| File | Purpose |
|------|---------|
| `whatever.hpp` | Template function definitions |
| `main.cpp` | Tests with `int` and `std::string` |

---

### Exercise 01 — `Iter`

> **Goal:** Implement a function template that iterates over an array and applies a function to each element.

```cpp
template <typename T, typename F>
void iter(T *array, size_t length, F func);
```

This exercise introduces the concept of **higher-order generic programming** — a function template that accepts both a generic array and a generic callable. The dual-template parameter `<T, F>` enables `iter` to work with any array type and any compatible function or functor.

**Tests include:**
- `int` arrays with `print<int>` and `increment`
- `std::string` arrays with `print<std::string>` and `toUpper`
- `double` arrays with `print<double>`

| File | Purpose |
|------|---------|
| `iter.hpp` | Template function definition |
| `main.cpp` | Comprehensive tests across types |

---

### Exercise 02 — `Array`

> **Goal:** Implement a class template `Array<T>` that behaves like a safe, bounds-checked dynamic array.

The most complex exercise — a full **template class** implementing the Orthodox Canonical Form with dynamic memory management.

```cpp
template <typename T>
class Array {
    T             *_elements;
    unsigned int  _size;

public:
    Array(void);                        // Default: empty array
    Array(unsigned int n);              // Parameterized: n elements, value-initialized
    Array(Array const &src);            // Deep copy constructor
    ~Array(void);                       // Destructor
    Array &operator=(Array const &rhs); // Deep copy assignment
    T &operator[](unsigned int index);  // Bounds-checked access
    T const &operator[](unsigned int index) const; // Const access
    unsigned int size(void) const;      // Size getter

    class OutOfBoundsException : public std::exception { /*...*/ };
};
```

**Critical implementation details:**
- **Deep copy semantics:** Both copy constructor and assignment operator allocate new memory and copy elements individually — modifying a copy never affects the original.
- **Bounds checking:** The `operator[]` throws a custom `OutOfBoundsException` for invalid indices.
- **Value initialization:** `new T[n]()` ensures elements are zero/default-initialized.
- **Const correctness:** Separate const and non-const `operator[]` overloads.

| File | Purpose |
|------|---------|
| `Array.hpp` | Complete template class (header-only) |
| `main.cpp` | Exhaustive test suite: deep copy, bounds, const, multi-type |

---

## 🔨 Build & Run

Each exercise is independently compilable:

```bash
# Compile and run any exercise
cd ex00 && make && ./whatever
cd ex01 && make && ./iter
cd ex02 && make && ./array

# Clean build artifacts
make clean    # Remove object files
make fclean   # Remove object files + binary
make re       # Full rebuild
```

**Compiler:** `c++` with flags `-Wall -Wextra -Werror -std=c++98 -O3`

---

## 📁 Project Structure

```
cpp_07/
├── README.md
├── ex00/                    # Whatever — Function Templates
│   ├── Makefile
│   ├── whatever.hpp         # swap, min, max templates
│   └── main.cpp
├── ex01/                    # Iter — Iterator Template
│   ├── Makefile
│   ├── iter.hpp             # iter() function template
│   └── main.cpp
└── ex02/                    # Array — Class Template
    ├── Makefile
    ├── Array.hpp            # Full template class (OCF + exceptions)
    └── main.cpp
```

---

## 💡 Key Takeaways

1. **Templates enable DRY code** — Write one function/class, use it with unlimited types.
2. **Templates are resolved at compile time** — Zero runtime overhead vs. hand-written type-specific code.
3. **Header-only is mandatory** — The compiler needs the full template definition at every usage site, so implementations live in `.hpp` files.
4. **Deep copy remains critical** — Even in templated classes, RAII and proper memory management (Rule of Three) are non-negotiable.
5. **Dual-parameter templates** (`<T, F>`) unlock higher-order generic patterns, similar to `std::for_each` in the STL.

---

## 🗺️ 42 C++ Module Roadmap

| Module | Topic | Status |
|--------|-------|--------|
| CPP 00 | Namespaces, classes, member functions | ✅ |
| CPP 01 | Memory allocation, pointers to members, references | ✅ |
| CPP 02 | Ad-hoc polymorphism, operator overloading, OCF | ✅ |
| CPP 03 | Inheritance | ✅ |
| CPP 04 | Subtype polymorphism, abstract classes, interfaces | ✅ |
| CPP 05 | Exceptions | ✅ |
| CPP 06 | C++ casts (`static`, `dynamic`, `reinterpret`) | ✅ |
| **CPP 07** | **Templates** | **✅ Current** |
| CPP 08 | Templated containers, iterators, algorithms | ⬜ Next |
| CPP 09 | STL | ⬜ |

---

<p align="center">
  <b>Made with ❤️ at <a href="https://www.42madrid.com/">42 Madrid</a></b><br/>
  <sub>rhiguita — 2026</sub>
</p>
