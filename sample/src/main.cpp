//==============================================================================
/**
 * @file    main.h
 *
 * @brief   entry point
 *
 * @author  ymoch
 * @date    2014-10-19  ymoch
 */
//==============================================================================
#include <iostream>
#include "gmock/gmock.h"
#include "dtest/dtest.h"

using ::dtest::Le;
using ::dtest::Ge;
using ::dtest::AllOf;

/**
 * @brief       entry point
 *
 * @retval      0   test OK
 */
int main()
{
    dtest::DtestManager tester;
    tester.SetDetailStream(&::std::cout);
    tester.SetUp();

    tester.TestThat("TestName", 2, AllOf(Ge(1), Le(3)), "ADDITIONAL_MESSAGE");

    return 0;
}

