# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/test2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/test2_autogen.dir/ParseCache.txt"
  "test2_autogen"
  )
endif()
