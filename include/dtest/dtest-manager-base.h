//==============================================================================
/**
 * @file    dtest/dtest-manager-base.h
 *
 * @brief   header of DtestManagerBase
 *
 * @author  ymoch
 * @date    2014-11-02  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MANAGER_BASE_H
#define INCLUDE_DTEST_DTEST_MANAGER_BASE_H

#include <ostream>
#include "internal/dtest-utils.h"

namespace dtest {

//==============================================================================
/**
 * @brief   Dtest manager base
 */
//==============================================================================
class DtestManagerBase : private Uncopyable
{
public:
    /**
     * @brief       default constructor
     */
    DtestManagerBase()
        : is_succeeded_(true), detail_stream_() {}

    /**
     * @brief       destructor
     */
    ~DtestManagerBase() {}

    /**
     * @brief       assign stream to output details of tests
     *
     * @param[in]   os      output stream
     */
    void SetOutputStream(::std::ostream* os) { detail_stream_ = os; }

    /**
     * @brief       print detail output header
     */
    void PrintHeader()
    {
        if (!detail_stream_) {
            return;
        }
        *detail_stream_ << "test-name,value,predicate,additional-info\n";
    }

    /**
     * @brief       is succeeded
     *
     * @return      is succeeded
     */
    bool IsSucceeded() const { return is_succeeded_; }

protected:
    bool                is_succeeded_;  //!< is test succeeded
    ::std::ostream*     detail_stream_; //!< stream to output details of tests
};

}   // namespace dtest

#endif  // INCLUDE_DTEST_DTEST_MANAGER_BASE_H
