set(CurvatureAD_SOURCE CurvatureAD.cxx)
GENERATECLP(CurvatureAD_SOURCE CurvatureAD.xml)

add_executable(CurvatureAD_sramtilak ${CurvatureAD_SOURCE})
target_link_libraries(CurvatureAD_sramtilak ${ITK_LIBRARIES})