# Устанавливаем переменную TARGET равной имени проекта,
# чтобы потом везде подставлять
set (TARGET ep1m-autopilot)

# Задаем имя проекта
project (${TARGET})

# Qt-шное барахло для запуска метаобъектного компилятора
# сборки ресурсов и генерации кода UI при работе с формами
set(CMAKE_AUTOMOC ON)

# Путь, куда надо сложить собранное
set (LIBRARY_OUTPUT_PATH "../../modules/ep1m")
# Указываем не добавлять к имени бинарника никаких префиксов
set (CMAKE_SHARED_MODULE_PREFIX "")

# Ищем зависимости Qt6
find_package(Qt6 COMPONENTS Xml REQUIRED)

find_package(CfgReader ${RRS_VERSION} REQUIRED)
find_package(physics ${RRS_VERSION} REQUIRED)
find_package(Journal ${RRS_VERSION} REQUIRED)
find_package(filesystem ${RRS_VERSION} REQUIRED)
find_package(device ${RRS_VERSION} REQUIRED)
find_package(vehicle ${RRS_VERSION} REQUIRED)

# Пути к заголовкам и сорцам
file (GLOB INCLUDES "./include/*.h")
file (GLOB SOURCES "./src/*.cpp")

# Компиляция библиотеки
add_library (${TARGET} SHARED ${SOURCES} ${INCLUDES} ${EQP_SOURCES})

# Указываем пути поиска заголовков
target_include_directories (${TARGET} PRIVATE ./include/)
target_include_directories (${TARGET} PRIVATE ../ep1m-equipment/include/)

# Компонуемся с библиотеками Qt6
target_link_libraries (${TARGET} Qt6::Xml)
target_link_libraries (${TARGET} CfgReader)
target_link_libraries (${TARGET} physics)
target_link_libraries (${TARGET} vehicle)
target_link_libraries (${TARGET} device)
target_link_libraries (${TARGET} filesystem)
