//==============================================================================
/**
 * @file    dtest/dtest-manager-variadic-template.h
 *
 * @brief   header of DtestManagerVariadicTemplate
 *
 * @author  ymoch
 * @date    2014-11-02  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MANAGER_VARIADIC_TEMPLATE_H
#define INCLUDE_DTEST_DTEST_MANAGER_VARIADIC_TEMPLATE_H

#include "dtest-manager-base.h"

namespace dtest {

//==============================================================================
/**
 * @brief   Dtest manager implemented with variadic template
 */
//==============================================================================
class DtestManagerVariadicTemplate : public DtestManagerBase
{
public:
    /**
     * @brief       default constructor
     */
    DtestManagerVariadicTemplate() : DtestManagerBase() {}

    /**
     * @brief       destructor
     */
    ~DtestManagerVariadicTemplate() {}

    /**
     * @brief       execute test
     *
     * @tparam      Value       tested value type
     * @tparam      Matcher     matcher type
     *                          Required to be implemented:
     *                          - bool Matches(Value)
     *                          - ::std::ostream& operator<<(::std::ostream, const Matcher&)
     * @tparam      Logs        log types
     *                          Required to be implemented:
     *                          - ::std::ostream& operator<<(::std::ostream, const Log&)
     *
     * @param[in]   test_name   test name
     * @param[in]   value       tested value
     * @param[in]   matcher     matcher
     * @param[in]   logs        logs
     *
     * @retval      true        test succeeded
     * @retval      false       test failed
     */
    template <class Value, class Matcher, class... Logs>
    bool TestThat(
            const char* const test_name,
            const Value& value,
            const Matcher& matcher,
            const Logs&... logs)
    {
        const bool result = matcher.Matches(value);
        if (!result) {
            if (detail_stream_ != NULL) {
                *detail_stream_ << test_name << ',' << value << ',' << matcher;
                PrintLog(logs...);
                *detail_stream_ << '\n';
            }
            is_succeeded_ = false;
        }
        return result;
    }

private:
    /**
     * @brief       print log (dummy)
     */
    void PrintLog() {}

    /**
     * @brief       print log
     *
     * @tparam      First       first log type
     * @tparam      Rest        rest log types
     *
     * @param[in]   first       first log
     * @param[in]   rest        rest logs
     */
    template <class First, class... Rest>
    void PrintLog(const First& first, const Rest&... rest)
    {
        *detail_stream_ << ',' << first;
        PrintLog(rest...);
    }
};

} // namespace dtest

#endif // INCLUDE_DTEST_DTEST_MANAGER_VARIADIC_TEMPLATE_H
