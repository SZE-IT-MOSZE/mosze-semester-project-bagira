add_test([=[BasicAssertions.CheckIfEmpty]=]  C:/Users/Gergo/Desktop/mosze/mosze-semester-project-bagira/build/Debug/demo-test.exe [==[--gtest_filter=BasicAssertions.CheckIfEmpty]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BasicAssertions.CheckIfEmpty]=]  PROPERTIES WORKING_DIRECTORY C:/Users/Gergo/Desktop/mosze/mosze-semester-project-bagira/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[BasicAssertions.CheckData]=]  C:/Users/Gergo/Desktop/mosze/mosze-semester-project-bagira/build/Debug/demo-test.exe [==[--gtest_filter=BasicAssertions.CheckData]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[BasicAssertions.CheckData]=]  PROPERTIES WORKING_DIRECTORY C:/Users/Gergo/Desktop/mosze/mosze-semester-project-bagira/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  demo-test_TESTS BasicAssertions.CheckIfEmpty BasicAssertions.CheckData)