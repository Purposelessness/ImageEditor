cmake_minimum_required(VERSION 3.5)
project(ImageEditor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "D:\\Qt\\6.2.3\\mingw_64")

find_package(QT NAMES Qt6 Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )

set(PROJECT_SOURCES
        QtApplication/main.cpp
        QtApplication/MainWidgets/editorwindow.cpp
        QtApplication/MainWidgets/editorwindow.h
        QtApplication/MainWidgets/tooldock.cpp
        QtApplication/MainWidgets/tooldock.h QtApplication/MainWidgets/imageviewer.cpp QtApplication/MainWidgets/imageviewer.h QtApplication/MainWidgets/toolbar.cpp QtApplication/MainWidgets/toolbar.h QtApplication/ToolStateMachine/toolcontext.cpp QtApplication/ToolStateMachine/toolcontext.h QtApplication/ToolStateMachine/tool.cpp QtApplication/ToolStateMachine/tool.h QtApplication/ToolStateMachine/Tools/Brushes/brush.cpp QtApplication/ToolStateMachine/Tools/Brushes/brush.h QtApplication/ToolStateMachine/toolview.cpp QtApplication/ToolStateMachine/toolview.h QtApplication/ToolStateMachine/toolcore.h QtApplication/Logger/logger.cpp QtApplication/Logger/logger.h QtApplication/ToolStateMachine/Tools/defaulttoolview.cpp QtApplication/ToolStateMachine/Tools/defaulttoolview.h QtApplication/ToolStateMachine/Tools/Brushes/brushcore.cpp QtApplication/ToolStateMachine/Tools/Brushes/brushcore.h QtApplication/ToolStateMachine/Tools/Frames/framecore.cpp QtApplication/ToolStateMachine/Tools/Frames/framecore.h QtApplication/ToolStateMachine/Tools/Frames/frame.cpp QtApplication/ToolStateMachine/Tools/Frames/frame.h)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ImageEditor
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
else ()
    add_executable(ImageEditor
            ${PROJECT_SOURCES}
            )
endif ()

target_link_libraries(ImageEditor PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ImageEditor)
endif ()

if (WIN32)
    set(DEBUG_SUFFIX)
    #    if (CMAKE_BUILD_TYPE MATCHES "Debug")
    #        set(DEBUG_SUFFIX "d")
    #    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/imageformats")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/imageformats/")

        file(GLOB QT_IMAGE_FORMATS "${QT_INSTALL_PATH}/plugins/imageformats/*.dll")
        foreach(CurrentHeaderFile IN LISTS QT_IMAGE_FORMATS)
            add_custom_command(
                    TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CurrentHeaderFile}
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/imageformats")
        endforeach()
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()