add_executable(test_add test_add.cpp)
target_link_libraries(test_add process_lib)

add_executable(test_and test_and.cpp)
target_link_libraries(test_and process_lib)

add_executable(test_or test_or.cpp)
target_link_libraries(test_or process_lib)

add_executable(test_xor test_xor.cpp)
target_link_libraries(test_xor process_lib)

add_executable(test_asl test_asl.cpp)
target_link_libraries(test_asl process_lib)

add_executable(test_asr test_asr.cpp)
target_link_libraries(test_asr process_lib)

add_executable(test_lsl test_lsl.cpp)
target_link_libraries(test_lsl process_lib)

add_executable(test_lsr test_lsr.cpp)
target_link_libraries(test_lsr process_lib)

add_executable(test_cnd test_cnd.cpp)
target_link_libraries(test_cnd process_lib)



