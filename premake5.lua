

workspace "ShoppingList"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ShoppingList"
    location "ShoppingList"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor",
        -- "Dependencies/glew-2.1.0/include",
        -- "Dependencies/GLFW/include",
        -- "Dependencies/glad/include"
    }

    libdirs
    {
        -- "Dependencies/glew-2.1.0/lib/Release/x64",
        -- "Dependencies/GLFW/lib-vc2022"
    }

    links
    {
        -- "glew32s.lib",
        -- "glfw3.lib",
        -- "opengl32.lib"
    }

    -- defines "GLEW_STATIC"

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        buildoptions "/utf-8"

    filter "configurations:Debug"
        defines "GM_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GM_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GM_DIST"
        optimize "On"