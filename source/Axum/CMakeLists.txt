#
# External dependencies
#

find_package(Boost 1.72.0 REQUIRED COMPONENTS filesystem serialization)
find_package(spdlog CONFIG REQUIRED)
find_package(OpenImageIO REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)
find_package(glbinding CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(unofficial-nativefiledialog CONFIG REQUIRED)

#
# Executable name and options
#

# Target name
set(target Axum)

# Exit here if required dependencies are not met
if(NOT BOOST_FOUND)
  message(STATUS "${target} skipped: Boost  not found")
  return()
else()
  message(STATUS "${target} : Boost found")
endif()

#
# Sources
#

list(
  APPEND
  sources
  main.cpp
  MApplication.h
  MApplication.cpp
  Addon/Addon.h
  Addon/Addon.cpp
  # Bakery tools
  Bakery/Baker.h
  Bakery/Baker.cpp
  Bakery/Bakery.h
  Bakery/Bakery.cpp
  # 3d View port rendering utilities
  Draw/RenderEngine.h
  Draw/RenderEngine.cpp
  Draw/Engines/GLEngine.h
  Draw/Engines/GLEngine.cpp
  # IO utils
  IO/ImageIO.h
  IO/ImageIO.cpp
  # Managers
  Managers/AddonManager.h
  Managers/AddonManager.cpp
  Managers/PackageManager.h
  Managers/PackageManager.cpp
  Managers/PreferenceManager.h
  Managers/PreferenceManager.cpp
  Managers/RenderManager.h
  Managers/RenderManager.cpp
  Managers/UndoManager.h
  Managers/UndoManager.cpp
  Managers/WindowManager.h
  Managers/WindowManager.cpp
  # Operators
  Operators/operator.h
  Operators/operator.cpp
  Operators/ResourceOperators/AddNewImgTexOP.h
  Operators/ResourceOperators/AddNewImgTexOP.cpp
  # Node Graph
  NodeGraph/LogicGraph.h
  NodeGraph/LogicGraph.cpp
  NodeGraph/Graph.h
  NodeGraph/Graph.cpp
  NodeGraph/InputSocket.h
  NodeGraph/InputSocket.cpp
  NodeGraph/Material.h
  NodeGraph/MaterialGraph.h
  NodeGraph/MaterialGraph.cpp
  NodeGraph/Node.h
  NodeGraph/Node.cpp
  NodeGraph/OutputSocket.h
  NodeGraph/OutputSocket.cpp
  NodeGraph/Nodes/AtomicNodes.h
  NodeGraph/Nodes/AtomicNodes.cpp
  NodeGraph/Nodes/CommentNode.h
  NodeGraph/Nodes/CommentNode.cpp
  NodeGraph/Nodes/LogicNode.h
  NodeGraph/Nodes/LogicNode.cpp
  NodeGraph/Nodes/LogicNodes.h
  NodeGraph/Nodes/LogicNodes.cpp
  NodeGraph/Nodes/LogicGraphNode.h
  NodeGraph/Nodes/LogicGraphNode.cpp
  NodeGraph/Nodes/MaterialGraphInstanceNode.h
  NodeGraph/Nodes/MaterialGraphInstanceNode.cpp
  NodeGraph/Nodes/MaterialNode.h
  NodeGraph/Nodes/MaterialNode.cpp
  NodeGraph/NodeGraphHelpers.h
  NodeGraph/Link.h
  NodeGraph/Link.cpp
  # Parameters
  Parameter/BooleanParam.h
  Parameter/BooleanParam.cpp
  Parameter/EnumParam.h
  Parameter/EnumParam.cpp
  Parameter/FloatVectorParam.h
  Parameter/FloatVectorParam.cpp
  Parameter/FloatParam.h
  Parameter/FloatParam.cpp
  Parameter/IntegerVectorParam.h
  Parameter/IntegerVectorParam.cpp
  Parameter/IntegerParam.h
  Parameter/IntegerParam.cpp
  Parameter/Param.h
  Parameter/Param.cpp
  Parameter/ParamCollection.h
  Parameter/ParamCollection.cpp
  Parameter/ProxyParam.h
  Parameter/ProxyParam.cpp
  Parameter/TextParam.h
  Parameter/TextParam.cpp
  Parameter/ParameterGroup.h
  Parameter/ParameterGroup.cpp
  # Resource types
  ResourceTypes/ImageTexture.h
  ResourceTypes/ImageTexture.cpp
  ResourceTypes/Folder.h
  ResourceTypes/Folder.cpp
  ResourceTypes/Font.h
  ResourceTypes/Font.cpp
  ResourceTypes/Resource.h
  ResourceTypes/Resource.cpp
  ResourceTypes/Scene.h
  ResourceTypes/Scene.cpp
  ResourceTypes/VectorTexture.h
  ResourceTypes/VectorTexture.cpp
  ResourceTypes/Package.h
  ResourceTypes/Package.cpp
  # UI Elements
  UI/MainWindow.h
  UI/MainWindow.cpp
  UI/SplashWindow.h
  UI/SplashWindow.cpp
  # Editor UI classes
  UI/Editors/Editor.h
  UI/Editors/Editor.cpp
  UI/Editors/TextureViewer/TextureViewer.h
  UI/Editors/TextureViewer/TextureViewer.cpp
  UI/Editors/Viewport/Viewport.h
  UI/Editors/Viewport/Viewport.cpp
  UI/Editors/Outliner/Outliner.h
  UI/Editors/Outliner/Outliner.cpp
  UI/Editors/LogicEditor/LogicEditor.h
  UI/Editors/LogicEditor/LogicEditor.cpp
  UI/Editors/AssetManager/AssetManager.h
  UI/Editors/AssetManager/AssetManager.cpp
  UI/Editors/MaterialEditor/MaterialEditor.h
  UI/Editors/MaterialEditor/MaterialEditor.cpp
  UI/Editors/GraphEditor/GraphEditor.h
  UI/Editors/GraphEditor/GraphEditor.cpp
  UI/Editors/ParameterEditor/ParameterEditor.h
  UI/Editors/ParameterEditor/ParameterEditor.cpp
  # Widgets
  UI/Widgets/Dialogs.h
  UI/Widgets/Dialogs.cpp
  # Logging Utilities
  Utils/Log/Log.h
  Utils/Log/Log.cpp
  # Runtime path utilities
  Utils/PathUtils/PathUtils.h
  Utils/PathUtils/PathUtils.cpp
  # Translation
  Utils/Translation/Translation.h
  Utils/Translation/Translation.cpp)

if(OPTION_WITH_CYCLES)
  list(APPEND sources Draw/Engines/CyclesEngine.h Draw/Engines/CyclesEngine.cpp)
endif()

#
# Create executable
#

# Build executable
add_executable(${target} MACOSX_BUNDLE ${sources})

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})

