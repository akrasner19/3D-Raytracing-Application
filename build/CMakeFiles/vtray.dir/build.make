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

# Include any dependencies generated for this target.
include CMakeFiles\vtray.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\vtray.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\vtray.dir\flags.make

CMakeFiles\vtray.dir\vtray.cpp.obj: CMakeFiles\vtray.dir\flags.make
CMakeFiles\vtray.dir\vtray.cpp.obj: ..\vtray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/vtray.dir/vtray.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\vtray.dir\vtray.cpp.obj /FdCMakeFiles\vtray.dir\ /FS -c C:\Users\Alex\Documents\applied\project3-akrasner19\vtray.cpp
<<

CMakeFiles\vtray.dir\vtray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vtray.dir/vtray.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  > CMakeFiles\vtray.dir\vtray.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alex\Documents\applied\project3-akrasner19\vtray.cpp
<<

CMakeFiles\vtray.dir\vtray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vtray.dir/vtray.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\vtray.dir\vtray.cpp.s /c C:\Users\Alex\Documents\applied\project3-akrasner19\vtray.cpp
<<

CMakeFiles\vtray.dir\vtray.cpp.obj.requires:

.PHONY : CMakeFiles\vtray.dir\vtray.cpp.obj.requires

CMakeFiles\vtray.dir\vtray.cpp.obj.provides: CMakeFiles\vtray.dir\vtray.cpp.obj.requires
	$(MAKE) -f CMakeFiles\vtray.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\vtray.dir\vtray.cpp.obj.provides.build
.PHONY : CMakeFiles\vtray.dir\vtray.cpp.obj.provides

CMakeFiles\vtray.dir\vtray.cpp.obj.provides.build: CMakeFiles\vtray.dir\vtray.cpp.obj


CMakeFiles\vtray.dir\geometry.cpp.obj: CMakeFiles\vtray.dir\flags.make
CMakeFiles\vtray.dir\geometry.cpp.obj: ..\geometry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/vtray.dir/geometry.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\vtray.dir\geometry.cpp.obj /FdCMakeFiles\vtray.dir\ /FS -c C:\Users\Alex\Documents\applied\project3-akrasner19\geometry.cpp
<<

CMakeFiles\vtray.dir\geometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vtray.dir/geometry.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  > CMakeFiles\vtray.dir\geometry.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alex\Documents\applied\project3-akrasner19\geometry.cpp
<<

CMakeFiles\vtray.dir\geometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vtray.dir/geometry.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\vtray.dir\geometry.cpp.s /c C:\Users\Alex\Documents\applied\project3-akrasner19\geometry.cpp
<<

CMakeFiles\vtray.dir\geometry.cpp.obj.requires:

.PHONY : CMakeFiles\vtray.dir\geometry.cpp.obj.requires

CMakeFiles\vtray.dir\geometry.cpp.obj.provides: CMakeFiles\vtray.dir\geometry.cpp.obj.requires
	$(MAKE) -f CMakeFiles\vtray.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\vtray.dir\geometry.cpp.obj.provides.build
.PHONY : CMakeFiles\vtray.dir\geometry.cpp.obj.provides

CMakeFiles\vtray.dir\geometry.cpp.obj.provides.build: CMakeFiles\vtray.dir\geometry.cpp.obj


CMakeFiles\vtray.dir\raytracer.cpp.obj: CMakeFiles\vtray.dir\flags.make
CMakeFiles\vtray.dir\raytracer.cpp.obj: ..\raytracer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/vtray.dir/raytracer.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\vtray.dir\raytracer.cpp.obj /FdCMakeFiles\vtray.dir\ /FS -c C:\Users\Alex\Documents\applied\project3-akrasner19\raytracer.cpp
<<

CMakeFiles\vtray.dir\raytracer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vtray.dir/raytracer.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  > CMakeFiles\vtray.dir\raytracer.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alex\Documents\applied\project3-akrasner19\raytracer.cpp
<<

CMakeFiles\vtray.dir\raytracer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vtray.dir/raytracer.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\vtray.dir\raytracer.cpp.s /c C:\Users\Alex\Documents\applied\project3-akrasner19\raytracer.cpp
<<

CMakeFiles\vtray.dir\raytracer.cpp.obj.requires:

.PHONY : CMakeFiles\vtray.dir\raytracer.cpp.obj.requires

