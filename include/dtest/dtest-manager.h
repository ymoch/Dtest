//==============================================================================
/**
 * @file    dtest/dtest-manager.h
 *
 * @brief   header of DtestManager
 *
 * @author  ymoch
 * @date    2014-10-19  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MANAGER_H
#define INCLUDE_DTEST_DTEST_MANAGER_H

#include <ostream>
#include "internal/dtest-utils.h"

namespace dtest {

//==============================================================================
/**
 * @brief   Dtest manager
 */
//==============================================================================
class DtestManager : private Uncopyable
{
public:
    /**
     * @brief       default constructor
     */
    DtestManager();

    /**
     * @brief       destructor
     */
    ~DtestManager();

    /**
     * @brief       assign stream to output details of tests
     *
     * @param[in]   os      output stream
     */
    void SetDetailStream(::std::ostream* os) { detail_stream_ = os; }

    /**
     * @brief       print detail output header
     */
    void PrintHeader();

    /**
     * @brief       test by matcher
     *
     * @tparam      ValueType       type of the tested value
     * @tparam      MatcherType     type of the matcher
     *                              this type is needed to implement:
     *                              - bool Matches(const ValueType&)
     *                              - void DescribeTo(std::ostream*);
     * @tparam      InfoType        type of information
     *                              this type is needed to implement:
     *                              - operator<<(ostream, this)
     *
     * @param[in]   test_name       test name
     * @param[in]   value           tested value
     * @param[in]   matcher         matcher
     * @param[in]   info            additional information for logging
     * @retval      true            test succeeded
     * @retval      false           test failed
     */
    template <class ValueType, class MatcherType, class InfoType>
    bool TestThat(const char* test_name,
                  const ValueType& value,
                  const MatcherType& matcher,
                  const InfoType& info);

    /**
     * @brief       test by matcher
     *
     * @tparam      ValueType       type of the tested value
     * @tparam      MatcherType     type of the matcher
     *                              this type is needed to implement:
     *                              - bool Matches(const ValueType&)
     *                              - void DescribeTo(std::ostream*);
     *
     * @param[in]   test_name       test name
     * @param[in]   value           tested value
     * @param[in]   matcher         matcher
     * @retval      true            test succeeded
     * @retval      false           test failed
     */
    template <class ValueType, class MatcherType>
    bool TestThat(const char* test_name,
                   const ValueType& value,
                   const MatcherType& matcher);

    /**
     * @brief       is succeeded
     *
     * @return      is succeeded
     */
    bool IsSucceeded() const { return is_succeeded_; }

private:
    bool                is_succeeded_;  //!< is test succeeded
    ::std::ostream*     detail_stream_; //!< stream to output details of tests
};

//==============================================================================
// inline implementations
//==============================================================================
template <class ValueType, class MatcherType, class InfoType>
inline bool DtestManager::TestThat(
        const char* test_name,
        const ValueType& value,
        const MatcherType& matcher,
        const InfoType& info)
{
    const bool result = matcher.Matches(value);
    if (!result) {
        if (detail_stream_) {
            *detail_stream_ << test_name
                            << ',' << value
                            << ',' << matcher
                            << ',' << info << '\n';
        }
        is_succeeded_ = false;
        return false;
    }
    return true;
}

template <class ValueType, class MatcherType>
inline bool DtestManager::TestThat(
        const char* test_name,
        const ValueType& value,
        const MatcherType& matcher)
{
    return TestThat(test_name, value, matcher, "");
}

}   // namespace dtest

#endif  // INCLUDE_DTEST_DTEST_MANAGER_H
