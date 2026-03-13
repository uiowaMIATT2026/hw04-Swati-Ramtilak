set(GradientAD_SOURCE GradientAD.cxx)
GENERATECLP(GradientAD_SOURCE GradientAD.xml)

add_executable(GradientAD_sramtilak ${GradientAD_SOURCE})
target_link_libraries(GradientAD_sramtilak ${ITK_LIBRARIES})