#
# Resource embedding
#

# Include the extension module.
list(APPEND CMAKE_MODULE_PATH
    "${PROJECT_SOURCE_DIR}/cmake/GCR")

include(GlibCompileResourcesSupport)

# Set the resources to bundle.
set(RESOURCE_LIST
    TOPIXDATA COMPRESS "splash.png")

# Compile the resources.
message("Compiling resources")

set(CMAKE_CURRENT_BINARY_DIR ${PROJECT_BINARY_DIR})

compile_gresources(RESOURCE_FILE
                   XML_OUT
                   TYPE BUNDLE
                   TARGET "${PROJECT_BINARY_DIR}/data/resources.bin"
                   RESOURCES ${RESOURCE_LIST}
                   COMPRESS_ALL)

add_custom_target(Resources ALL DEPENDS ${RESOURCE_FILE})

install(FILES "${PROJECT_BINARY_DIR}/data/resources.bin" DESTINATION "${INSTALL_DATA}/data" COMPONENT RUNTIME)

message("Compiled resources")