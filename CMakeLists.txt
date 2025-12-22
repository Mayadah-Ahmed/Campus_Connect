cmake_minimum_required(VERSION 3.10)

project(CampusConnect)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CampusConnect
    main.cpp

    models/User.cpp
    models/Post.cpp

    repository/InMemoryUserRepository.cpp

    service/AuthService.cpp
    service/PostService.cpp

    controller/AuthController.cpp
 "tests/AuthServiceTest.cpp" "tests/postServiceTest.cpp")

target_include_directories(CampusConnect PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)
