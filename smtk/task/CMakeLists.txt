# Tasks are classes (with header and source files) that also have
# JSON classes (with header and source files).
set(tasks
  FillOutAttributes
  GatherResources
  Group
  SubmitOperation
  Task
)

set(adaptors
  ConfigureOperation
  ResourceAndRole
)

set(operations
  AddDependency
  EmplaceWorklet
  RemoveDependency
  RenameTask
)

set(taskSrcs
  Active.cxx
  Adaptor.cxx
  Gallery.cxx
  Instances.cxx
  Manager.cxx
  Registrar.cxx
  Worklet.cxx
  adaptor/ResourceAndRole.cxx
  json/Configurator.cxx
  json/Helper.cxx
  json/jsonManager.cxx
  json/jsonAdaptor.cxx
  json/jsonWorklet.cxx
)

set(taskHeaders
  Active.h
  Adaptor.h
  Gallery.h
  Instances.h
  Manager.h
  Registrar.h
  State.h
  Worklet.h
  adaptor/Instances.h
  adaptor/ResourceAndRole.h
  json/Configurator.h
  json/Configurator.txx
  json/Helper.h
  json/jsonAdaptor.h
  json/jsonManager.h
  json/jsonWorklet.h
)

foreach(task ${tasks})
  list(APPEND taskSrcs ${task}.cxx json/json${task}.cxx)
  list(APPEND taskHeaders ${task}.h json/json${task}.h)
endforeach()

foreach(operation ${operations})
  list(APPEND taskHeaders operators/${operation}.h)
  list(APPEND taskSrcs operators/${operation}.cxx)
  if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/operators/${operation}.sbt")
    smtk_encode_file(
      "${CMAKE_CURRENT_SOURCE_DIR}/operators/${operation}.sbt"
      HEADER_OUTPUT headerName
    )
    list(APPEND _taskDependencies ${headerName})
  endif()
endforeach()
add_custom_target(taskGenHeaders DEPENDS ${_taskDependencies})

foreach(adaptor ${adaptors})
  list(APPEND taskSrcs adaptor/${adaptor}.cxx json/json${adaptor}.cxx)
  list(APPEND taskHeaders adaptor/${adaptor}.h json/json${adaptor}.h)
endforeach()

if (SMTK_ENABLE_PYTHON_WRAPPING)
  add_subdirectory(pybind11)
endif()

#install the headers
smtk_public_headers(smtkCore ${taskHeaders})

if (SMTK_ENABLE_PARAVIEW_SUPPORT)
  set_property(GLOBAL APPEND
    PROPERTY _smtk_plugin_files "${CMAKE_CURRENT_SOURCE_DIR}/plugin/paraview.plugin")
endif()

if (SMTK_ENABLE_TESTING)
  add_subdirectory(testing)
endif()
