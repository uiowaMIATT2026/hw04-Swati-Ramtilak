set(GaussianLPF_SOURCE GaussianLPF.cxx)
GENERATECLP(GaussianLPF_SOURCE GaussianLPF.xml)

add_executable(GaussianLPF_sramtilak ${GaussianLPF_SOURCE})
target_link_libraries(GaussianLPF_sramtilak ${ITK_LIBRARIES})