/*
Topic 3: Container Adapters and Protected Members (For Ex02: Mutated abomination)
Exercise 02 requires you to make std::stack iterable by creating a MutantStack class. By default, std::stack intentionally hides iterators to enforce LIFO (Last-In-First-Out) behavior.

Concepts to Research:
Container Adapters: Understanding how std::stack wraps an underlying container (like std::deque by default).
The c Protected Member: std::stack has a protected member variable named c which is the actual underlying container. Inheriting from std::stack allows you to access c.
Type Aliasing (using vs. typedef): How to expose the iterators of the underlying container using modern C++ using declarations (e.g., using iterator = typename std::stack<T>::container_type::iterator;).

Resources:
cppreference: std::stack https://en.cppreference.com/w/cpp/container/stack
StackOverflow: How to iterate over a std::stack? (This thread discusses the exact "hack" needed for this exercise). https://stackoverflow.com/questions/525365/does-stdstack-expose-iterators
LearnCpp: Type aliases https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
*/
