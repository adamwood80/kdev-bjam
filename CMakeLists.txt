project(kdevelop_boostbuild)

set(KDE4_BUILD_TESTS "ON" CACHE "BOOL" "Enable building of tests" FORCE )

find_package(KDE4 4.5.0 REQUIRED)
include(KDE4Defaults)
include(MacroLibrary)
find_package(KDevPlatform 1.3.60 REQUIRED)

if(KDevPlatform_VERSION VERSION_GREATER 1.4.59)
    MESSAGE(FATAL_ERROR "This version of the plugin doesn't work with KDevPlatform 1.5, version 1.4 is required")
endif(KDevPlatform_VERSION VERSION_GREATER 1.4.59)

set(BOOST_BUILD_PLUGIN_VERSION 0.0.1)

include_directories( ${KDE4_INCLUDES} ${KDEVPLATFORM_INCLUDE_DIR} ${QT_INCLUDES})

add_definitions( ${QT_DEFINITIONS} ${KDE4_DEFINITIONS} -DBOOST_BUILD_PLUGIN_VERSION=\\\"${CUSTOM_BUILDSYSTEM_VERSION}\\\" )

set(kdevelop_boostbuild_SRCS boostbuildmanager.cpp)

kde4_add_plugin(kdevelop_boostbuild ${kdevelop_boostbuild_SRCS})

target_link_libraries(kdevelop_boostbuild ${KDE4_KDEUI_LIBS}
                      ${KDEVPLATFORM_PROJECT_LIBRARIES}
                      ${KDEVPLATFORM_INTERFACES_LIBRARIES}
                      ${KDEVPLATFORM_UTIL_LIBRARIES}
                      ${KDEVPLATFORM_OUTPUTVIEW_LIBRARIES}
                      ${KDEVPLATFORM_LANGUAGE_LIBRARIES}
                      )

install(TARGETS kdevelop_boostbuild DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES kdevelop_boostbuild.rc DESTINATION ${DATA_INSTALL_DIR}/kdevelop_boostbuild)

install(FILES kdevelop_boostbuild.desktop DESTINATION ${SERVICES_INSTALL_DIR})
 
