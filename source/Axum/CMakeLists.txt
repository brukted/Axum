#
# Resource embedding
#

# Include the extension module.
list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/GCR")

include(GlibCompileResourcesSupport)

# Set the resources to bundle.
set(RESOURCE_LIST
    TOPIXDATA COMPRESS "${CMAKE_SOURCE_DIR}/resources/splash.png")

# Compile the resources.
compile_gresources(RESOURCE_FILE
                   XML_OUT
                   TYPE EMBED_C
                   TARGET "embedded-resources.h"
                   RESOURCES ${RESOURCE_LIST})
add_custom_target(resource ALL DEPENDS ${RESOURCE_FILE})

message(STATUS "${XML_OUT}")


# 
# External dependencies
# 

find_package(PkgConfig REQUIRED QUIET)

if (NOT PkgConfig_FOUND )
   message(STATUS "${target} skipped: PkgConfig  not found")
    return()
else()
    message(STATUS "${target} : PkgConfig found")
endif()

find_package(Boost 1.72.0 REQUIRED COMPONENTS filesystem serialization)
pkg_search_module (GTKMM REQUIRED IMPORTED_TARGET gtkmm-3.0)
pkg_search_module (SPD_LOG REQUIRED IMPORTED_TARGET spdlog)
pkg_search_module (EPOXY REQUIRED IMPORTED_TARGET libepoxy epoxy)
pkg_search_module (LIB_SIGNAL REQUIRED IMPORTED_TARGET sigc++-3.0)
pkg_search_module (OIIO REQUIRED IMPORTED_TARGET OpenImageIO>=2.1)
pkg_search_module (FMT REQUIRED IMPORTED_TARGET fmt>=6.2)
pkg_search_module (GDLMM REQUIRED IMPORTED_TARGET gdlmm-3.0)

# 
# Executable name and options
# 

# Target name
set(target Axum)

# Exit here if required dependencies are not met
if (NOT BOOST_FOUND )
   message(STATUS "${target} skipped: Boost  not found")
    return()
else()
    message(STATUS "${target} : Boost found")
endif()

if (NOT GTKMM_FOUND )
   message(STATUS "${target} skipped: Gtkmm  not found")
    return()
else()
    message(STATUS "${target} : Gtkmm found")
endif()


# 
# Sources
# 

