-- cd Desktop/justbear/Liman/BuildScript/
-- build-vs2015.bat
dofile("utils.lua")

------------------------------------------------------------------
------------------------------------------------------------------
---------------     premake script        ------------------------
------------------------------------------------------------------
------------------------------------------------------------------

core_name = "Core"
core_proj_name = core_name
game_name = "Demo"
game_proj_name = game_name
editor_name = "limanEditor"
editor_proj_name = editor_name
editor_dll_name = editor_name .. "DLL"
editor_dll_proj_name = editor_dll_name
------------------------------------------------------------------
os.chdir(os.getcwd() .. "./../../")
working_dir = os.getcwd() .. "/"
assets_dir = working_dir .. "Assets/"
source_dir = working_dir .. "Liman/"
------------------------------------------------------------------
if (_ACTION == "clean") then
	cleaning = true else cleaning = false
end
------------------------------------------------------------------
if (cleaning) then premake_ver = 4  else premake_ver = 5 end
------------------------------------------------------------------
if (cleaning) then
	os.rmdir(working_dir .. "Temp")
	os.rmdir(working_dir .. "Lib")
	os.rmdir(working_dir .. "Build")
end
------------------------------------------------------------------

if (cleaning ~= true) then
	os.mkdir(working_dir .. "Build/" .. game_proj_name .. "/Debug/")
	os.copyfile(working_dir .."Liman/Dependencies/Libraries/glew32.dll", working_dir .."Build/" .. game_proj_name .. "/Debug/glew32.dll")
	os.mkdir(working_dir .. "Build/" .. game_proj_name .. "/Release/")
	os.copyfile(working_dir .."Liman/Dependencies/Libraries/glew32.dll", working_dir .."Build/" .. game_proj_name .. "/Release/glew32.dll")
	os.mkdir(working_dir .. "Build/" .. game_proj_name .. "/Release/Resources")
	os.copydir(working_dir .."Assets/", working_dir .."Build/" .. game_proj_name .. "/Release/Resources/")
end
------------------------------------------------------------------
if (_ACTION == "vs2015") then
	lib_path = source_dir .. "Dependencies/Libraries/vs2015"
elseif (_ACTION == "vs2013") then
	lib_path = source_dir .. "Dependencies/Libraries/vs2013"
else
	lib_path = ""
end
------------------------------------------------------------------
-- Linan solution
------------------------------------------------------------------
solution "LimanGame"

	if(premake_ver == 5) then
		startproject(game_name)
	end
	location(working_dir .. "Liman/")
	includedirs { working_dir .. "Liman/Dependencies/Include/" }
	-- flags { "ExtraWarnings", "FatalWarnings", "FloatFast" }
	flags { "Unicode" }

	libdirs { lib_path, lib_path .. "/%{cfg.buildcfg}" }

	configurations { "Debug", "Release" }

	configuration "Debug"
		defines { "DEBUG", "_DEBUG", "_DEBUG_" }
		flags { "Symbols" }

    	-- targetsuffix ("-" .. _ACTION .. "-Debug")

	configuration "Release"
		defines { "NDEBUG" }
		flags { "Optimize" }

	------------------------------------------------------------------
	-- "Core" library project
	------------------------------------------------------------------
	project (core_name)
		language "C++"
		kind "StaticLib"

		targetname (core_proj_name)
		targetextension ".lib"
		location (working_dir .. "Liman/Core/")

		objdir (working_dir .. "Temp/Core/")
		targetdir (working_dir .. "Lib/Core/")
		
		files {
			working_dir .. "Liman/Core/**.h",
			working_dir .. "Liman/Core/**.cpp"
		}

		if (_ACTION == "vs2015") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2015" }
		elseif (_ACTION == "vs2013") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2013" }
		end
		links {
			"OpenGL32",
			"glew32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}

		-- warnings "Default"

		-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end

		configuration "Debug"
			defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS", "_CRT_NONSTDC_NO_DEPRECATE" }
			libdirs { working_dir .. "Lib/Core/%{cfg.buildcfg}" }

		configuration "Release"
			defines { "NDEBUG" }
			libdirs { working_dir .. "Lib/Core/%{cfg.buildcfg}" }

	------------------------------------------------------------------
	-- "Demo" executable project
	------------------------------------------------------------------
	project (game_name)
		language "C++"
		kind "ConsoleApp"

		if(premake_ver == 5) then
			dependson { "Core" }
		end

		targetname (game_proj_name)
		targetextension ".exe"
		location (working_dir .."Liman/" .. game_proj_name .. "/")
	
		objdir (working_dir .. "Temp/Demo/")
		targetdir (working_dir .. "Build/Demo/%{cfg.buildcfg}")

		files {
			working_dir .. "Liman/".. game_proj_name .. "/**.h",
			working_dir .. "Liman/" .. game_proj_name .."/**.cpp"
		}

		includedirs { working_dir .. "Liman/Core/" }

		if (_ACTION == "vs2015") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2015" }
		elseif (_ACTION == "vs2013") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2013" }
		end
		links {
			"Core",
			"OpenGL32",
			"glew32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}

		-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
		-- warnings "Default"

		configuration "Debug"
			defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { }

		configuration "Release"
			defines { "WIN32", "_LIB" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links {  }

	------------------------------------------------------------------
	-- "editorDLL" library project
	------------------------------------------------------------------
	project (editor_dll_name)
	
		language "C++"
		kind "ConsoleApp"

		if(premake_ver == 5) then
			dependson { "Core" }
		end

		targetname (editor_dll_proj_name)
		targetextension ".dll"
		location (working_dir .."Liman/" .. editor_dll_proj_name .. "/")
		
		objdir (working_dir .. "Temp/" .. editor_dll_proj_name)
		targetdir (working_dir .. "Build/" .. editor_dll_proj_name .. "/%{cfg.buildcfg}")

		files {
			working_dir .. "Liman/".. editor_dll_proj_name .. "/**.h",
			working_dir .. "Liman/" .. editor_dll_proj_name .."/**.cpp"
		}

		includedirs { working_dir .. "Liman/Core/" }

		if (_ACTION == "vs2015") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2015" }
		elseif (_ACTION == "vs2013") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2013" }
		end
		links {
			"Core",
			"OpenGL32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}

		-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
		-- warnings "Default"

		configuration "Debug"
			defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links {  }

		configuration "Release"
			defines { "WIN32", "_LIB" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links {  }