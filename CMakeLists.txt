project(ktexteditor_kde-bjam)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include_directories(${KDE4_INCLUDES} ${QT_INCLUDES})
add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})

set(ktexteditor_kde-bjam_SRCS kde-bjamplugin.cpp)

kde4_add_plugin(ktexteditor_kde-bjam ${ktexteditor_kde-bjam_SRCS})

target_link_libraries(ktexteditor_kde-bjam ${KDE4_KDEUI_LIBS} ${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS ktexteditor_kde-bjam DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES kde-bjamui.rc DESTINATION ${DATA_INSTALL_DIR}/ktexteditor_kde-bjam)

install(FILES ktexteditor_kde-bjam.desktop DESTINATION ${SERVICES_INSTALL_DIR})
 
