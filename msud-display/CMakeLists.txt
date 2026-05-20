set (TARGET msud-display)

project (${TARGET})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set (LIBRARY_OUTPUT_PATH "../../modules/ep1m")

set (CMAKE_SHARED_MODULE_PREFIX "")

add_definitions(-DMSUD_DISPLAY_LIBRARY)

find_package(Qt6 COMPONENTS Xml REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS OpenGL REQUIRED)

find_package(CfgReader ${RRS_VERSION} REQUIRED)
find_package(physics ${RRS_VERSION} REQUIRED)
find_package(Journal ${RRS_VERSION} REQUIRED)
find_package(filesystem ${RRS_VERSION} REQUIRED)
find_package(device ${RRS_VERSION} REQUIRED)
find_package(vehicle ${RRS_VERSION} REQUIRED)
find_package(display ${RRS_VERSION} REQUIRED)
find_package(core ${RRS_VERSION} REQUIRED)

file (GLOB INCLUDES "./include/*.h")
#file (GLOB EQP_INCLUDES "../ep1m-equipment/include/*.h")
file (GLOB SOURCES "./src/*.cpp")
#file (GLOB EQP_SOURCES "../ep1m-equipment/src/*.cpp")
file (GLOB RESOURCES "./resources/*.qrc")

#add_library (${TARGET} MODULE ${SOURCES} ${INCLUDES} ${EQP_SOURCES} ${EQP_INCLUDES} ${RESOURCES})
add_library (${TARGET} SHARED ${SOURCES} ${INCLUDES} ${RESOURCES})

target_include_directories (${TARGET} PRIVATE ./include/)
target_include_directories (${TARGET} PRIVATE ../ep1m/include)
target_include_directories (${TARGET} PRIVATE ../ep1m-equipment/include)

target_link_libraries (${TARGET} Qt6::Xml)
target_link_libraries (${TARGET} Qt6::Gui)
target_link_libraries (${TARGET} Qt6::Widgets)
target_link_libraries (${TARGET} Qt6::OpenGL)
target_link_libraries (${TARGET} device)
target_link_libraries (${TARGET} display)
target_link_libraries (${TARGET} core)
