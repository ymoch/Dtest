//==============================================================================
/**
 * @file    dtest/dtest-matcher-multi-c++11.h
 *
 * @brief   header of Dtest multi-value matchers for C++11
 *
 * @author  ymoch
 * @date    2014-10-21  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MATCHER_MULTI_VARIADIC_TEMPLATE_H
#define INCLUDE_DTEST_DTEST_MATCHER_MULTI_VARIADIC_TEMPLATE_H

#include <ostream>
#include "internal/dtest-combiners.h"

namespace dtest {

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
 * @brief   operator << for VariadicMatcher
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

#endif // INCLUDE_DTEST_DTEST_MATCHER_MULTI_VARIADIC_TEMPLATE_H