#
# Project options
#

set_target_properties(${target} PROPERTIES ${DEFAULT_PROJECT_OPTIONS} FOLDER
                                           "${IDE_FOLDER}")

#
# Include directories
#

target_include_directories(
  ${target}
  PRIVATE ${DEFAULT_INCLUDE_DIRECTORIES} ${CMAKE_CURRENT_BINARY_DIR}
          ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_BINARY_DIR}/source/include)

#
# Libraries
#

target_link_libraries(
  ${target}
  PRIVATE ${DEFAULT_LIBRARIES}
          ${META_PROJECT_NAME}::ABaker
          Boost::filesystem
          Boost::serialization
          spdlog::spdlog_header_only
          imgui::imgui
          imnodes
          fmt::fmt-header-only
          glbinding::glbinding
          glfw
          OpenImageIO::OpenImageIO
          unofficial::nativefiledialog::nfd)

#
# Compile definitions
#

target_compile_definitions(${target} PRIVATE ${DEFAULT_COMPILE_DEFINITIONS})

#
# Compile options
#

target_compile_options(${target} PRIVATE ${DEFAULT_COMPILE_OPTIONS})

#
# Linker options
#

target_link_libraries(${target} PRIVATE ${DEFAULT_LINKER_OPTIONS})

#
# Dependencies
#

add_dependencies(${target} imnodes)

#
# Target Health
#

perform_health_checks(${target} ${sources})

#
# Deployment
#

# Executable
install(
  TARGETS ${target}
  RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT Axum
  BUNDLE DESTINATION ${INSTALL_BIN} COMPONENT Axum)
