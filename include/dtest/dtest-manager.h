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

#include "dtest-manager-tuple-generated.h"
#ifdef _DTEST_VARIADIC_TEMPLATE
#   include "dtest-manager-variadic-template.h"
#endif

namespace dtest {

#ifdef _DTEST_VARIADIC_TEMPLATE
typedef DtestManagerVariadicTemplate DtestManager;
#else
typedef DtestManagerTuple DtestManager;
#endif

}   // namespace dtest

#endif  // INCLUDE_DTEST_DTEST_MANAGER_H
