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
        QtApplication/MainWidgets/iv.h
        QtApplication/MainWidgets/iv.cpp
        QtApplication/MainWidgets/EditorWindow/editorwindowview.cpp
        QtApplication/MainWidgets/EditorWindow/editorwindowview.h
        QtApplication/MainWidgets/ToolDock/tooldock.cpp
        QtApplication/MainWidgets/ToolDock/tooldock.h
        QtApplication/MainWidgets/ImageViewer/imageviewerview.cpp
        QtApplication/MainWidgets/ImageViewer/imageviewerview.h
        QtApplication/MainWidgets/ToolBar/toolbar.cpp
        QtApplication/MainWidgets/ToolBar/toolbar.h
        QtApplication/ToolService/toolservice.cpp
        QtApplication/ToolService/toolservice.h
        QtApplication/Utility/Logger/logger.cpp
        QtApplication/logger.h
        QtApplication/MainWidgets/ToolDock/itooldock.h
        QtApplication/MainWidgets/ToolBar/itoolbar.h
        QtApplication/ToolService/toolcontext.cpp
        QtApplication/ToolService/toolcontext.h
        QtApplication/ToolService/toolunit.h
        QtApplication/ToolService/Tool/itoolmodel.h
        QtApplication/ToolService/toolunitview.cpp
        QtApplication/ToolService/toolunitview.h
        QtApplication/ToolService/toolunit.cpp QtApplication/ToolService/ToolCategory/toolcategory.cpp QtApplication/ToolService/ToolCategory/toolcategory.h QtApplication/ToolService/ToolCategory/toolcategorymodel.cpp QtApplication/ToolService/ToolCategory/toolcategorymodel.h QtApplication/ToolService/ToolCategory/BrushCategory/brushcategory.cpp QtApplication/ToolService/ToolCategory/BrushCategory/brushcategory.h QtApplication/ToolService/ToolCategory/BrushCategory/brushcategorymodel.cpp QtApplication/ToolService/ToolCategory/BrushCategory/brushcategorymodel.h QtApplication/ToolService/ToolCategory/BrushCategory/brushcategoryview.cpp QtApplication/ToolService/ToolCategory/BrushCategory/brushcategoryview.h QtApplication/ToolService/ToolCategory/ShapeCategory/shapecategory.cpp QtApplication/ToolService/ToolCategory/ShapeCategory/shapecategory.h QtApplication/ToolService/ToolCategory/ShapeCategory/shapecategoryview.cpp QtApplication/ToolService/ToolCategory/ShapeCategory/shapecategoryview.h QtApplication/ToolService/Tool/Brush-like/Brush/brush.cpp QtApplication/ToolService/Tool/Brush-like/Brush/brush.h QtApplication/ToolService/Tool/Brush-like/Brush/brushview.cpp QtApplication/ToolService/Tool/Brush-like/Brush/brushview.h QtApplication/ToolService/Tool/Brush-like/Brush/brushmodel.cpp QtApplication/ToolService/Tool/Brush-like/Brush/brushmodel.h QtApplication/ToolService/Tool/tool.cpp QtApplication/ToolService/Tool/tool.h QtApplication/ToolService/ToolCategory/ShapeCategory/shapecategorymodel.cpp QtApplication/ToolService/ToolCategory/ShapeCategory/shapecategorymodel.h QtApplication/ToolService/Tool/Brush-like/Pen/pen.cpp QtApplication/ToolService/Tool/Brush-like/Pen/pen.h QtApplication/ToolService/Tool/Brush-like/Pen/penview.cpp QtApplication/ToolService/Tool/Brush-like/Pen/penview.h QtApplication/ToolService/Tool/Brush-like/Pen/penmodel.cpp QtApplication/ToolService/Tool/Brush-like/Pen/penmodel.h QtApplication/ToolService/ToolCategory/toolcategoryview.cpp QtApplication/ToolService/ToolCategory/toolcategoryview.h QtApplication/MainWidgets/ImageViewer/imagecontainer.cpp QtApplication/MainWidgets/ImageViewer/imagecontainer.h QtApplication/MainWidgets/ImageViewer/icanvas.h QtApplication/MainWidgets/EditorWindow/editorwindow.cpp QtApplication/Utility/ImageReader/imagereader.cpp QtApplication/Utility/ImageReader/imagereader.h QtApplication/Utility/imageio.h QtApplication/Utility/ImageWriter/imagewriter.cpp QtApplication/Utility/ImageWriter/imagewriter.h QtApplication/MainWidgets/EditorWindow/editorwindow.h QtApplication/MainWidgets/ImageViewer/imageviewer.cpp QtApplication/MainWidgets/ImageViewer/imageviewer.h)

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