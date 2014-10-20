//==============================================================================
/**
 * @file    dtest/dtest-manager.h
 *
 * @brief   header of Dtest matchers
 *
 * @author  ymoch
 * @date    2014-10-20  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MATCHER_H
#define INCLUDE_DTEST_DTEST_MATCHER_H

#include <utility>
#include <ostream>
#include "internal/dtest-comparators.h"
#include "internal/dtest-combiners.h"

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
/**
 * @brief       variadic matcher
 *
 * @tparam      Combiner        combiner of predicates
 * @tparam      HeadMatcher     head of matchers
 * @tparam      TailMatchers... tail of matchers
 */
//==============================================================================
template <class Combiner, class HeadMatcher, class... TailMatchers>
class VariadicMatcher
{
public:
    /**
     * @brief       constructor
     *
     * @param[in]   head_matcher  head of matchers
     * @param[in]   tail_matchers tail of matchers
     */
    VariadicMatcher(const HeadMatcher& head_matcher, TailMatchers... tail_matchers)
        : head_matcher_(head_matcher)
        , tail_matchers_(tail_matchers...) {}

    /**
     * @brief       check that it matches
     *
     * @tparam      ValueType       value type
     * @param[in]   value           value to Matches
     * @retval      true            it matches
     * @retval      false           it doesn't match
     */
    template <class ValueType>
    bool Matches(const ValueType& value) const
    {
        return Combiner::Combine(
                    head_matcher_.Matches(value),
                    tail_matchers_.Matches(value));
    }

    /**
     * @brief       describe self
     *
     * @param       os      output stream to describe to
     */
    void DescribeTo(::std::ostream* os) const
    {
        *os << "(" << head_matcher_ << ") "
            << Combiner::GetOperatorString() << " "
            << tail_matchers_;
    }

private:
    HeadMatcher                                 head_matcher_;  //!< head of matchers
    VariadicMatcher<Combiner, TailMatchers...>  tail_matchers_; //!< tail of matchers
};

//==============================================================================
/**
 * @brief       variadic matcher (specification for single matcher)
 *
 * @tparam      Combiner        combiner of predicates
 * @tparam      Matcher         matcher
 */
//==============================================================================
template <class Combiner, class Matcher>
class VariadicMatcher<Combiner, Matcher>
{
public:
    /**
     * @brief       constructor
     *
     * @param[in]   matcher     matcher
     */
    VariadicMatcher(const Matcher& matcher)
        : matcher_(matcher) {}

    /**
     * @brief       check that it matches
     *
     * @tparam      ValueType       value type
     * @param[in]   value           value to Matches
     * @retval      true            it matches
     * @retval      false           it doesn't match
     */
    template <class ValueType>
    bool Matches(const ValueType& value) const
    {
        return matcher_.Matches(value);
    }

    /**
     * @brief       describe self
     *
     * @param       os      output stream to describe to
     */
    void DescribeTo(::std::ostream* os) const
    {
        *os << "(" << matcher_ << ")";
    }

private:
    Matcher matcher_;   //!< matcher
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
 * @brief   operator << for SingleValueMatcher
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class HeadMatcher, class... TailMatchers>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher<Combiner, HeadMatcher, TailMatchers...>& matcher)
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

/**
 * @brief   create AND matcher
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class Matcher, class... RestMatchers>
inline VariadicMatcher<AndCombiner, Matcher, RestMatchers...> AllOf(
        const Matcher& matcher, RestMatchers... rest_matchers)
{
    return VariadicMatcher<AndCombiner, Matcher, RestMatchers...>(
                matcher, rest_matchers...);
}

/**
 * @brief   create OR matcher
 *
 * @tparam      ValueType   value type
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class Matcher, class... RestMatchers>
inline VariadicMatcher<OrCombiner, Matcher, RestMatchers...> AnyOf(
        const Matcher& matcher, RestMatchers... rest_matchers)
{
    return VariadicMatcher<OrCombiner, Matcher, RestMatchers...>(
                matcher, rest_matchers...);
}

}   // namespace dtest

#endif // INCLUDE_DTEST_DTEST_MATCHER_H
