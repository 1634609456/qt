cmake_minimum_required(VERSION 3.16)

project(shm-viewer VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(ElaWidgetTools REQUIRED PATHS ${CMAKE_SOURCE_DIR}/3rdparty/ElaWidgetTools/lib/cmake NO_DEFAULT_PATH)

set(QDEVTOOLS_DIR ${CMAKE_SOURCE_DIR}/3rdparty/QDevtools)

set(PROCON_DIR ${CMAKE_SOURCE_DIR}/3rdparty/procon)

find_package(webview REQUIRED PATHS ${CMAKE_SOURCE_DIR}/3rdparty/webview/lib/cmake NO_DEFAULT_PATH)

find_package(concurrentqueue REQUIRED PATHS ${CMAKE_SOURCE_DIR}/3rdparty/concurrentqueue/lib/cmake NO_DEFAULT_PATH)
find_package(readerwriterqueue REQUIRED PATHS ${CMAKE_SOURCE_DIR}/3rdparty/readerwriterqueue/lib/cmake NO_DEFAULT_PATH)

set(BUILD_BENCHMARK OFF)
set(BUILD_EXAMPLES OFF)
set(BUILD_UNIT_TESTS OFF)
set(ENABLE_SANITIZER OFF)
set(ENABLE_SQLITE3 ON)
add_definitions(-DORMPP_ENABLE_SQLITE3)
add_subdirectory(${CMAKE_SOURCE_DIR}/3rdparty/ormpp)

set(QRC_FILES
    res.qrc
)

set(SRC_FILES
    src/main.cpp
    src/util/shm_manager.hpp
    src/model/motor_config_model.hpp
    src/model/motor_feb_model.hpp
    src/model/io_model.hpp
    src/delegate/light_delegate.hpp
)

set(UI_FILES
    ui/form/form.ui
    ui/form/form.cpp
    ui/home_page/homepage.ui
    ui/home_page/homepage.cpp
    ui/main_flyer/mainflyer.ui
    ui/main_flyer/mainflyer.cpp
    ui/feeding/feeding.ui
    ui/feeding/feeding.cpp
    ui/middle_circuit_breaker/middelcircuitbreaker.ui
    ui/middle_circuit_breaker/middelcircuitbreaker.cpp
    ui/beside_pass/besidepass.ui
    ui/beside_pass/besidepass.cpp
    ui/blanking/blanking.ui
    ui/blanking/blanking.cpp
    ui/main_window.hpp
    ui/data_monitor_page.hpp
    ui/chart_page.hpp
    ui/config_page.hpp
    ui/param_page.hpp
    ${QDEVTOOLS_DIR}/qdevtools.cpp
    ${QDEVTOOLS_DIR}/qdevtool.ui
)

set(PROJECT_SOURCES
    ${SRC_FILES} ${UI_FILES} ${QRC_FILES}
)

find_program(QT_LUPDATE NAMES lupdate lupdate-qt6)
find_program(QT_LRELEASE NAMES lrelease lrelease-qt6)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${PROJECT_SOURCES})
    # Define target properties for Android with Qt 6 as: set_property(TARGET
    # ${PROJECT_NAME} APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    # ${CMAKE_CURRENT_SOURCE_DIR}/android) For more information, see
    # https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(
            ${PROJECT_NAME} SHARED
            ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(
            ${PROJECT_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
        ${ElaWidgetTools_INCLUDE_DIRS}
        ${QDEVTOOLS_DIR}
        ${CMAKE_SOURCE_DIR}/3rdparty/ormpp
        ${PROCON_DIR}/include
	)

target_link_directories(${PROJECT_NAME} PRIVATE
        ${ElaWidgetTools_LIBRARY_DIRS}
        ${PROCON_DIR}/x64
	)

target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt${QT_VERSION_MAJOR}::Widgets
        ElaWidgetTools
        webview::core
        # ormpp
        sqlite3
        concurrentqueue::concurrentqueue
        readerwriterqueue::readerwriterqueue
        NoSys
        YKCat2
	)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1. If
# you are developing for iOS or macOS you should consider setting an explicit,
# fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION
        MACOSX_BUNDLE_GUI_IDENTIFIER com.example.${PROJECT_NAME}
    )
endif()
set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        ${BUNDLE_ID_OPTION} MACOSX_BUNDLE_BUNDLE_VERSION
        ${PROJECT_VERSION} MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE FALSE
)

include(GNUInstallDirs)
install(
    TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

set(QT_SDK_DIR "D:/Qt/6.7.3/msvc2022_64")

if (WIN32)
    include(GNUInstallDirs)
    install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
    )
    if (MSVC)
        install(
            FILES $<TARGET_PDB_FILE:${PROJECT_NAME}>
            DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME} OPTIONAL)
    endif ()
    # QT依赖安装 只做Release安装 Debug自行打包
    install(FILES ${QT_SDK_DIR}/plugins/platforms/qwindows.dll DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/platforms)
    install(FILES ${QT_SDK_DIR}/plugins/generic/qtuiotouchplugin.dll DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/generic)
    install(
        FILES ${QT_SDK_DIR}/plugins/imageformats/qgif.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qicns.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qico.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qjpeg.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qtga.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qtiff.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qwbmp.dll
        FILES ${QT_SDK_DIR}/plugins/imageformats/qwebp.dll
        DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/imageformats
    )
    install(FILES ${QT_SDK_DIR}/plugins/styles/qmodernwindowsstyle.dll DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/styles)
    FILE(GLOB TRANSLATIONS ${QT_SDK_DIR}/translations_install/*.qm)
    install(FILES ${TRANSLATIONS} DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}/translations)
    install(
        FILES ${QT_SDK_DIR}/bin/Qt${QT_VERSION_MAJOR}Widgets.dll
        FILES ${QT_SDK_DIR}/bin/Qt${QT_VERSION_MAJOR}Core.dll
        FILES ${QT_SDK_DIR}/bin/Qt${QT_VERSION_MAJOR}Gui.dll
        FILES ${QT_SDK_DIR}/bin/Qt${QT_VERSION_MAJOR}Network.dll
        FILES ${QT_SDK_DIR}/bin/Qt${QT_VERSION_MAJOR}Xml.dll
        DESTINATION ${CMAKE_INSTALL_PREFIX}/${PROJECT_NAME}
    )
endif ()
