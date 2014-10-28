//==============================================================================
/**
 * @file    dtest/dtest-matcher-multi-generated.h
 *
 * @brief   header of Dtest multi-value matchers automatically generated
 *
 * @author  generate-matcher-header.py
 * @date    2014-10-29  generate-matcher-header.py
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
    Matcher matcher_;   //!< matcher
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
 * @return      matcher
 */
template <class Matcher>
inline VariadicMatcher1<OrCombiner, Matcher> AnyOf(const Matcher& matcher)
{
    return VariadicMatcher1<OrCombiner, Matcher>(matcher);
}

//==============================================================================
/**
 * @brief   variadic matcher (N = 2)
 */
//==============================================================================
template <class Combiner, class T1, class T2>
class VariadicMatcher2
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher2(const T1& v1, const T2& v2)
        : head_matcher_(v1), tail_matchers_(v2) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher1<Combiner, T2> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 2)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher2
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher2<Combiner, T1, T2>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2>
inline VariadicMatcher2<AndCombiner, T1, T2> AllOf(const T1& v1, const T2& v2)
{
    return VariadicMatcher2<AndCombiner, T1, T2>(v1, v2);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2>
inline VariadicMatcher2<OrCombiner, T1, T2> AnyOf(const T1& v1, const T2& v2)
{
    return VariadicMatcher2<OrCombiner, T1, T2>(v1, v2);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 3)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3>
class VariadicMatcher3
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher3(const T1& v1, const T2& v2, const T3& v3)
        : head_matcher_(v1), tail_matchers_(v2, v3) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher2<Combiner, T2, T3> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 3)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher3
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher3<Combiner, T1, T2, T3>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3>
inline VariadicMatcher3<AndCombiner, T1, T2, T3> AllOf(const T1& v1, const T2& v2, const T3& v3)
{
    return VariadicMatcher3<AndCombiner, T1, T2, T3>(v1, v2, v3);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3>
inline VariadicMatcher3<OrCombiner, T1, T2, T3> AnyOf(const T1& v1, const T2& v2, const T3& v3)
{
    return VariadicMatcher3<OrCombiner, T1, T2, T3>(v1, v2, v3);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 4)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4>
class VariadicMatcher4
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher4(const T1& v1, const T2& v2, const T3& v3, const T4& v4)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher3<Combiner, T2, T3, T4> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 4)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher4
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher4<Combiner, T1, T2, T3, T4>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4>
inline VariadicMatcher4<AndCombiner, T1, T2, T3, T4> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4)
{
    return VariadicMatcher4<AndCombiner, T1, T2, T3, T4>(v1, v2, v3, v4);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4>
inline VariadicMatcher4<OrCombiner, T1, T2, T3, T4> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4)
{
    return VariadicMatcher4<OrCombiner, T1, T2, T3, T4>(v1, v2, v3, v4);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 5)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4, class T5>
class VariadicMatcher5
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher5(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4, v5) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher4<Combiner, T2, T3, T4, T5> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 5)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher5
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4, class T5>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher5<Combiner, T1, T2, T3, T4, T5>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5>
inline VariadicMatcher5<AndCombiner, T1, T2, T3, T4, T5> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5)
{
    return VariadicMatcher5<AndCombiner, T1, T2, T3, T4, T5>(v1, v2, v3, v4, v5);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5>
inline VariadicMatcher5<OrCombiner, T1, T2, T3, T4, T5> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5)
{
    return VariadicMatcher5<OrCombiner, T1, T2, T3, T4, T5>(v1, v2, v3, v4, v5);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 6)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6>
class VariadicMatcher6
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher6(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4, v5, v6) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher5<Combiner, T2, T3, T4, T5, T6> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 6)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher6
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher6<Combiner, T1, T2, T3, T4, T5, T6>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6>
inline VariadicMatcher6<AndCombiner, T1, T2, T3, T4, T5, T6> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6)
{
    return VariadicMatcher6<AndCombiner, T1, T2, T3, T4, T5, T6>(v1, v2, v3, v4, v5, v6);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6>
inline VariadicMatcher6<OrCombiner, T1, T2, T3, T4, T5, T6> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6)
{
    return VariadicMatcher6<OrCombiner, T1, T2, T3, T4, T5, T6>(v1, v2, v3, v4, v5, v6);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 7)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
