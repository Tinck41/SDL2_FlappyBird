cmake_minimum_required(VERSION 3.20)

project(FlappyBird
		VERSION 1.0.0
		LANGUAGES C CXX
)

file(GLOB_RECURSE PROJECT_SOURCE_FILES "src/*.h" "src/*.hpp" "src/*.cpp")

set(CMAKE_CXX_STANDARD 17)
set(SDL2_DIR ${PROJECT_SOURCE_DIR}/vendor/SDL2)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/vendor/spdlog/include)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})