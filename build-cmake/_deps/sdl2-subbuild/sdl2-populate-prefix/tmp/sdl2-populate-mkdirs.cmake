# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

# If CMAKE_DISABLE_SOURCE_CHANGES is set to true and the source directory is an
# existing directory in our source tree, calling file(MAKE_DIRECTORY) on it
# would cause a fatal error, even though it would be a no-op.
if(NOT EXISTS "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-src")
  file(MAKE_DIRECTORY "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-src")
endif()
file(MAKE_DIRECTORY
  "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-build"
  "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix"
  "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix/tmp"
  "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp"
  "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix/src"
  "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "C:/Users/Rainchus/Desktop/ChameleonTwistJPRecompiled - Copy/build-cmake/_deps/sdl2-subbuild/sdl2-populate-prefix/src/sdl2-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
