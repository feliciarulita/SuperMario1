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
include CMakeFiles/SuperMario1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SuperMario1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SuperMario1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SuperMario1.dir/flags.make

CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o: /Users/bryant/super_mario_bros_20240328/src/AnimatedCharacter.cpp
CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o -MF CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/AnimatedCharacter.cpp

CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/AnimatedCharacter.cpp > CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.i

CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/AnimatedCharacter.cpp -o CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.s

CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o: /Users/bryant/super_mario_bros_20240328/src/AppEnd.cpp
CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o -MF CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/AppEnd.cpp

CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/AppEnd.cpp > CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.i

CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/AppEnd.cpp -o CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.s

CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o: /Users/bryant/super_mario_bros_20240328/src/AppStart.cpp
CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o -MF CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/AppStart.cpp

CMakeFiles/SuperMario1.dir/src/AppStart.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/AppStart.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/AppStart.cpp > CMakeFiles/SuperMario1.dir/src/AppStart.cpp.i

CMakeFiles/SuperMario1.dir/src/AppStart.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/AppStart.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/AppStart.cpp -o CMakeFiles/SuperMario1.dir/src/AppStart.cpp.s

CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o: /Users/bryant/super_mario_bros_20240328/src/AppUpdate.cpp
CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o -MF CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/AppUpdate.cpp

CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/AppUpdate.cpp > CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.i

CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/AppUpdate.cpp -o CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.s

CMakeFiles/SuperMario1.dir/src/Character.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/Character.cpp.o: /Users/bryant/super_mario_bros_20240328/src/Character.cpp
CMakeFiles/SuperMario1.dir/src/Character.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SuperMario1.dir/src/Character.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/Character.cpp.o -MF CMakeFiles/SuperMario1.dir/src/Character.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/Character.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/Character.cpp

CMakeFiles/SuperMario1.dir/src/Character.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/Character.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/Character.cpp > CMakeFiles/SuperMario1.dir/src/Character.cpp.i

CMakeFiles/SuperMario1.dir/src/Character.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/Character.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/Character.cpp -o CMakeFiles/SuperMario1.dir/src/Character.cpp.s

CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o: /Users/bryant/super_mario_bros_20240328/src/PhaseManager.cpp
CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o -MF CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/PhaseManager.cpp

CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/PhaseManager.cpp > CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.i

CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/PhaseManager.cpp -o CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.s

CMakeFiles/SuperMario1.dir/src/main.cpp.o: CMakeFiles/SuperMario1.dir/flags.make
CMakeFiles/SuperMario1.dir/src/main.cpp.o: /Users/bryant/super_mario_bros_20240328/src/main.cpp
CMakeFiles/SuperMario1.dir/src/main.cpp.o: CMakeFiles/SuperMario1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SuperMario1.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SuperMario1.dir/src/main.cpp.o -MF CMakeFiles/SuperMario1.dir/src/main.cpp.o.d -o CMakeFiles/SuperMario1.dir/src/main.cpp.o -c /Users/bryant/super_mario_bros_20240328/src/main.cpp

CMakeFiles/SuperMario1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SuperMario1.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/bryant/super_mario_bros_20240328/src/main.cpp > CMakeFiles/SuperMario1.dir/src/main.cpp.i

CMakeFiles/SuperMario1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SuperMario1.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/bryant/super_mario_bros_20240328/src/main.cpp -o CMakeFiles/SuperMario1.dir/src/main.cpp.s

# Object files for target SuperMario1
SuperMario1_OBJECTS = \
"CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o" \
"CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o" \
"CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o" \
"CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o" \
"CMakeFiles/SuperMario1.dir/src/Character.cpp.o" \
"CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o" \
"CMakeFiles/SuperMario1.dir/src/main.cpp.o"

# External object files for target SuperMario1
SuperMario1_EXTERNAL_OBJECTS =

SuperMario1: CMakeFiles/SuperMario1.dir/src/AnimatedCharacter.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/src/AppEnd.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/src/AppStart.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/src/AppUpdate.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/src/Character.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/src/PhaseManager.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/src/main.cpp.o
SuperMario1: CMakeFiles/SuperMario1.dir/build.make
SuperMario1: _deps/sdl2-build/libSDL2maind.a
SuperMario1: libFramework.a
SuperMario1: lib/libGLEWd.a
SuperMario1: _deps/sdl2_image-build/libSDL2_imaged.a
SuperMario1: _deps/sdl2_ttf-build/libSDL2_ttfd.a
SuperMario1: _deps/sdl2_ttf-build/external/freetype/libfreetyped.a
SuperMario1: _deps/sdl2_mixer-build/libSDL2_mixerd.a
SuperMario1: _deps/sdl2-build/libSDL2d.a
SuperMario1: _deps/spdlog-build/libspdlogd.a
SuperMario1: CMakeFiles/SuperMario1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable SuperMario1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SuperMario1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SuperMario1.dir/build: SuperMario1
.PHONY : CMakeFiles/SuperMario1.dir/build

CMakeFiles/SuperMario1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SuperMario1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SuperMario1.dir/clean

CMakeFiles/SuperMario1.dir/depend:
	cd /Users/bryant/super_mario_bros_20240328/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bryant/super_mario_bros_20240328 /Users/bryant/super_mario_bros_20240328 /Users/bryant/super_mario_bros_20240328/build /Users/bryant/super_mario_bros_20240328/build /Users/bryant/super_mario_bros_20240328/build/CMakeFiles/SuperMario1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SuperMario1.dir/depend

