//==============================================================================
/**
 * @file    dtest/iternal/dtest-comparators.h
 *
 * @brief   header of Dtest comparators
 *
 * @author  ymoch
 * @date    2014-10-20  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_COMPARATORS_H
#define INCLUDE_DTEST_DTEST_COMPARATORS_H

namespace dtest {

//==============================================================================
/**
 * @brief   Comparator to check that A is equal to B
 */
//==============================================================================
class EqualToComparator
{
public:
    /**
     * @brief       Check a == b
     *
     * @tparam      ValueType1  compared value type
     * @tparam      ValueType2  comparing value type
     * @param[in]   a           compared value
     * @param[in]   b           comparing value
     * @return      result of expression "a == b"
     */
    template <class ValueType1, class ValueType2>
    static bool Compare(const ValueType1& a, const ValueType2& b)
    {
        return a == b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorString = "==";
        return kOperatorString;
    }
};

//==============================================================================
/**
 * @brief   Comparator to check that A isn't equal to B
 */
//==============================================================================
class NotEqualToComparator
{
public:
    /**
     * @brief       Check a != b
     *
     * @tparam      ValueType1  compared value type
     * @tparam      ValueType2  comparing value type
     * @param[in]   a           compared value
     * @param[in]   b           comparing value
     * @return      result of expression "a != b"
     */
    template <class ValueType1, class ValueType2>
    static bool Compare(const ValueType1& a, const ValueType2& b)
    {
        return a != b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorString = "!=";
        return kOperatorString;
    }
};

//==============================================================================
/**
 * @brief   Comparator to check that A is greater than B
 */
//==============================================================================
class GreaterThanComparator
{
public:
    /**
     * @brief       Check a > b
     *
     * @tparam      ValueType1  compared value type
     * @tparam      ValueType2  comparing value type
     * @param[in]   a           compared value
     * @param[in]   b           comparing value
     * @return      result of expression "a > b"
     */
    template <class ValueType1, class ValueType2>
    static bool Compare(const ValueType1& a, const ValueType2& b)
    {
        return a > b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorString = ">";
        return kOperatorString;
    }
};

//==============================================================================
/**
 * @brief   Comparator to check that A is greater than or equal to B
 */
//==============================================================================
class GreaterThanOrEqualToComparator
{
public:
    /**
     * @brief       Check a >= b
     *
     * @tparam      ValueType1  compared value type
     * @tparam      ValueType2  comparing value type
     * @param[in]   a           compared value
     * @param[in]   b           comparing value
     * @return      result of expression "a >= b"
     */
    template <class ValueType1, class ValueType2>
    static bool Compare(const ValueType1& a, const ValueType2& b)
    {
        return a >= b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorString = ">=";
        return kOperatorString;
    }
};

//==============================================================================
/**
 * @brief   Comparator to check that A is less than B
 */
//==============================================================================
class LessThanComparator
{
public:
    /**
     * @brief       Check a < b
     *
     * @tparam      ValueType1  compared value type
     * @tparam      ValueType2  comparing value type
     * @param[in]   a           compared value
     * @param[in]   b           comparing value
     * @return      result of expression "a < b"
     */
    template <class ValueType1, class ValueType2>
    static bool Compare(const ValueType1& a, const ValueType2& b)
    {
        return a < b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorString = "<";
        return kOperatorString;
    }
};

//==============================================================================
/**
 * @brief   Comparator to check that A is less than or equal to B
 */
//==============================================================================
class LessThanOrEqualToComparator
{
public:
    /**
     * @brief       Check a <= b
     *
     * @tparam      ValueType1  compared value type
     * @tparam      ValueType2  comparing value type
     * @param[in]   a           compared value
     * @param[in]   b           comparing value
     * @return      result of expression "a <= b"
     */
    template <class ValueType1, class ValueType2>
    static bool Compare(const ValueType1& a, const ValueType2& b)
    {
        return a <= b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorString = "<=";
        return kOperatorString;
    }
};

} // namespace dtest

#endif // INCLUDE_DTEST_DTEST_COMPARATORS_H
