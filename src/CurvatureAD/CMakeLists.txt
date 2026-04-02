set(CurvatureAD_SOURCE CurvatureAD.cxx)
GENERATECLP(CurvatureAD_SOURCE CurvatureAD.xml)

#Updated
add_executable(CurvatureAD_${MYHAWKID} ${CurvatureAD_SOURCE})
target_link_libraries(CurvatureAD_${MYHAWKID} ${ITK_LIBRARIES})