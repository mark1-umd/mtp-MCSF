set(GTEST_SHUFFLE 1)

add_executable(
    mcfs-test
    main.cpp
    MCFStest.cpp
)

target_include_directories(mcfs-test PUBLIC ../vendor/googletest/googletest/include)
target_link_libraries(mcfs-test PUBLIC gtest)
