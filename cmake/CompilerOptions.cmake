if (MSVC)
    string (REGEX REPLACE "/W[0-4]" "" CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT}")
    # CMake enforce /W3 by default. This line tend to delete the regulation.
endif()

if (MSVC)
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "/W4"
        "/WX"
    )

    if(NOT (MSVC_VERSION LESS 1910)) # MSVC v14.1 (Visual Studio 2017 15.0)
        list(APPEND ${PROJECT_NAME}_CXX_FLAGS_DEBUG "/permissive-")
    endif()

    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE
        "/W1"
        "/O2"
    )
else()
    set(${PROJECT_NAME}_CXX_FLAGS_DEBUG
        "-pedantic"
        "-pedantic-errors"
        "-W"
        "-Wall"
        "-Wdouble-promotion"
        "-Werror"
        "-Wextra"
        "-Wfloat-equal"
        "-Wformat=1"
        "-Wimplicit-fallthrough"
        "-Winit-self"
        "-Winline"
        "-Wno-long-long"
        "-Wpointer-arith"
        "-Wshadow"
        "-Wsign-promo"
        "-Wundef"
        "-Wno-attributes"
    )
    set(${PROJECT_NAME}_CXX_FLAGS_RELEASE "-O3")
endif()
