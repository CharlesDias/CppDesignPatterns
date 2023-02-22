
add_library(${LIB_NAME} STATIC)

target_sources(${LIB_NAME}
   PRIVATE
   src/concrete_creator1.cpp
   src/concrete_creator2.cpp
   src/concrete_product1.cpp
   src/concrete_product2.cpp
)

target_include_directories(${LIB_NAME}
   PUBLIC
   ../lib/include
)