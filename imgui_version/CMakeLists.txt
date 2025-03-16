cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)
project(pi_imgui_demo)

add_subdirectory(../external/hello_imgui ${CMAKE_BINARY_DIR}/hello_imgui_build)

option(EXAMPLE_INTEGRATION_PORTABLE_INSTALL "Install in a portable way" ON)

set(GUI_SOURCE gui.cpp)
include_directories(.)

if (EXAMPLE_INTEGRATION_PORTABLE_INSTALL)
    hello_imgui_add_app(${PROJECT_NAME} main.cpp ${GUI_SOURCE})
else()
    set(HELLOIMGUI_ADD_APP_WITH_INSTALL OFF CACHE BOOL "" FORCE)
    imgui_bundle_add_app(${PROJECT_NAME} main.cpp ${GUI_SOURCE})

    if (NOT EXAMPLE_INTEGRATION_PORTABLE_INSTALL)
        include(GNUInstallDirs)
        install(TARGETS ${PROJECT_NAME} DESTINATION ${CMAKE_INSTALL_BINDIR})
        set(assets_install_dir ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME})
        if (NOT IS_ABSOLUTE ${assets_install_dir})
            set(assets_install_dir ${CMAKE_INSTALL_PREFIX}/${assets_install_dir})
        endif()
        install(DIRECTORY assets DESTINATION ${assets_install_dir})
        target_compile_definitions(imgui_bundle_example_integration PRIVATE ASSETS_LOCATION="${assets_install_dir}/assets")
    endif()
endif()

