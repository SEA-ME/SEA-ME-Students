# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/m01_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/m01_autogen.dir/ParseCache.txt"
  "m01_autogen"
  )
endif()
