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

add_executable(test_cbr test_cbr.cpp)
target_link_libraries(test_cbr process_lib)

add_executable(test_mov test_mov.cpp)
target_link_libraries(test_mov process_lib)

add_executable(test_st test_st.cpp)
target_link_libraries(test_st process_lib)

add_executable(test_sub test_sub.cpp)
target_link_libraries(test_sub process_lib)

add_executable(test_lda test_lda.cpp)
target_link_libraries(test_lda process_lib)

add_executable(test_ld test_ld.cpp)
target_link_libraries(test_ld process_lib)

add_executable(test_ldc test_ldc.cpp)
target_link_libraries(test_ldc process_lib)

add_executable(test_label_and_data test_label_and_data.cpp)
target_link_libraries(test_label_and_data process_lib)

add_executable(unit_tests unit_tests.cpp)
target_link_libraries(unit_tests process_lib)