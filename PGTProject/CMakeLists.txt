# Makefile generated by CMakefileGenerator.cs (v1.2)
# *DO NOT EDIT*

cmake_minimum_required (VERSION 2.6)
project (UE4)

# CMake Flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_OBJECTS 1 CACHE BOOL "" FORCE)
set(CMAKE_CXX_USE_RESPONSE_FILE_FOR_INCLUDES 1 CACHE BOOL "" FORCE)

# Standard Includes
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-includes.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-definitions.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-headers-ue4.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-headers-project.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-sources-engine.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-sources-project.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-csharp-engine.cmake")
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-csharp-project.cmake")

# Optional Shader Include
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-shaders-engine.cmake")
set_source_files_properties(${ENGINE_SHADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-shaders-project.cmake")
set_source_files_properties(${PROJECT_SHADER_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
source_group("Shader Files" REGULAR_EXPRESSION .*.usf)

# Optional Config Include
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-config-engine.cmake")
set_source_files_properties(${ENGINE_CONFIG_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
include("/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/Intermediate/ProjectFiles/cmake-config-project.cmake")
set_source_files_properties(${PROJECT_CONFIG_FILES} PROPERTIES HEADER_FILE_ONLY TRUE)
source_group("Config Files" REGULAR_EXPRESSION .*.ini)

add_custom_target(PGTProject-Mac-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject Mac DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(PGTProject-IOS-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject IOS DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProject-TVOS-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject TVOS DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProject-Mac-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject Mac Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(PGTProject-IOS-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject IOS Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProject-TVOS-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject TVOS Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProject cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject Mac Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)

add_custom_target(PGTProject-IOS cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject IOS Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProject-TVOS cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProject TVOS Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProjectEditor-Mac-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor Mac DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(PGTProjectEditor-IOS-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor IOS DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProjectEditor-TVOS-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor TVOS DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProjectEditor-Mac-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor Mac Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(PGTProjectEditor-IOS-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor IOS Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProjectEditor-TVOS-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor TVOS Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProjectEditor cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor Mac Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)

add_custom_target(PGTProjectEditor-IOS cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor IOS Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(PGTProjectEditor-TVOS cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" PGTProjectEditor TVOS Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(UE4Editor-Mac-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Editor Mac DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(UE4Editor-Mac-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Editor Mac Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(UE4Editor cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Editor Mac Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)

add_custom_target(UE4Game-Mac-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game Mac DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(UE4Game-IOS-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game IOS DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(UE4Game-TVOS-DebugGame cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game TVOS DebugGame "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(UE4Game-Mac-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game Mac Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)
add_custom_target(UE4Game-IOS-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game IOS Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(UE4Game-TVOS-Shipping cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game TVOS Shipping "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(UE4Game cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game Mac Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress -buildscw VERBATIM)

add_custom_target(UE4Game-IOS cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game IOS Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_custom_target(UE4Game-TVOS cd "/Users/Shared/Epic Games/UE_4.21" && bash "/Users/Shared/Epic Games/UE_4.21/Engine/Build/BatchFiles/Mac/Build.sh" UE4Game TVOS Development "-project=/Users/aleksejhorvat/Documents/dev/IVGT6/PGTProject/PGTProject.uproject" -game -progress VERBATIM)
add_executable(FakeTarget ${ENGINE_HEADER_FILES} ${ENGINE_SOURCE_FILES} ${ENGINE_CSHARP_FILES} ${ENGINE_SHADER_FILES} ${ENGINE_CONFIG_FILES} ${PROJECT_HEADER_FILES} ${PROJECT_SOURCE_FILES} ${PROJECT_CSHARP_FILES} ${PROJECT_SHADER_FILES} ${PROJECT_CONFIG_FILES})
