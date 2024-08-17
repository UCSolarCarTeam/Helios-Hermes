# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/HeliosHermes_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/HeliosHermes_autogen.dir/ParseCache.txt"
  "HeliosHermes_autogen"
  )
endif()
