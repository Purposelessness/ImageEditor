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
        Concurrent
        REQUIRED
        )

find_package(Qt${QT_VERSION_MAJOR} COMPONENTS
        Core
        Gui
        Widgets
        Concurrent
        REQUIRED
        )

set(PROJECT_SOURCES
        QtApplication/main.cpp
        QtApplication/MainWidgets/EditorWindow/editorwindowview.cpp
        QtApplication/MainWidgets/EditorWindow/editorwindowview.h
        QtApplication/MainWidgets/ToolDock/tooldock.cpp
        QtApplication/MainWidgets/ToolDock/tooldock.h
        QtApplication/MainWidgets/ImageViewer/imageviewerview.cpp
        QtApplication/MainWidgets/ImageViewer/imageviewerview.h
        QtApplication/MainWidgets/ToolBar/toolbar.cpp
        QtApplication/MainWidgets/ToolBar/toolbar.h
        QtApplication/Service/ToolService/toolservice.cpp
        QtApplication/Service/ToolService/toolservice.h
        QtApplication/Service/Logger/logger.cpp
        QtApplication/logger.h
        QtApplication/MainWidgets/ToolDock/itooldock.h
        QtApplication/MainWidgets/ToolBar/itoolbar.h
        QtApplication/Service/ToolService/toolcontext.cpp
        QtApplication/Service/ToolService/toolcontext.h
        QtApplication/Service/ToolService/toolunit.h
        QtApplication/Service/ToolService/Tool/itoolmodel.h
        QtApplication/Service/ToolService/toolunitview.cpp
        QtApplication/Service/ToolService/toolunitview.h
        QtApplication/Service/ToolService/toolunit.cpp QtApplication/Service/ToolService/ToolCategory/toolcategory.cpp QtApplication/Service/ToolService/ToolCategory/toolcategory.h QtApplication/Service/ToolService/ToolCategory/toolcategorymodel.cpp QtApplication/Service/ToolService/ToolCategory/toolcategorymodel.h QtApplication/Service/ToolService/ToolCategory/BrushCategory/brushcategory.cpp QtApplication/Service/ToolService/ToolCategory/BrushCategory/brushcategory.h QtApplication/Service/ToolService/ToolCategory/BrushCategory/brushcategorymodel.cpp QtApplication/Service/ToolService/ToolCategory/BrushCategory/brushcategorymodel.h QtApplication/Service/ToolService/ToolCategory/BrushCategory/brushcategoryview.cpp QtApplication/Service/ToolService/ToolCategory/BrushCategory/brushcategoryview.h QtApplication/Service/ToolService/ToolCategory/ShapeCategory/shapecategory.cpp QtApplication/Service/ToolService/ToolCategory/ShapeCategory/shapecategory.h QtApplication/Service/ToolService/ToolCategory/ShapeCategory/shapecategoryview.cpp QtApplication/Service/ToolService/ToolCategory/ShapeCategory/shapecategoryview.h QtApplication/Service/ToolService/Tool/Brush-like/Brush/brush.cpp QtApplication/Service/ToolService/Tool/Brush-like/Brush/brush.h QtApplication/Service/ToolService/Tool/Brush-like/Brush/brushview.cpp QtApplication/Service/ToolService/Tool/Brush-like/Brush/brushview.h QtApplication/Service/ToolService/Tool/Brush-like/Brush/brushmodel.cpp QtApplication/Service/ToolService/Tool/Brush-like/Brush/brushmodel.h QtApplication/Service/ToolService/Tool/tool.cpp QtApplication/Service/ToolService/Tool/tool.h QtApplication/Service/ToolService/ToolCategory/ShapeCategory/shapecategorymodel.cpp QtApplication/Service/ToolService/ToolCategory/ShapeCategory/shapecategorymodel.h QtApplication/Service/ToolService/Tool/Brush-like/Pen/pen.cpp QtApplication/Service/ToolService/Tool/Brush-like/Pen/pen.h QtApplication/Service/ToolService/Tool/Brush-like/Pen/penview.cpp QtApplication/Service/ToolService/Tool/Brush-like/Pen/penview.h QtApplication/Service/ToolService/Tool/Brush-like/Pen/penmodel.cpp QtApplication/Service/ToolService/Tool/Brush-like/Pen/penmodel.h QtApplication/Service/ToolService/ToolCategory/toolcategoryview.cpp QtApplication/Service/ToolService/ToolCategory/toolcategoryview.h QtApplication/MainWidgets/ImageViewer/imagecontainer.cpp QtApplication/MainWidgets/ImageViewer/imagecontainer.h QtApplication/MainWidgets/EditorWindow/editorwindow.cpp QtApplication/Service/ImageReader/imagereader.cpp QtApplication/Service/ImageReader/imagereader.h QtApplication/Service/imageio.h QtApplication/Service/ImageWriter/imagewriter.cpp QtApplication/Service/ImageWriter/imagewriter.h QtApplication/MainWidgets/EditorWindow/editorwindow.h QtApplication/MainWidgets/ImageViewer/imageviewer.cpp QtApplication/MainWidgets/ImageViewer/imageviewer.h QtApplication/Service/ToolService/Tool/Shape/Line/line.cpp QtApplication/Service/ToolService/Tool/Shape/Line/line.h QtApplication/Service/Painter/painter.cpp QtApplication/Service/Painter/painter.h)

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
        Qt::Concurrent
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
        foreach (CurrentHeaderFile IN LISTS QT_IMAGE_FORMATS)
            add_custom_command(
                    TARGET ${PROJECT_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CurrentHeaderFile}
                    "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/imageformats")
        endforeach ()
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()