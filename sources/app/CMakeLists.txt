set(APP_NAME ${PROJECT_NAME}App)

qt_add_executable(${APP_NAME} main.cpp)


target_link_libraries(${APP_NAME} PRIVATE
  example::SomeLib
  Qt6::Widgets
)

set_target_properties(${APP_NAME} PROPERTIES
  WIN32_EXECUTABLE ON
  MACOSX_BUNDLE ON
  MACOSX_BUNDLE_GUI_IDENTIFIER "com.example.projecttemplateapp"
  XCODE_ATTRIBUTE_CODE_SIGNING_REQUIRED OFF
  XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY ""
  XCODE_ATTRIBUTE_CODE_SIGN_STYLE "Manual"
  XCODE_ATTRIBUTE_CODE_SIGN_INJECT_BASE_ENTITLEMENTS OFF
)

set(DEPLOY_TOOL_OPTIONS_ARG "")
# if(APPLE)
#   set(DEPLOY_TOOL_OPTIONS_ARG --hardened-runtime)
# elseif(WIN32)
#   set(DEPLOY_TOOL_OPTIONS_ARG --no-compiler-runtime)
# endif()

set(EXECUTABLE_PATH "$<TARGET_FILE_NAME:${APP_NAME}>.app")
qt_generate_deploy_script(
    TARGET ${APP_NAME}
    OUTPUT_SCRIPT DEPLOY_SCRIPT
    CONTENT "
qt_deploy_runtime_dependencies(
    EXECUTABLE \"${EXECUTABLE_PATH}\"
    DEPLOY_TOOL_OPTIONS \"${DEPLOY_TOOL_OPTIONS_ARG}\"
    GENERATE_QT_CONF
    VERBOSE
    NO_APP_STORE_COMPLIANCE
)")

install(TARGETS ${APP_NAME}
    BUNDLE  DESTINATION .
)

install(SCRIPT "${DEPLOY_SCRIPT}")

include(CPack)
set(CPACK_GENERATOR "DragNDrop")
set(CPACK_PACKAGE_FILE_NAME "${APP_NAME} Installer") # The name of the generated package
set(CPACK_BUNDLE_NAME "${APP_NAME}") # The name of the app bundle
