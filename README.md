Dtest
======

Dtest is a library specialized to test data.

1. Features
--------------

1. Simple component

  - Able to write complex tests with simple Dtest components.

2. Highly-optimized assertion

  - Most of Dtest assertions will be in-line-expanded and executed fast.

3. Each assertion stands for an assertion

  - Each assertion has a name, and this means "a test case".

4. Each assertion returns its result

  - Able to control testing flows freely with results of tests.

5. Written with predicates

  - To make finding the meaning of each test easy.

6. Output expressed in CSV format

  - To make analysing results easy.

3. Images
---------

### 1. Coding tests

```c++
// create test manager
dtest::DtestManager manager;

// set the output stream
std::ofstream ofs("dtest_log.csv");
manager.SetDetailStream(&ofs);
manager.PrintHeader();

// run (i.e.)
for (auto it = container.begin(); it != container.end(); ++it) {
  manager.TestThat("TestName1", it->value1, dtest::Eq(0), "AdditionalMessage");
  manager.TestThat("TestName2", it->value2, dtest::AllOf(dtest::Gt(1), dtest::Lt(5)));
}
```

### 2. Check output

The content of output file "dtest_log.csv" is like below.

```
TestName1,1,is == 0,AdditionalMessage
TestName2,0,(is > 1) and (is < 5),
TestName1,2,is == 0,AdditionalMessage
```


4. License
-----------

Dtest is released under the MIT License, see LICENSE.

