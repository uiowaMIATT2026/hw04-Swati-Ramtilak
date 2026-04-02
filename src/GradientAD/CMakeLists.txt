set(GradientAD_SOURCE GradientAD.cxx)
GENERATECLP(GradientAD_SOURCE GradientAD.xml)

#Updated
add_executable(GradientAD_${MYHAWKID} ${GradientAD_SOURCE})
target_link_libraries(GradientAD_${MYHAWKID} ${ITK_LIBRARIES})