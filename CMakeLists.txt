cmake_minimum_required(VERSION 3.5)
project(ImageEditor)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "D:\\Qt\\6.3.0\\mingw_64")

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
        main.cpp
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
        QtApplication/Service/ToolService/Generics/toolunit.h
        QtApplication/Service/ToolService/Tool/toolmodel.h
        QtApplication/Service/ToolService/Generics/toolunitview.cpp
        QtApplication/Service/ToolService/Generics/toolunitview.h
        QtApplication/Service/ToolService/Generics/toolunit.cpp QtApplication/Service/ToolService/ToolCategory/toolcategory.cpp QtApplication/Service/ToolService/ToolCategory/toolcategory.h QtApplication/Service/ToolService/ToolCategory/toolcategorymodel.inl QtApplication/Service/ToolService/ToolCategory/toolcategorymodel.h QtApplication/Service/ToolService/ToolCategory/ImageTools/imagetools.cpp QtApplication/Service/ToolService/ToolCategory/ImageTools/imagetools.h QtApplication/Service/ToolService/ToolCategory/ImageTools/imagetoolsmodel.cpp QtApplication/Service/ToolService/ToolCategory/ImageTools/imagetoolsmodel.h QtApplication/Service/ToolService/ToolCategory/FigureCategory/figurecategory.cpp QtApplication/Service/ToolService/ToolCategory/FigureCategory/figurecategory.h QtApplication/Service/ToolService/Tool/tool.cpp QtApplication/Service/ToolService/Tool/tool.h QtApplication/Service/ToolService/ToolCategory/FigureCategory/figurecategorymodel.cpp QtApplication/Service/ToolService/ToolCategory/FigureCategory/figurecategorymodel.h QtApplication/Service/ToolService/ToolCategory/toolcategoryview.cpp QtApplication/Service/ToolService/ToolCategory/toolcategoryview.h QtApplication/MainWidgets/ImageViewer/imagecontainer.cpp QtApplication/MainWidgets/ImageViewer/imagecontainer.h QtApplication/MainWidgets/EditorWindow/editorwindow.cpp QtApplication/Service/ImageLoader/imageloader.cpp QtApplication/Service/ImageLoader/imageloader.h QtApplication/Service/ImageSaver/imagesaver.cpp QtApplication/Service/ImageSaver/imagesaver.h QtApplication/MainWidgets/EditorWindow/editorwindow.h QtApplication/MainWidgets/ImageViewer/imageviewer.cpp QtApplication/MainWidgets/ImageViewer/imageviewer.h QtApplication/Service/Painter/painter.cpp QtApplication/Service/Painter/painter.h QtApplication/Service/UndoService/undoservice.cpp QtApplication/Service/UndoService/undoservice.h QtApplication/Service/UndoService/Command/additemcommand.cpp QtApplication/Service/UndoService/Command/additemcommand.h QtApplication/MainWidgets/ImageViewer/igraphicsview.h QtApplication/Service/ToolService/ToolCategory/FigureCategory/ParametersInterface/shapeparametersinterface.cpp QtApplication/Service/ToolService/ToolCategory/FigureCategory/ParametersInterface/shapeparametersinterface.h QtApplication/Service/ToolService/Tool/Figure/shape.inl QtApplication/Service/ToolService/Tool/Figure/shape.h QtApplication/Service/ToolService/Tool/Figure/shapemodel.inl QtApplication/Service/ToolService/Tool/Figure/shapemodel.h QtApplication/Service/ToolService/Tool/Figure/Ellipse/ellipse.cpp QtApplication/Service/ToolService/Tool/Figure/Ellipse/ellipse.h QtApplication/Service/ToolService/Tool/Figure/Rect/rect.cpp QtApplication/Service/ToolService/Tool/Figure/Rect/rect.h QtApplication/Service/ToolService/Tool/Figure/Line/line.cpp QtApplication/Service/ToolService/Tool/Figure/Line/line.h QtApplication/Service/ToolService/Tool/Figure/Line/linemodel.cpp QtApplication/Service/ToolService/Tool/Figure/Line/linemodel.h QtApplication/Service/ToolService/ToolCategory/FigureCategory/ParametersInterface/lineparametersinterface.cpp QtApplication/Service/ToolService/ToolCategory/FigureCategory/ParametersInterface/lineparametersinterface.h QtApplication/Service/ToolService/ToolCategory/FigureCategory/ParametersInterface/parametersinterface.cpp QtApplication/Service/ToolService/ToolCategory/FigureCategory/ParametersInterface/parametersinterface.h QtApplication/Service/ToolService/Tool/Figure/figure.h QtApplication/Service/ToolService/Tool/Figure/figure.cpp QtApplication/Service/ToolService/Tool/Figure/Rect/rectitem.cpp QtApplication/Service/ToolService/Tool/Figure/Rect/rectitem.h QtApplication/Service/ToolService/Tool/Figure/Ellipse/ellipseitem.cpp QtApplication/Service/ToolService/Tool/Figure/Ellipse/ellipseitem.h QtApplication/Service/ToolService/Tool/Figure/Line/lineitem.cpp QtApplication/Service/ToolService/Tool/Figure/Line/lineitem.h "QtApplication/Core/StateMachine/context.inl" QtApplication/Core/StateMachine/context.h QtApplication/Service/ToolService/Generics/toolcontext.inl QtApplication/Service/ToolService/Generics/toolcontext.h QtApplication/Service/ToolService/ToolCategory/itoolcategorymodel.h QtApplication/Service/ToolService/Generics/toolcontextobject.cpp QtApplication/Service/ToolService/Generics/toolcontextobject.h QtApplication/Service/ToolService/Tool/Figure/figuremodel.cpp QtApplication/Service/ToolService/Tool/Figure/figuremodel.h QtApplication/Service/ToolService/Tool/Figure/Triangle/triangle.cpp QtApplication/Service/ToolService/Tool/Figure/Triangle/triangle.h QtApplication/Service/ToolService/Tool/Figure/Triangle/triangleitem.cpp QtApplication/Service/ToolService/Tool/Figure/Triangle/triangleitem.h QtApplication/Service/ToolService/Tool/Image/Marquee/marquee.h QtApplication/Service/ToolService/Tool/Image/Marquee/marqueemodel.inl QtApplication/Service/ToolService/Tool/Image/Marquee/marqueemodel.h QtApplication/Service/ToolService/Tool/toolmodel.cpp QtApplication/Service/ToolService/MarqueeItem/marqueeitem.cpp QtApplication/Service/ToolService/MarqueeItem/marqueeitem.h QtApplication/Service/ToolService/Tool/Image/Marquee/ellipsemarqueeitem.cpp QtApplication/Service/ToolService/Tool/Image/Marquee/ellipsemarqueeitem.h QtApplication/Service/ToolService/Tool/Image/EllipseColorInverter/ellipsecolorinverter.cpp QtApplication/Service/ToolService/Tool/Image/EllipseColorInverter/ellipsecolorinverter.h QtApplication/Service/ToolService/Tool/Image/Marquee/marquee.inl QtApplication/Service/ToolService/Tool/Figure/ishapemodel.h QtApplication/Service/ToolService/Tool/Image/Marquee/marqueeobject.cpp QtApplication/Service/ToolService/Tool/Image/Marquee/marqueeobject.h QtApplication/Data/data.cpp QtApplication/Data/data.h QtApplication/Service/ColorInverterWorker/colorinverterworker.cpp QtApplication/Service/ColorInverterWorker/colorinverterworker.h Library/Service/Benchmark/benchmark.inl Library/Service/Benchmark/benchmark.h Library/Service/FigureCalculator/calculator.cpp Library/Service/FigureCalculator/calculator.h QtApplication/Service/ToolService/Tool/Image/PixmapItem/pixmapitem.cpp QtApplication/Service/ToolService/Tool/Image/PixmapItem/pixmapitem.h QtApplication/Service/ToolService/Tool/Image/EllipseColorInverter/ellipsepixmapitem.cpp QtApplication/Service/ToolService/Tool/Image/EllipseColorInverter/ellipsepixmapitem.h QtApplication/Service/ToolService/Tool/Image/Crop/crop.cpp QtApplication/Service/ToolService/Tool/Image/Crop/crop.h QtApplication/Service/UndoService/Command/focusoncommand.cpp QtApplication/Service/UndoService/Command/focusoncommand.h Library/figurepoints.h Library/Service/FigureCalculator/Type/ellipse.cpp Library/Service/FigureCalculator/Type/ellipse.h Library/Service/FigureCalculator/constants.h Library/Bitmap/loader.cpp Library/Bitmap/loader.h Library/Bitmap/image.cpp Library/Bitmap/image.h Library/Bitmap/saver.cpp Library/Bitmap/saver.h Library/datastructures.h Library/iimage.h Library/Service/ColorInverter/colorinverter.cpp Library/Service/ColorInverter/colorinverter.h Test/tester.cpp Test/tester.h Library/Bitmap/bitmapheader.h Library/Service/Painter/painter.cpp Library/Service/Painter/painter.h Library/Service/FigureCalculator/Type/line.cpp Library/Service/FigureCalculator/Type/line.h Library/Service/FloodFiller/floodfiller.cpp Library/Service/FloodFiller/floodfiller.h Library/Service/FigureCalculator/Type/triangle.cpp Library/Service/FigureCalculator/Type/triangle.h QtApplication/Service/CommandInterface/commandinterface.cpp QtApplication/Service/CommandInterface/commandinterface.h QtApplication/Service/CommandInterface/command.h QtApplication/Service/CommandInterface/commandcontroller.cpp QtApplication/Service/CommandInterface/commandcontroller.h QtApplication/Service/CommandInterface/commandinformation.h QtApplication/Service/CommandInterface/command.cpp QtApplication/Service/CommandInterface/commandinformation.cpp)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME}
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
else ()
    add_executable(${PROJECT_NAME}
            ${PROJECT_SOURCES}
            )
endif ()

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ImageEditor)
endif ()

set_property(TARGET ${PROJECT_NAME} PROPERTY WIN32_EXECUTABLE true)

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
    foreach (QT_LIB Core Gui Widgets Concurrent)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
