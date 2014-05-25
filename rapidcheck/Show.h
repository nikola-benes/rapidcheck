#pragma once

namespace rc {

//! Outputs a representation of the given value to the given output stream. The
//! default is to use \c operator<< but you can override this representation by
//! providing overloads for different types.
//!
//! @param value  The value.
//! @param os     The output stream.
template<typename T>
void show(const T &value, std::ostream &os);

//! Overloaded show to display strings in a more readable way.
void show(const std::string &value, std::ostream &os);

//! Delegates to the \c std::string version
void show(const char *value, std::ostream &os);

template<typename T1, typename T2>
void show(const std::pair<T1, T2> &pair, std::ostream &os);

//! Helper function for showing collections of values.
//!
//! @param prefix  The prefix to the collection, for example "["
//! @param suffix  The suffix to the collection, for example "]"
//! @param begin   The start of the range.
//! @param end     The end of the range.
//! @param os      The stream to output to.
template<typename Iterator>
void showCollection(const std::string &prefix,
                    const std::string &suffix,
                    Iterator begin,
                    Iterator end,
                    std::ostream &os);

template<typename T, typename Alloc>
void show(const std::vector<T, Alloc> &vec, std::ostream &os);

template<typename Key,
         typename T,
         typename Compare,
         typename Allocator>
void show(const std::map<Key, T, Compare, Allocator> &m, std::ostream &os);

} // namespace rc

#include "detail/Show.hpp"
