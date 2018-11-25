cmake_minimum_required(VERSION 3.5)

project(Liman C CXX)

set(CMAKE_CXX_STANDARD 11)

# OPENGL
message(STATUS "Loading OPENGL library")
find_package(OpenGL REQUIRED)
if (OPENGL_FOUND)
	message("Found OpenGL for Mac OS")
	message("OpenGL for Mac OS, include dir: ${OPENGL_INCLUDE_DIR}")
	message("OpenGL for Mac OS, link libraries: ${OPENGL_gl_LIBRARY}")
else (OPENGL_FOUND)
	message(FATAL_ERROR "OpenGL for Mac OS not found")
endif ()

# GLEW
message(STATUS "Loading GLEW library")
add_subdirectory(third_party/glew-cmake)
set(LIB_GLEW_INC_DIR third_party/glew-cmake/include)
set(LIB_GLEW_NAME libglew_static)

# GLFW
message(STATUS "Loading GLFW library")
add_subdirectory(third_party/glfw)
set(LIB_GLFW_INC_DIR third_party/glfw/include)
set(LIB_GLFW_NAME glfw)

## GLM
message(STATUS "Loading GLM library")
add_subdirectory(third_party/glm)
set(LIB_GLM_INC_DIR third_party/glm)
set(LIB_GLM_NAME glm)

# STB
message(STATUS "Loading STB library")
set(LIB_STB_INC_DIR third_party/stb)

# TINYXML2
message(STATUS "Loading TINYXML2 library")
add_subdirectory(third_party/tinyxml2)
set(LIB_TINYXML2_INC_DIR third_party/tinyxml2)
set(LIB_TINYXML2_NAME tinyxml2)

# Liman Core
set(LIMAN_CORE_DIR ${PROJECT_SOURCE_DIR}/Core)
file(GLOB_RECURSE LIMAN_CORE_SRCS
	"${LIMAN_CORE_DIR}/*.cpp"
	)
file(GLOB_RECURSE LIMAN_CORE_HDRS
	"${LIMAN_CORE_DIR}/*.h"
	)
add_library(Liman-Core STATIC
	${LIMAN_CORE_SRCS}
	${LIMAN_CORE_HDRS}
	)
target_include_directories(Liman-Core
	PUBLIC ${LIB_GLEW_INC_DIR}
	PUBLIC ${LIB_GLFW_INC_DIR}
	PUBLIC ${LIB_GLM_INC_DIR}
	PUBLIC ${LIB_STB_INC_DIR}
	PUBLIC ${LIB_TINYXML2_INC_DIR}
	)
target_link_libraries(Liman-Core
	${OPENGL_gl_LIBRARY}
	${OPENGL_glu_LIBRARY}
	${LIB_GLEW_NAME}
	${LIB_GLFW_NAME}
	${LIB_GLM_NAME}
	${LIB_TINYXML2_NAME}
	)

# Liman Game
set(LIMAN_GAME_DIR ${PROJECT_SOURCE_DIR}/Game)
file(GLOB_RECURSE LIMAN_GAME_SRCS
	"${LIMAN_GAME_DIR}/*.cpp"
	)
file(GLOB_RECURSE LIMAN_GAME_HDRS
	"${LIMAN_GAME_DIR}/*.h"
	)
add_library(Liman-Game STATIC
	${LIMAN_GAME_SRCS}
	${LIMAN_GAME_HDRS}
	)
target_link_libraries(Liman-Game
	Liman-Core
	)
target_include_directories(Liman-Game
	PUBLIC ${LIMAN_CORE_DIR}
	)

# Liman Demo
set(LIMAN_DEMO_DIR ${PROJECT_SOURCE_DIR}/Demo)
file(GLOB_RECURSE LIMAN_DEMO_SRCS
	"${LIMAN_DEMO_DIR}/*.cpp"
	)
file(GLOB_RECURSE LIMAN_DEMO_HDRS
	"${LIMAN_DEMO_DIR}/*.h"
	)
add_executable(Liman-Demo
	${LIMAN_DEMO_SRCS}
	${LIMAN_DEMO_HDRS}
	)
target_include_directories(Liman-Demo PUBLIC
	${LIMAN_CORE_DIR}
	${LIMAN_GAME_DIR}
	)
target_link_libraries(Liman-Demo
	Liman-Core
	Liman-Game
	)