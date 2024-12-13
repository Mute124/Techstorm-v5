﻿
set(ENGINE_SOURCES 
	# Engine Core
    "Common.h" 
    "Common.cpp"
    "engine.h" 
    "engine.cpp"
    "BasicCore.h" 
    
    # Project
    "Project.h" 
    "Project.cpp" 

	# Renderer
    "renderer/Window.h" 
    "renderer/Window.cpp" 
    "renderer/Renderer.h" 
    "renderer/Renderer.cpp"
    "renderer/Color.h" 
    "renderer/GameObject.h" 
    "renderer/GameObject.cpp"
<<<<<<< HEAD
    "renderer/GameCamera.h" 
    "renderer/GameCamera.cpp" 
=======
    "input/Input.h" 
    "math/Vector.cpp" 
    "renderer/GameCamera.h" 
    "renderer/GameCamera.cpp" 
    "Common.h" 
>>>>>>> 54653e5aab996b3ca5dfae6c481ea281d8cba5dc
    "renderer/RenderLayer.h" 
    "renderer/GameObjectRegistry.h"
    "renderer/GameObjectRegistry.cpp" 
    "renderer/objects/PlaneObject.h"
    "renderer/IGameObjectGate.h"
    "renderer/WindowDecorations.h"
    "renderer/GameUI.h"
    "renderer/GameUI.cpp"

    # Utils
    "Utils/Singleton.h" 
    "utils/DoublyLinkedList.h" 
    "utils/Gate.h" 
    "utils/Globals.h"

    # Math
    "math/Vector.h" 
    "math/Vector.cpp" 
	
    # Input
    "input/Input.h" 
    "input/Input.cpp"

    # Config
    "conf/Config.h"
    "conf/Config.cpp"

    # File system
    "fs/FileSystem.h"
    "fs/FileSystem.cpp"

    # Physics
    "physics/Physics.h" 
    "physics/Physics.cpp"
    "physics/Listeners.h"
    "physics/Listeners.cpp"
    "physics/Layers.h"
    "physics/Layers.cpp"

    # Modding
    "modding/ScriptingAPI.h"
    "modding/ScriptingAPI.cpp"
    "modding/ModLoader.h"
    "modding/ModLoader.cpp"
    "modding/Mod.h"
    "modding/Mod.cpp"

    # Debugging
    "EReturnCode.h"
    "dbg/Logging.h" 
    "dbg/Debugging.h"
    "dbg/Errors.h"

    # Game Tools
    "world/world.h" 
    "world/tools/Terrain.h" 

)

# Project shared library
add_library(Techstorm SHARED 
    ${ENGINE_SOURCES}
)



# Organize files in Visual Studio
foreach(source IN LISTS ENGINE_SOURCES)
    get_filename_component(source_path "${source}" PATH)
    string(REPLACE "/" "\\" source_path_msvc "${source_path}")
    source_group("${source_path_msvc}" FILES "${source}")
endforeach()

target_include_directories(Techstorm PRIVATE ${PROJECT_SOURCE_DIR}/include )

target_link_libraries(Techstorm PUBLIC
    raylib 
    joltphysics::joltphysics 
    joltphysics_DEPS_TARGET
    libconfig::libconfig
    libconfig_libconfig_libconfig++_DEPS_TARGET
    sol2::sol2
    Angelscript::angelscript
    eventpp::eventpp
    rmlui::rmlui
    rmlui_DEPS_TARGET
)

# Set output name for Windows/Linux
if(WIN32)
    set_target_properties(Techstorm PROPERTIES OUTPUT_NAME "Techstorm.dll" )
elseif(UNIX)
    set_target_properties(Techstorm PROPERTIES OUTPUT_NAME "Techstorm.so") 
endif()