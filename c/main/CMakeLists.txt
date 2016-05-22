CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(SORT_MAIN)

# set ROOT_PATH as your install path
SET(ROOT_PATH ~/study/algorithms/root/c)

INCLUDE_DIRECTORIES(${ROOT_PATH}/usr/include)
LINK_DIRECTORIES(${ROOT_PATH}/usr/lib)

ADD_EXECUTABLE(sort_main main.c)
TARGET_LINK_LIBRARIES(sort_main sort)
