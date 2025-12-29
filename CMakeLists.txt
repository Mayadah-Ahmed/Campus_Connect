cmake_minimum_required(VERSION 3.10)

# اسم المشروع
project(Campus_Connect)

# تحديد إصدار C++ (مهم جداً لدعم الـ Smart Pointers)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. تعريف مسارات المجلدات (للبحث عن الـ Headers)
include_directories(
    .
    controller
    models
    repository
    service
    View
)

# 2. تجميع كل ملفات الـ CPP في قائمة واحدة (تأكدي من مطابقة أسماء الملفات)
set(SOURCES
    main.cpp
    
    # Models
    models/User.cpp
    models/Post.cpp
    
    # Repository
    repository/InMemoryUserRepository.cpp
    repository/InMemoryPostRepository.cpp
    
    # Service
    service/AuthService.cpp
    service/PostService.cpp
    
    # View
    View/UserView.cpp
    View/PostView.cpp
    
    # Controller
    controller/UserController.cpp
    controller/PostController.cpp
)

# 3. إنشاء الملف التنفيذي
add_executable(Campus_Connect ${SOURCES})

# 4. ربط المكتبات (اختياري لبعض الأنظمة)
if(MSVC)
    target_compile_options(Campus_Connect PRIVATE /W4)
endif()