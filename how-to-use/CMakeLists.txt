cmake_minimum_required(VERSION 3.16)
project(koshi8bit-easy-living-how-to-use LANGUAGES CXX)

option(KOSHI8BIT_LIB_EASY_LIVING_COMPILE_FROM_SRC
    "Compile 'libs/koshi8bit/easy-living' from source (ON) or from DLL (OFF)"
    OFF)

find_package(Qt6 COMPONENTS Core Widgets REQUIRED)

qt_standard_project_setup()

set(BASE_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

message(STATUS "KOSHI8BIT_LIB_EASY_LIVING_COMPILE_FROM_SRC = " ${KOSHI8BIT_LIB_EASY_LIVING_COMPILE_FROM_SRC})
message(STATUS "CMAKE_CURRENT_SOURCE_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})



if(KOSHI8BIT_LIB_EASY_LIVING_COMPILE_FROM_SRC)
    message(STATUS "Compile `koshi8bit/easy-living` from SRC")

    list(APPEND BASE_SOURCES
        libs/koshi8bit/easy-living/koshi8bit-easy-living_global.h
        libs/koshi8bit/easy-living/easyliving.h
        libs/koshi8bit/easy-living/easyliving.cpp
        libs/koshi8bit/easy-living/operationresult.h
        libs/koshi8bit/easy-living/operationresult.cpp
    )
endif()

message(STATUS "Files to compile:")
foreach(item ${BASE_SOURCES})
    message(STATUS "-- ${item}")
endforeach()

qt_add_executable(${PROJECT_NAME}
    WIN32 MACOSX_BUNDLE
    ${BASE_SOURCES}
)

if(KOSHI8BIT_LIB_EASY_LIVING_COMPILE_FROM_SRC)

    target_compile_definitions(${PROJECT_NAME}
        PRIVATE KOSHI8BIT_EASY_LIVING_LIBRARY
    )

else()

    message(STATUS "Compile `koshi8bit/easy-living` with binary (DLL)")

    target_include_directories(${PROJECT_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/libs/koshi8bit/easy-living
    )

    target_link_directories(${PROJECT_NAME}
        PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/libs/koshi8bit/easy-living
    )

    target_link_libraries(${PROJECT_NAME}
        PRIVATE
            Qt${QT_VERSION_MAJOR}::Core
            koshi8bit-easy-living
    )
endif()

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
)