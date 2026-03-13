set(SimpleThreshold_SOURCE SimpleThreshold.cxx)
GENERATECLP(SimpleThreshold_SOURCE SimpleThreshold.xml)

add_executable(SimpleThreshold_sramtilak ${SimpleThreshold_SOURCE})
target_link_libraries(SimpleThreshold_sramtilak ${ITK_LIBRARIES})