//==============================================================================
/**
 * @file    dtest/dtest-manager.h
 *
 * @brief   header of Dtest single-value matchers
 *
 * @author  ymoch
 * @date    2014-10-21  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MATCHER_SINGLE_H
#define INCLUDE_DTEST_DTEST_MATCHER_SINGLE_H

#include <ostream>
#include "internal/dtest-comparators.h"

namespace dtest {

//==============================================================================
/**
 * @brief   single value matcher
 *
 * @tparam  ValueType   Value type
 */
//==============================================================================
template <class ValueType, class Comparator>
class SingleValueMatcher
{
public:
    /**
     * @brief       constructor
     *
     * @param[in]   value   value to be matched
     */
    explicit SingleValueMatcher(const ValueType& value)
        : value_(value) {}

    /**
     * @brief       check that it matches
     *
     * @tparam      TargetValueType target value type
     * @param[in]   that            value to Matches
     * @retval      true            it matches
     * @retval      false           it doesn't match
     */
    template <class TargetValueType>
    bool Matches(const TargetValueType& that) const
    {
        return Comparator::Compare(that, value_);
    }

    /**
     * @brief       describe self
     *
     * @param       os      output stream to describe to
     */
    void DescribeTo(::std::ostream* os) const
    {
        *os << "is " << Comparator::GetOperatorString() << " " << value_;
    }

private:
    ValueType   value_; //!< value to be matched
};

//==============================================================================
// definitions of inline functions
//==============================================================================
/**
 * @brief   operator << for SingleValueMatcher
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class ValueType, class Comparator>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const SingleValueMatcher<ValueType, Comparator>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create matcher that checks "== value"
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class ValueType>
inline SingleValueMatcher<ValueType, EqualToComparator> Eq(
        const ValueType& value)
{
    return SingleValueMatcher<ValueType, EqualToComparator>(value);
}

/**
 * @brief   create matcher that checks "!= value"
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class ValueType>
inline SingleValueMatcher<ValueType, NotEqualToComparator> Ne(
        const ValueType& value)
{
    return SingleValueMatcher<ValueType, NotEqualToComparator>(value);
}

/**
 * @brief   create matcher that checks "> value"
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class ValueType>
inline SingleValueMatcher<ValueType, GreaterThanComparator> Gt(
        const ValueType& value)
{
    return SingleValueMatcher<ValueType, GreaterThanComparator>(value);
}

/**
 * @brief   create matcher that checks ">= value"
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class ValueType>
inline SingleValueMatcher<ValueType, GreaterThanOrEqualToComparator> Ge(
        const ValueType& value)
{
    return SingleValueMatcher<ValueType, GreaterThanOrEqualToComparator>(value);
}

/**
 * @brief   create matcher that checks "< value"
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class ValueType>
inline SingleValueMatcher<ValueType, LessThanComparator> Lt(
        const ValueType& value)
{
    return SingleValueMatcher<ValueType, LessThanComparator>(value);
}

/**
 * @brief   create matcher that checks "<= value"
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class ValueType>
inline SingleValueMatcher<ValueType, LessThanOrEqualToComparator> Le(
        const ValueType& value)
{
    return SingleValueMatcher<ValueType, LessThanOrEqualToComparator>(value);
}

} // namespace dtest

#endif // INCLUDE_DTEST_DTEST_MATCHER_SINGLE_H
