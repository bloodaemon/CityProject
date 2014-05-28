CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(demo4)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

FIND_PACKAGE (OpenGL REQUIRED)
FIND_PACKAGE (GLUT REQUIRED)
FIND_PACKAGE (GLEW REQUIRED)


#Debug mode
#ADD_DEFINITIONS(-g )

#Release Mode
ADD_DEFINITIONS(-s -O3 )


#create the executable
SET(EXEC CityProject.x)
ADD_EXECUTABLE(${EXEC} main.cpp box.cpp cityapp.cpp plane.cpp car/car.cpp car/movingCar.cpp street/street.cpp building/cube.cpp building/pyramid.cpp building/cylinder.cpp building/buildingsEnum.h building/directionsEnum.h building/buildings.cpp building/windowTexture.cpp billboard/billboard.cpp sky/sky.cpp)

TARGET_LINK_LIBRARIES (${EXEC}
   ${OPENGL_gl_LIBRARY}
   ${OPENGL_glu_LIBRARY}
   ${GLUT_LIBRARY}
   ${GLEW_GLEW_LIBRARY}

)