list(APPEND sources
    main.cpp
    MApplication.h
    MApplication.cpp
    Addon/Addon.h
    Addon/Addon.cpp
    #Bakery tools
    Bakery/Baker.h
    Bakery/Baker.cpp
    Bakery/BakerParams.h
    Bakery/BakerParams.cpp
    Bakery/Bakery.h
    Bakery/Bakery.cpp
    Bakery/BakeryParams.h
    Bakery/BakeryParams.cpp
    #3d View port rendering utilities
    Draw/RenderEngine.h
    Draw/RenderEngine.cpp
    Draw/Engines/GLEngine.h
    Draw/Engines/GLEngine.cpp
    #Editor
    Editors/Editor.h
    Editors/Editor.cpp
    Editors/ParameterEditor.h
    Editors/ParameterEditor.cpp
    Editors/MaterialGraphEditor.h
    Editors/MaterialGraphEditor.cpp
    Editors/Outliner.h
    Editors/Outliner.cpp
    Editors/2DView.h
    Editors/2DView.cpp
    Editors/3DView.h
    Editors/3DView.cpp
    Editors/AssetManager.h
    Editors/AssetManager.cpp
    Editors/LogicGraphEditor.h
    Editors/LogicGraphEditor.cpp
    Editors/Operators/Operator.h
    Editors/Operators/Operator.cpp
    #Managers
    Managers/AddonManager.h
    Managers/AddonManager.cpp
    Managers/BakeryManager.h
    Managers/BakeryManager.cpp
    Managers/EditorManager.h
    Managers/EditorManager.cpp
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
    #Node Graph
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
    NodeGraph/InputSockets/LogicInSocket.h
    NodeGraph/InputSockets/LogicInSocket.cpp
    NodeGraph/InputSockets/MaterialInSocket.h
    NodeGraph/InputSockets/MaterialInSocket.cpp
    NodeGraph/Nodes/AtomicNodes.h
    NodeGraph/Nodes/AtomicNodes.cpp
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
    NodeGraph/OutputSockets/LogicOutSocket.h
    NodeGraph/OutputSockets/LogicOutSocket.cpp
    NodeGraph/OutputSockets/MaterialOutSocket.h
    NodeGraph/OutputSockets/MaterialOutSocket.cpp
    #Parameters
    Parameter/BooleanParam.h
    Parameter/BooleanParam.cpp
    Parameter/EnumParam.h
    Parameter/EnumParam.cpp
    Parameter/Float2Param.h
    Parameter/Float2Param.cpp
    Parameter/Float3Param.h
    Parameter/Float3Param.cpp
    Parameter/Float4Param.h
    Parameter/Float4Param.cpp
    Parameter/FloatParam.h
    Parameter/FloatParam.cpp
    Parameter/Integer2Param.h
    Parameter/Integer2Param.cpp
    Parameter/Integer3Param.h
    Parameter/Integer3Param.cpp
    Parameter/Integer4Param.h
    Parameter/Integer4Param.cpp
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
    #Resource types
    Resources/ImageTexture.h
    Resources/ImageTexture.cpp
    Resources/Folder.h
    Resources/Folder.cpp
    Resources/Font.h
    Resources/Font.cpp
    Resources/Resource.h
    Resources/Resource.cpp
    Resources/Scene.h
    Resources/Scene.cpp
    Resources/VectorGraphics.h
    Resources/VectorGraphics.cpp
    Resources/Package.h
    Resources/Package.cpp
    #UI Elements
    UI/EditorUI.h
    UI/EditorUI.cpp
    UI/MainWindow.h
    UI/MainWindow.cpp
    UI/SplashWindow.h
    UI/SplashWindow.cpp
    UI/Window.h
    UI/Window.cpp
    #Editor UI classes
    UI/EditorUIs/2DViewUI.h
    UI/EditorUIs/2DViewUI.cpp
    UI/EditorUIs/3DViewUI.h
    UI/EditorUIs/3DViewUI.cpp
    UI/EditorUIs/OutlinerUI.h
    UI/EditorUIs/OutlinerUI.cpp
    UI/EditorUIs/LogicGraphEditorUI.h
    UI/EditorUIs/LogicGraphEditorUI.cpp
    UI/EditorUIs/AssetManagerUI.h
    UI/EditorUIs/AssetManagerUI.cpp
    UI/EditorUIs/MatGraphEditorUI.h
    UI/EditorUIs/MatGraphEditorUI.cpp
    UI/EditorUIs/ParameterEditorUI.h
    UI/EditorUIs/ParameterEditorUI.cpp
    #Widgets
    UI/Widgets/ExplorerItemUI.h
    UI/Widgets/ExplorerItemUI.cpp
    UI/Widgets/GraphUI.h
    UI/Widgets/GraphUI.cpp
    UI/Widgets/InputSocketUI.h
    UI/Widgets/InputSocketUI.cpp
    UI/Widgets/NodeLinkUI.h
    UI/Widgets/NodeLinkUI.cpp
    UI/Widgets/NodeUI.h
    UI/Widgets/NodeUI.cpp
    UI/Widgets/OutputSocketUI.h
    UI/Widgets/OutputSocketUI.cpp
    UI/Widgets/ParamUI.h
    UI/Widgets/ParamUI.cpp
    #Function Graph Related UI elements
    UI/Widgets/Function/FunGraphUI.h
    UI/Widgets/Function/FunGraphUI.cpp
    UI/Widgets/Function/FunInSocketUI.h
    UI/Widgets/Function/FunInSocketUI.cpp
    UI/Widgets/Function/FunNodeLinkUI.h
    UI/Widgets/Function/FunNodeLinkUI.cpp
    UI/Widgets/Function/FunNodeUI.h
    UI/Widgets/Function/FunNodeUI.cpp
    UI/Widgets/Function/FunOutSocketUI.h
    UI/Widgets/Function/FunOutSocketUI.cpp
    #Material Graph related UI elements
    UI/Widgets/Material/MatGraphUI.h
    UI/Widgets/Material/MatGraphUI.cpp
    UI/Widgets/Material/MatInSocketUI.h
    UI/Widgets/Material/MatInSocketUI.cpp
    UI/Widgets/Material/MatNodeLinkUI.h
    UI/Widgets/Material/MatNodeLinkUI.cpp
    UI/Widgets/Material/MatNodeUI.h
    UI/Widgets/Material/MatNodeUI.cpp
    UI/Widgets/Material/MatOutSocketUI.h
    UI/Widgets/Material/MatOutSocketUI.cpp
    #Utilities
    #Serialization Utilities
    Utils/Serialization/Connection.h
    Utils/Serialization/Connection.cpp
    Utils/Serialization/GUIInfo.h
    #Logging Utilities
    Utils/Log/Log.h
    Utils/Log/Log.cpp
    #Runtime path utilities
    Utils/pathUtils.h
    Utils/pathUtils.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/embedded-resources.h
)

if(OPTION_WITH_CYCLES)
    list(APPEND sources
        Draw/Engines/CyclesEngine.h
        Draw/Engines/CyclesEngine.cpp
    )
endif()

# 
# Create executable
# 

# Build executable
add_executable(${target}
    MACOSX_BUNDLE
    ${sources}
)

# Create namespaced alias
add_executable(${META_PROJECT_NAME}::${target} ALIAS ${target})


# 
# Project options
# 

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
    FOLDER "${IDE_FOLDER}"
)


# 
# Include directories
# 

target_include_directories(${target}
    PRIVATE
    ${DEFAULT_INCLUDE_DIRECTORIES}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${PROJECT_BINARY_DIR}/source/include
    Utils/Log
    Utils
)


# 
# Libraries
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LIBRARIES}
    ${META_PROJECT_NAME}::ABaker
    Boost::filesystem
    Boost::serialization
    PkgConfig::SPD_LOG
    PkgConfig::GTKMM
    PkgConfig::EPOXY
    PkgConfig::LIB_SIGNAL
    PkgConfig::OIIO
    PkgConfig::GDLMM
)


# 
# Compile definitions
# 

target_compile_definitions(${target}
    PRIVATE
    ${DEFAULT_COMPILE_DEFINITIONS}
)


# 
# Compile options
# 

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)


# 
# Linker options
# 

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
)


#
# Target Health
#

perform_health_checks(
    ${target}
    ${sources}
)


# 
# Deployment
# 

# Executable
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN} COMPONENT Axum
    BUNDLE  DESTINATION ${INSTALL_BIN} COMPONENT Axum
)
