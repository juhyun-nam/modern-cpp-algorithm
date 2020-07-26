set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#file(GLOB ALL_SOURCE_FILES sort/*.h sort/*.cc tests/*)

add_custom_target(clang-format
									COMMAND
									clang-format
									-style=file
									-i
									${ALL_SOURCE_FILES}
)
add_custom_target(clang-tidy
                  COMMAND
									clang-tidy
									-config=''
									-p ${CMAKE_BINARY_DIR}
									${ALL_SOURCE_FILES}
)

add_custom_target(iwyu
                  COMMAND
									iwyu_tool.py -p ${CMAKE_BINARY_DIR}
)
