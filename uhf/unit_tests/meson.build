#
# TODO Could split out only those source files needed to support each test. See
# golay test for example.

incdirUT = include_directories(
    '../include'
)

unit_test_uhfRadio = executable('unit_test-uhfRadio', 'qa_radio.cpp', core_source_files,
  include_directories : incdirUT,
  dependencies: [gtest_dep]
)

test('uhfRadio', unit_test_uhfRadio,
    timeout: 5
    )
    
