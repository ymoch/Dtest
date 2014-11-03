//==============================================================================
/**
 * @file    dtest/dtest-manager.h
 *
 * @brief   header of Dtest matchers
 *
 * @author  ymoch
 * @date    2014-10-20  ymoch
 */
//==============================================================================
#ifndef INCLUDE_DTEST_DTEST_MATCHER_H
#define INCLUDE_DTEST_DTEST_MATCHER_H

#include "dtest-matcher-single.h"
#ifdef _DTEST_VARIADIC_TEMPLATE
#   include "dtest-matcher-multi-variadic-template.h"
#else
#   include "dtest-matcher-multi-tuple-generated.h"
#endif

#endif // INCLUDE_DTEST_DTEST_MATCHER_H
