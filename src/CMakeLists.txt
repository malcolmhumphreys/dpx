
include_directories (${PROJECT_SOURCE_DIR}/include)

add_executable(dpxinfo dpx.cpp dpxinfo.cpp)

install (TARGETS dpxinfo
    DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)