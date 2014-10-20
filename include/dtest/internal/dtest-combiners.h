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
#ifndef INCLUDE_DTEST_DTEST_COMBINERS_H
#define INCLUDE_DTEST_DTEST_COMBINERS_H

namespace dtest {

//==============================================================================
/**
 * @brief       AND combiner
 */
//==============================================================================
class AndCombiner
{
public:
    /**
     * @brief       Combine
     *
     * @param[in]   a       combined flag
     * @param[in]   b       combined flag
     * @return      combined value
     */
    static bool Combine(const bool a, const bool b)
    {
        return a && b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorStr = "and";
        return kOperatorStr;
    }
};

//==============================================================================
/**
 * @brief       OR combiner
 */
//==============================================================================
class OrCombiner
{
public:
    /**
     * @brief       Combine
     *
     * @param[in]   a       combined flag
     * @param[in]   b       combined flag
     * @return      combined value
     */
    static bool Combine(const bool a, const bool b)
    {
        return a || b;
    }

    /**
     * @brief       Get operator string
     *
     * @return      operator string
     */
    static const char* GetOperatorString()
    {
        static const char* const kOperatorStr = "or";
        return kOperatorStr;
    }
};

} // namespace dtest

#endif // INCLUDE_DTEST_DTEST_COMBINERS_H
