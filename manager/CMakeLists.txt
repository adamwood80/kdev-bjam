set(kdevelop_boostbuild_SRCS boostbuildmanager.cpp)

kde4_add_plugin(kdevboostbuildmanager ${kdevelop_boostbuild_SRCS})

target_link_libraries(kdevboostbuildmanager ${KDE4_KDEUI_LIBS}
                      ${KDEVPLATFORM_PROJECT_LIBRARIES}
                      ${KDEVPLATFORM_INTERFACES_LIBRARIES}
                      ${KDEVPLATFORM_UTIL_LIBRARIES}
                      ${KDEVPLATFORM_OUTPUTVIEW_LIBRARIES}
                      ${KDEVPLATFORM_LANGUAGE_LIBRARIES}
                      )

install(TARGETS kdevboostbuildmanager DESTINATION ${PLUGIN_INSTALL_DIR})

#install(FILES kdevboostbuildmanager.rc DESTINATION ${DATA_INSTALL_DIR}/kdevboostbuildmanager)

install(FILES kdevboostbuildmanager.desktop DESTINATION ${SERVICES_INSTALL_DIR})