CMakeFiles\vtray.dir\raytracer.cpp.obj.provides: CMakeFiles\vtray.dir\raytracer.cpp.obj.requires
	$(MAKE) -f CMakeFiles\vtray.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\vtray.dir\raytracer.cpp.obj.provides.build
.PHONY : CMakeFiles\vtray.dir\raytracer.cpp.obj.provides

CMakeFiles\vtray.dir\raytracer.cpp.obj.provides.build: CMakeFiles\vtray.dir\raytracer.cpp.obj


CMakeFiles\vtray.dir\vtray_automoc.cpp.obj: CMakeFiles\vtray.dir\flags.make
CMakeFiles\vtray.dir\vtray_automoc.cpp.obj: vtray_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/vtray.dir/vtray_automoc.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\vtray.dir\vtray_automoc.cpp.obj /FdCMakeFiles\vtray.dir\ /FS -c C:\Users\Alex\Documents\applied\project3-akrasner19\build\vtray_automoc.cpp
<<

CMakeFiles\vtray.dir\vtray_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/vtray.dir/vtray_automoc.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  > CMakeFiles\vtray.dir\vtray_automoc.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Alex\Documents\applied\project3-akrasner19\build\vtray_automoc.cpp
<<

CMakeFiles\vtray.dir\vtray_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/vtray.dir/vtray_automoc.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe  @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\vtray.dir\vtray_automoc.cpp.s /c C:\Users\Alex\Documents\applied\project3-akrasner19\build\vtray_automoc.cpp
<<

CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.requires:

.PHONY : CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.requires

CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.provides: CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.requires
	$(MAKE) -f CMakeFiles\vtray.dir\build.make /nologo -$(MAKEFLAGS) CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.provides.build
.PHONY : CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.provides

CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.provides.build: CMakeFiles\vtray.dir\vtray_automoc.cpp.obj


# Object files for target vtray
vtray_OBJECTS = \
"CMakeFiles\vtray.dir\vtray.cpp.obj" \
"CMakeFiles\vtray.dir\geometry.cpp.obj" \
"CMakeFiles\vtray.dir\raytracer.cpp.obj" \
"CMakeFiles\vtray.dir\vtray_automoc.cpp.obj"

# External object files for target vtray
vtray_EXTERNAL_OBJECTS =

vtray.exe: CMakeFiles\vtray.dir\vtray.cpp.obj
vtray.exe: CMakeFiles\vtray.dir\geometry.cpp.obj
vtray.exe: CMakeFiles\vtray.dir\raytracer.cpp.obj
vtray.exe: CMakeFiles\vtray.dir\vtray_automoc.cpp.obj
vtray.exe: CMakeFiles\vtray.dir\build.make
vtray.exe: C:\Qt\Qt5.8.0\5.8\msvc2015\lib\Qt5Guid.lib
vtray.exe: C:\Qt\Qt5.8.0\5.8\msvc2015\lib\Qt5Cored.lib
vtray.exe: CMakeFiles\vtray.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable vtray.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\vtray.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\vtray.dir\objects1.rsp @<<
 /out:vtray.exe /implib:vtray.lib /pdb:C:\Users\Alex\Documents\applied\project3-akrasner19\build\vtray.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console C:\Qt\Qt5.8.0\5.8\msvc2015\lib\Qt5Guid.lib C:\Qt\Qt5.8.0\5.8\msvc2015\lib\Qt5Cored.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\vtray.dir\build: vtray.exe

.PHONY : CMakeFiles\vtray.dir\build

CMakeFiles\vtray.dir\requires: CMakeFiles\vtray.dir\vtray.cpp.obj.requires
CMakeFiles\vtray.dir\requires: CMakeFiles\vtray.dir\geometry.cpp.obj.requires
CMakeFiles\vtray.dir\requires: CMakeFiles\vtray.dir\raytracer.cpp.obj.requires
CMakeFiles\vtray.dir\requires: CMakeFiles\vtray.dir\vtray_automoc.cpp.obj.requires

.PHONY : CMakeFiles\vtray.dir\requires

CMakeFiles\vtray.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\vtray.dir\cmake_clean.cmake
.PHONY : CMakeFiles\vtray.dir\clean

CMakeFiles\vtray.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Alex\Documents\applied\project3-akrasner19 C:\Users\Alex\Documents\applied\project3-akrasner19 C:\Users\Alex\Documents\applied\project3-akrasner19\build C:\Users\Alex\Documents\applied\project3-akrasner19\build C:\Users\Alex\Documents\applied\project3-akrasner19\build\CMakeFiles\vtray.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\vtray.dir\depend

