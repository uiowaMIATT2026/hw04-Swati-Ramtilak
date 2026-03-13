set(DOG_SOURCE DOG.cxx)
GENERATECLP(DOG_SOURCE DOG.xml)

add_executable(DOG_sramtilak ${DOG_SOURCE})
target_link_libraries(DOG_sramtilak ${ITK_LIBRARIES})