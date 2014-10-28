//==============================================================================
/**
 * @file    dtest-manager.cpp
 *
 * @brief   implementation of DtestManager
 *
 * @author  ymoch
 * @date    2014-10-19  ymoch
 */
//==============================================================================
#include "dtest/dtest-manager.h"

namespace dtest {

DtestManager::DtestManager()
    : is_succeeded_(true)
    , detail_stream_(NULL)
{}

DtestManager::~DtestManager()
{
}

void DtestManager::PrintHeader()
{
    if (!detail_stream_) {
        return;
    }
    *detail_stream_ << "test-name,value,predicate,additional-info\n";
}

}   // namespace dtest
