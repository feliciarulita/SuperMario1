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
CMAKE_SOURCE_DIR = /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild

# Utility rule file for sdl2_ttf-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/sdl2_ttf-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sdl2_ttf-populate.dir/progress.make

CMakeFiles/sdl2_ttf-populate: CMakeFiles/sdl2_ttf-populate-complete

CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-install
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-mkdir
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-configure
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-build
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-install
CMakeFiles/sdl2_ttf-populate-complete: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'sdl2_ttf-populate'"
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E make_directory /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles/sdl2_ttf-populate-complete
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-done

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-build: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'sdl2_ttf-populate'"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E echo_append
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-build

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-configure: sdl2_ttf-populate-prefix/tmp/sdl2_ttf-populate-cfgcmd.txt
sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-configure: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'sdl2_ttf-populate'"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E echo_append
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-configure

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/download-sdl2_ttf-populate.cmake
sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-urlinfo.txt
sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'sdl2_ttf-populate'"
	cd /Users/bryant/super_mario_bros_20240328/PTSD/lib && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -P /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/download-sdl2_ttf-populate.cmake
	cd /Users/bryant/super_mario_bros_20240328/PTSD/lib && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -P /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/verify-sdl2_ttf-populate.cmake
	cd /Users/bryant/super_mario_bros_20240328/PTSD/lib && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -P /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/extract-sdl2_ttf-populate.cmake
	cd /Users/bryant/super_mario_bros_20240328/PTSD/lib && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-install: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'sdl2_ttf-populate'"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E echo_append
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-install

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'sdl2_ttf-populate'"
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -Dcfgdir= -P /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/tmp/sdl2_ttf-populate-mkdirs.cmake
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-mkdir

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch-info.txt
sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'sdl2_ttf-populate'"
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-test: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'sdl2_ttf-populate'"
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E echo_append
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-build && /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-test

sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update-info.txt
sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No update step for 'sdl2_ttf-populate'"
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E echo_append
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update

sdl2_ttf-populate: CMakeFiles/sdl2_ttf-populate
sdl2_ttf-populate: CMakeFiles/sdl2_ttf-populate-complete
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-build
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-configure
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-download
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-install
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-mkdir
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-patch
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-test
sdl2_ttf-populate: sdl2_ttf-populate-prefix/src/sdl2_ttf-populate-stamp/sdl2_ttf-populate-update
sdl2_ttf-populate: CMakeFiles/sdl2_ttf-populate.dir/build.make
.PHONY : sdl2_ttf-populate

# Rule to build all files generated by this target.
CMakeFiles/sdl2_ttf-populate.dir/build: sdl2_ttf-populate
.PHONY : CMakeFiles/sdl2_ttf-populate.dir/build

CMakeFiles/sdl2_ttf-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sdl2_ttf-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sdl2_ttf-populate.dir/clean

CMakeFiles/sdl2_ttf-populate.dir/depend:
	cd /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild /Users/bryant/super_mario_bros_20240328/build/_deps/sdl2_ttf-subbuild/CMakeFiles/sdl2_ttf-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/sdl2_ttf-populate.dir/depend

