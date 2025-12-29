cmake_minimum_required(VERSION 3.10)

project(Campus_Connect)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    controller
    models
    repository
    service
    View
)
set(SOURCES
    main.cpp
   
    models/User.cpp
    models/Post.cpp
  
    repository/InMemoryUserRepository.cpp
    repository/InMemoryPostRepository.cpp
   
    service/AuthService.cpp
    service/PostService.cpp
   
    View/UserView.cpp
    View/PostView.cpp
   
    controller/UserController.cpp
    controller/PostController.cpp
)

add_executable(Campus_Connect ${SOURCES})