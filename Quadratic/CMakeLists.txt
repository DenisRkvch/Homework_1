# CMakeList.txt: проект CMake для Quadratic; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

add_library(Quadratic STATIC "Quadratic.cpp" "Quadratic.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Quadratic PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
