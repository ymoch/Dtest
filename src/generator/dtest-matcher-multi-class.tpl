//==============================================================================
/**
 * @brief   variadic matcher (N = $n)
 */
//==============================================================================
template <class Combiner, class T1, $def_tail>
class VariadicMatcher$n
{
public:
    /**
     * @brief       constructor
     */
    VariadicMatcher$n(const T1& v1, $def_tail_args)
        : head_matcher_(v1), tail_matchers_($tail_args) {}

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
    T1 head_matcher_;
    VariadicMatcher$prev_n<Combiner, $tail> tail_matchers_;
};

//==============================================================================
// definition of inline function (N = $n)
//==============================================================================
/**
 * @brief   operator << for VariadicMatcher
 *
 * @param[in,out]   os          output stream
 * @param[in]       matcher     matcher
 */
template <class Combiner, class T1, $def_tail>
inline ::std::ostream& operator<<(
        ::std::ostream& os,
        const VariadicMatcher$n<Combiner, T1, $tail>& matcher)
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
template <class T1, $def_tail>
inline VariadicMatcher$n<AndCombiner, T1, $tail> AllOf(const T1& v1, $def_tail_args)
{
    return VariadicMatcher$n<AndCombiner, T1, $tail>(v1, $tail_args);
}

/**
 * @brief   create OR matcher
 *
 * @param[in]   value       value to be compared
 * @return      matcher
 */
template <class T1, $def_tail>
inline VariadicMatcher$n<OrCombiner, T1, $tail> AnyOf(const T1& v1, $def_tail_args)
{
    return VariadicMatcher$n<OrCombiner, T1, $tail>(v1, $tail_args);
}


