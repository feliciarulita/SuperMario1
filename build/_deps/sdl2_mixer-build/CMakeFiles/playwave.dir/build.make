# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/bryant/super_mario_bros_20240328

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bryant/super_mario_bros_20240328/build

# Include any dependencies generated for this target.
include _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/flags.make

_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.o: _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/flags.make
_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.o: /Users/bryant/super_mario_bros_20240328/PTSD/lib/sdl2_mixer/playwave.c
_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.o: _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.o"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.o -MF CMakeFiles/playwave.dir/playwave.c.o.d -o CMakeFiles/playwave.dir/playwave.c.o -c /Users/bryant/super_mario_bros_20240328/PTSD/lib/sdl2_mixer/playwave.c

_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/playwave.dir/playwave.c.i"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/bryant/super_mario_bros_20240328/PTSD/lib/sdl2_mixer/playwave.c > CMakeFiles/playwave.dir/playwave.c.i

_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/playwave.dir/playwave.c.s"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/bryant/super_mario_bros_20240328/PTSD/lib/sdl2_mixer/playwave.c -o CMakeFiles/playwave.dir/playwave.c.s

# Object files for target playwave
playwave_OBJECTS = \
"CMakeFiles/playwave.dir/playwave.c.o"

# External object files for target playwave
playwave_EXTERNAL_OBJECTS =

_deps/sdl2_mixer-build/playwave: _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/playwave.c.o
_deps/sdl2_mixer-build/playwave: _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/build.make
_deps/sdl2_mixer-build/playwave: _deps/sdl2_mixer-build/libSDL2_mixerd.a
_deps/sdl2_mixer-build/playwave: _deps/sdl2-build/libSDL2maind.a
_deps/sdl2_mixer-build/playwave: _deps/sdl2-build/libSDL2d.a
_deps/sdl2_mixer-build/playwave: _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable playwave"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/playwave.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/build: _deps/sdl2_mixer-build/playwave
.PHONY : _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/build

_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/clean:
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build && $(CMAKE_COMMAND) -P CMakeFiles/playwave.dir/cmake_clean.cmake
.PHONY : _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/clean

_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/depend:
	cd /Users/bryant/super_mario_bros_20240328/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bryant/super_mario_bros_20240328 /Users/bryant/super_mario_bros_20240328/PTSD/lib/sdl2_mixer /Users/bryant/super_mario_bros_20240328/build /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_mixer-build/CMakeFiles/playwave.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/sdl2_mixer-build/CMakeFiles/playwave.dir/depend

