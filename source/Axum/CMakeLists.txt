
# 
# External dependencies
# 

find_package(PkgConfig REQUIRED QUIET)
find_package(Boost 1.72.0 REQUIRED COMPONENTS filesystem serialization)
find_package(GTKMM)
pkg_search_module (SPD_LOG REQUIRED IMPORTED_TARGET spdlog)
pkg_search_module (EPOXY REQUIRED IMPORTED_TARGET libepoxy epoxy)

# 
# Executable name and options
# 

# Target name
set(target Axum)

# Exit here if required dependencies are not met

#if (NOT BOOST_FOUND || NOT PkgConfig_FOUND || NOT )
#   message(STATUS "Example ${target} skipped: Qt5 not found")
#    return()
#else()
#    message(STATUS "Example ${target}")
#endif()


# 
# Sources
# 

list(APPEND sources
    main.cpp
    MApplication.h
    MApplication.cpp
    Addon/Addon.h
    Addon/Addon.cpp
    Bakery/Baker.h
    Bakery/Baker.cpp
    Bakery/BakerParams.h
    Bakery/BakerParams.cpp
    Bakery/Bakery.h
    Bakery/Bakery.cpp
    Bakery/BakeryParams.h
    Bakery/BakeryParams.cpp
    Draw/RenderEngine.h
    Draw/RenderEngine.cpp
    Draw/RenderEngineParams.h
    Draw/RenderEngineParams.cpp
    Draw/CameraParams.h
    Draw/CameraParams.cpp
    Draw/Engines/GLEngine.h
    Draw/Engines/GLEngine.cpp
    #Editor
    Editor/Editor.h
    Editor/Editor.cpp
    Editor/Editors/ParameterEditor.h
    Editor/Editors/ParameterEditor.cpp
    Editor/Editors/GraphEditor.h
    Editor/Editors/GraphEditor.cpp
    Editor/Editors/MaterialGraphEditor.h
    Editor/Editors/MaterialGraphEditor.cpp
    Editor/Editors/Explorer.h
    Editor/Editors/Explorer.cpp
    Editor/Editors/2DView.h
    Editor/Editors/2DView.cpp
    Editor/Editors/3DView.h
    Editor/Editors/3DView.cpp
    Editor/Editors/Library.h
    Editor/Editors/Library.cpp
    Editor/Editors/FunGraphEditor.h
    Editor/Editors/FunGraphEditor.cpp
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
    Operators/Operator.h
    Operators/Operator.cpp
    Package/Package.h
    Package/Package.cpp
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
    Parameter/TextParam.h
    Parameter/TextParam.cpp
    Resources/Bitmap.h
    Resources/Bitmap.cpp
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
    #UI Elements
    UI/DockablePanel.h
    UI/DockablePanel.cpp
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
    UI/EditorUIs/ExplorerUI.h
    UI/EditorUIs/ExplorerUI.cpp
    UI/EditorUIs/FunGraphEditorUI.h
    UI/EditorUIs/FunGraphEditorUI.cpp
    UI/EditorUIs/GraphEditorUI.h
    UI/EditorUIs/GraphEditorUI.cpp
    UI/EditorUIs/LibraryUI.h
    UI/EditorUIs/LibraryUI.cpp
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
    GTKMM
    PkgConfig::EPOXY
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
