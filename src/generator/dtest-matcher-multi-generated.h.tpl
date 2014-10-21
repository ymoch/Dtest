//==============================================================================
/**
 * @file    dtest/dtest-matcher-multi-generated.h
 *
 * @brief   header of Dtest multi-value matchers automatically generated
 *
 * @author  $author
 * @date    $date  $author
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MATCHER_MULTI_GENERATED_H
#define INCLUDE_DTEST_DTEST_MATCHER_MULTI_GENERATED_H

#include "internal/dtest-combiners.h"

namespace dtest {

//==============================================================================
/**
 * @brief   variadic matcher (N = 1)
 */
//==============================================================================
template <class Combiner, class Matcher>
class VariadicMatcher1
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher1(const Matcher& matcher)
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
    Matcher matcher_;
};

//==============================================================================
// definition of inline function (N = 1)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class Matcher>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher1<Combiner, Matcher>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class Matcher>
inline VariadicMatcher1<AndCombiner, Matcher> AllOf(const Matcher& matcher)
{
    return VariadicMatcher1<AndCombiner, Matcher>(matcher);
}

/**
 * @brief   create OR matcher
 *
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class Matcher>
inline VariadicMatcher1<OrCombiner, Matcher> AnyOf(const Matcher& matcher)
{
    return VariadicMatcher1<OrCombiner, Matcher>(matcher);
}

$class_definitions
}

#endif // INCLUDE_DTEST_DTEST_MATCHER_MULTI_GENERATED_H
