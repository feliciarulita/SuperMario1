# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/PTSD/lib/spdlog"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-build"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src"
  "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/feliciarulita/Documents/sem4/oop_game/SuperMario1/cmake-build-debug/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
