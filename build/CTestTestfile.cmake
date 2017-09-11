# CMake generated Testfile for 
# Source directory: C:/Users/Alex/Documents/applied/project3-akrasner19
# Build directory: C:/Users/Alex/Documents/applied/project3-akrasner19/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(unit "unittests")
add_test(test0 "vtray" "C:/Users/Alex/Documents/applied/project3-akrasner19/tests/scene0.json" "output0.png")
add_test(test1 "vtray" "C:/Users/Alex/Documents/applied/project3-akrasner19/tests/scene1.json" "output1.png")
add_test(test2 "vtray" "C:/Users/Alex/Documents/applied/project3-akrasner19/tests/scene2.json" "output2.png")
add_test(test3 "vtray" "C:/Users/Alex/Documents/applied/project3-akrasner19/tests/scene3.json" "output3.png")
set_tests_properties(test3 PROPERTIES  WILL_FAIL "ON")
add_test(test4 "vtray" "C:/Users/Alex/Documents/applied/project3-akrasner19/tests/scene4.json" "output4.png")
set_tests_properties(test4 PROPERTIES  WILL_FAIL "ON")
