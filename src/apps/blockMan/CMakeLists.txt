# minimum cmake version supported
cmake_minimum_required (VERSION 2.6)

# application project
project (blockMan)

# The sources to be used
file(GLOB SOURCE_FILES "*.cpp")

# Output
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/../bin")

# Define the executable to be generated
set(TOOL_NAME "blockMan")
set(PROJ_NAME "apps")
add_executable(${TOOL_NAME} ${SOURCE_FILES})

# Add the project static libs at linking
target_link_libraries (${TOOL_NAME} wallet token ${BASE_LIBS})

# Testing
# Define paths to test folder and gold folder
set(TEST_EXE "${EXECUTABLE_OUTPUT_PATH}/${TOOL_NAME}")
set(TEST_PATH "${TEST_PATH}/${PROJ_NAME}/${TOOL_NAME}")
set(GOLD_PATH "${GOLD_PATH}/${PROJ_NAME}/${TOOL_NAME}")

# Additional target to make the README.md
build_readme(${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_NAME})

# Function to run an special or slow test case
function(run_special_test testName)
    run_the_special_test(${TEST_PATH} ${GOLD_PATH} ${testName} ${TEST_EXE} ${ARGN})
endfunction(run_special_test)

# Function to run an individual test case
function(run_test testName)
    run_the_test(${TEST_PATH} ${GOLD_PATH} ${testName} ${TEST_EXE} ${ARGN})
endfunction(run_test)

# Enter one line for each individual test
run_test("blockMan_README"    "-th")
run_test("blockMan_bad_input" "--thing")
#run_test("blockMan_list"      "--list" " --skip 50000")

# DO NOT USE THESE OPTIONS FOR TESTING, THEY ARE LONG RUNNING AND IRREVERSABLY CHANGE DATA FILES
#run_test("blockMan_list"     "--check")
#run_test("blockMan_list"     "--check" " 500000")
#run_test("blockMan_list"     "--check" " --deep")
#run_test("blockMan_list"     "--check" " --emptyOnly")
#run_test("blockMan_list"     "--check" " --noOnly")
#run_test("blockMan_list"     "--freshen")
#run_test("blockMan_list"     "--refreshen")
# DO NOT USE THESE OPTIONS FOR TESTING, THEY ARE LONG RUNNING AND IRREVERSABLY CHANGE DATA FILES

# Installation steps, this tool is renamed at installation
install(TARGETS ${TOOL_NAME} RUNTIME DESTINATION bin)
