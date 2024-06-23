cmake_minimum_required(VERSION 3.5)

project(human_and_ai VERSION 0.1 LANGUAGES CXX)

# Find required Qt components
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Test)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Test)

# Set C++ standard and options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define your main application sources
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    aiplayer.h
    aiplayer.cpp
    gameboard.h
    gameboard.cpp
)

# Create the main executable for your application
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(human_and_ai
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(human_and_ai SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(human_and_ai
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link Qt Widgets module to the main executable
target_link_libraries(human_and_ai PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Set properties for macOS bundle if applicable
if(APPLE)
    set_target_properties(human_and_ai PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    )
endif()

# Include Qt Test module for building unit tests
include_directories(${CMAKE_SOURCE_DIR})  # Include root directory for tests

# Add unit test executables
add_executable(test_aiplayer
    test_aiplayer.cpp
    aiplayer.h
    aiplayer.cpp
    gameboard.h
    gameboard.cpp
)
target_link_libraries(test_aiplayer PRIVATE Qt${QT_VERSION_MAJOR}::Test)

add_executable(test_gameboard
    test_gameboard.cpp
    gameboard.h
    gameboard.cpp
)
target_link_libraries(test_gameboard PRIVATE Qt${QT_VERSION_MAJOR}::Test)

add_executable(test_mainwindow
    test_mainwindow.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    aiplayer.h
    aiplayer.cpp
    gameboard.h
    gameboard.cpp
)
target_link_libraries(test_mainwindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

# Ensure tests are discovered by CTest
enable_testing()
add_test(NAME TestAIPlayer COMMAND test_aiplayer)
add_test(NAME TestGameBoard COMMAND test_gameboard)
add_test(NAME TestMainWindow COMMAND test_mainwindow)

# Install the main application
include(GNUInstallDirs)
install(TARGETS human_and_ai
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
