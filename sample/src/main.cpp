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
    dtest::DtestManager manager;
    manager.SetDetailStream(&::std::cout);
    manager.PrintHeader();

    manager.TestThat("TestName", 0, AllOf(Ge(1), Le(3)), "ADDITIONAL_MESSAGE");

    return manager.IsSucceeded() ? 0 : 1;
}