class VariadicMatcher7
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher7(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4, v5, v6, v7) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher6<Combiner, T2, T3, T4, T5, T6, T7> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 7)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher7
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher7<Combiner, T1, T2, T3, T4, T5, T6, T7>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
inline VariadicMatcher7<AndCombiner, T1, T2, T3, T4, T5, T6, T7> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7)
{
    return VariadicMatcher7<AndCombiner, T1, T2, T3, T4, T5, T6, T7>(v1, v2, v3, v4, v5, v6, v7);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7>
inline VariadicMatcher7<OrCombiner, T1, T2, T3, T4, T5, T6, T7> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7)
{
    return VariadicMatcher7<OrCombiner, T1, T2, T3, T4, T5, T6, T7>(v1, v2, v3, v4, v5, v6, v7);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 8)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
class VariadicMatcher8
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher8(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4, v5, v6, v7, v8) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher7<Combiner, T2, T3, T4, T5, T6, T7, T8> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 8)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher8
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher8<Combiner, T1, T2, T3, T4, T5, T6, T7, T8>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
inline VariadicMatcher8<AndCombiner, T1, T2, T3, T4, T5, T6, T7, T8> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8)
{
    return VariadicMatcher8<AndCombiner, T1, T2, T3, T4, T5, T6, T7, T8>(v1, v2, v3, v4, v5, v6, v7, v8);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
inline VariadicMatcher8<OrCombiner, T1, T2, T3, T4, T5, T6, T7, T8> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8)
{
    return VariadicMatcher8<OrCombiner, T1, T2, T3, T4, T5, T6, T7, T8>(v1, v2, v3, v4, v5, v6, v7, v8);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 9)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
class VariadicMatcher9
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher9(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4, v5, v6, v7, v8, v9) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher8<Combiner, T2, T3, T4, T5, T6, T7, T8, T9> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 9)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher9
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher9<Combiner, T1, T2, T3, T4, T5, T6, T7, T8, T9>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
inline VariadicMatcher9<AndCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9)
{
    return VariadicMatcher9<AndCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9>(v1, v2, v3, v4, v5, v6, v7, v8, v9);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
inline VariadicMatcher9<OrCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9)
{
    return VariadicMatcher9<OrCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9>(v1, v2, v3, v4, v5, v6, v7, v8, v9);
}


//==============================================================================
/**
 * @brief   variadic matcher (N = 10)
 */
//==============================================================================
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
class VariadicMatcher10
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher10(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9, const T10& v10)
        : head_matcher_(v1), tail_matchers_(v2, v3, v4, v5, v6, v7, v8, v9, v10) {}

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
    T1 head_matcher_;   //!< head matcher
    VariadicMatcher9<Combiner, T2, T3, T4, T5, T6, T7, T8, T9, T10> tail_matchers_;  //!< tail matchers
};

//==============================================================================
// definition of inline function (N = 10)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher10
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher10<Combiner, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>& matcher)
{
    matcher.DescribeTo(&os);
    return os;
}

/**
 * @brief   create AND matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
inline VariadicMatcher10<AndCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> AllOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9, const T10& v10)
{
    return VariadicMatcher10<AndCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
}

/**
 * @brief   create OR matcher
 *
 * @return      matcher
 */
template <class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
inline VariadicMatcher10<OrCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10> AnyOf(const T1& v1, const T2& v2, const T3& v3, const T4& v4, const T5& v5, const T6& v6, const T7& v7, const T8& v8, const T9& v9, const T10& v10)
{
    return VariadicMatcher10<OrCombiner, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>(v1, v2, v3, v4, v5, v6, v7, v8, v9, v10);
}



}

#endif // INCLUDE_DTEST_DTEST_MATCHER_MULTI_GENERATED_H
