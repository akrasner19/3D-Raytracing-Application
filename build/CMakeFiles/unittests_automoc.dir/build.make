# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Alex\Documents\applied\project3-akrasner19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Alex\Documents\applied\project3-akrasner19\build

# Utility rule file for unittests_automoc.

# Include the progress variables for this target.
include CMakeFiles\unittests_automoc.dir\progress.make

CMakeFiles\unittests_automoc:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic moc for target unittests"
	echo >nul && "C:\Program Files\CMake\bin\cmake.exe" -E cmake_autogen C:/Users/Alex/Documents/applied/project3-akrasner19/build/CMakeFiles/unittests_automoc.dir/ Debug

unittests_automoc: CMakeFiles\unittests_automoc
unittests_automoc: CMakeFiles\unittests_automoc.dir\build.make

.PHONY : unittests_automoc

# Rule to build all files generated by this target.
CMakeFiles\unittests_automoc.dir\build: unittests_automoc

.PHONY : CMakeFiles\unittests_automoc.dir\build

CMakeFiles\unittests_automoc.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\unittests_automoc.dir\cmake_clean.cmake
.PHONY : CMakeFiles\unittests_automoc.dir\clean

CMakeFiles\unittests_automoc.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Alex\Documents\applied\project3-akrasner19 C:\Users\Alex\Documents\applied\project3-akrasner19 C:\Users\Alex\Documents\applied\project3-akrasner19\build C:\Users\Alex\Documents\applied\project3-akrasner19\build C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles\unittests_automoc.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\unittests_automoc.dir\depend

