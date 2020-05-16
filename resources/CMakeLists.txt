# Include the extension module.
list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/../cmake/GCR")

include(GlibCompileResourcesSupport)

# Set the resources to bundle.
set(RESOURCE_LIST
    TOPIXDATA splash.png)

# Compile the resources.
compile_gresources(RESOURCE_FILE
                   XML_OUT
                   TYPE EMBED_H
                   TARGET "resources.h"
                   RESOURCES ${RESOURCE_LIST})
add_custom_target(resource ALL DEPENDS ${RESOURCE_FILE})

message(STATUS "${XML_OUT}")
