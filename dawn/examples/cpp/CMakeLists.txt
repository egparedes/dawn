##===------------------------------------------------------------------------------*- CMake -*-===##
##                          _                      
##                         | |                     
##                       __| | __ ___      ___ ___  
##                      / _` |/ _` \ \ /\ / / '_  | 
##                     | (_| | (_| |\ V  V /| | | |
##                      \__,_|\__,_| \_/\_/ |_| |_| - Compiler Toolchain
##
##
##  This file is distributed under the MIT License (MIT). 
##  See LICENSE.txt for details.
##
##===------------------------------------------------------------------------------------------===##
add_executable(sir-to-iir SIRToIIR.cpp)
target_link_libraries(sir-to-iir DawnCStatic)
target_include_directories(sir-to-iir PUBLIC ${DAWN_INSTALL_INCLUDE_DIR} ${DAWN_INSTALL_INCLUDE_DIR}/dawn/Support/External)
