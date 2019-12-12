set(TESTS_WITH_BASELINES
  ${CMAKE_CURRENT_SOURCE_DIR}/OpenExodusFile.xml)

include(SMTKPVTestingMacros)

#TODO: this should be set for the entire project's xml tests
set(OpenExodusFile_USES_DIRECT_DATA ON)

smtk_add_client_tests(
#  LABEL "pv_meshsession"
  TEST_SCRIPTS ${TESTS_WITH_BASELINES}
  LOAD_PLUGINS
    smtkMeshSessionPlugin
    smtkPVServerExtPlugin
    smtkPQComponentsPlugin
  PLUGIN_PATHS
    $<TARGET_FILE_DIR:smtkMeshSessionPlugin>/..
    $<TARGET_FILE_DIR:smtkPQComponentsPlugin>/..
    $<TARGET_FILE_DIR:smtkPVServerExtPlugin>/..
  DATA_DIRECTORY ${PROJECT_SOURCE_DIR}/data
  BASELINE_DIR ${PROJECT_SOURCE_DIR}/data/baseline/smtk/mesh
  )