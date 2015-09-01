-- cd Desktop/justbear/Liman/BuildScript/
-- build-vs2015.bat
dofile("utils.lua")

------------------------------------------------------------------
------------------------------------------------------------------
---------------     premake script        ------------------------
------------------------------------------------------------------
------------------------------------------------------------------

os.chdir(os.getcwd() .. "./../../")
working_dir = os.getcwd() .. "/"
 assets_dir = "Assets/"
 source_dir = "Liman/"
  dependsies_dir = "Dependencies/"
   libraries_dir = "Libraries/"
   include_dir = "Include/"
 build_dir = "Build/"
  resources_dir = "Resources/"
 temp_dir = "Temp/"
 core_lib_dir = "Lib/"
------------------------------------------------------------------
includes_path = working_dir .. source_dir .. dependsies_dir .. include_dir
libraries_path = working_dir .. source_dir .. dependsies_dir .. libraries_dir
------------------------------------------------------------------
engine_name = "Liman"
sol_name = "Liman"
sol_dir = working_dir .. source_dir
core_name = "Core"
core_path = working_dir .. source_dir .. core_name .. "/"
game_name = "Demo"
game_path = working_dir .. source_dir .. game_name .. "/"
editor_name = engine_name .. "Editor"
editor_path = working_dir .. source_dir .. editor_name .. "/"
editorDLL_name = editor_name .. "DLL"
editorDLL_path =  working_dir .. source_dir .. editorDLL_name .. "/"
-- ------------------------------------------------------------------
if (_ACTION == "clean") then
	cleaning = true else cleaning = false
end
-- ------------------------------------------------------------------
if (cleaning) then premake_ver = 4  else premake_ver = 5 end
-- ------------------------------------------------------------------
if (cleaning) then
	os.rmdir(working_dir .. "Temp")
	os.rmdir(working_dir .. "Lib")
	os.rmdir(working_dir .. "Build")
end
-- ------------------------------------------------------------------
if (cleaning ~= true) then
	os.mkdir(working_dir .. "Build/" .. game_name .. "/Debug/")
	os.mkdir(working_dir .. "Build/" .. game_name .. "/Release/")
	os.mkdir(working_dir .. build_dir .. game_name .. "/Release/Resources")
	os.copydir(working_dir .. assets_dir, working_dir ..build_dir .. game_name .. "/Release/Resources/")
end
------------------------------------------------------------------
if (_ACTION == "vs2015") then
	lib_ide_path = libraries_path .. "/vs2015"
elseif (_ACTION == "vs2013") then
	lib_ide_path = libraries_path .. "/vs2013"
else
	lib_ide_path = ""
end
------------------------------------------------------------------
-- Liman solution
------------------------------------------------------------------
solution(sol_name)

	if(premake_ver == 5) then
		startproject(game_name)
	end
	location(working_dir .. "Liman/")
	includedirs { includes_path }

	libdirs { libraries_path, lib_ide_path, lib_ide_path .. "/%{cfg.buildcfg}" }

	configurations { "Debug", "Release" }

	if _ACTION == vs2013 or _ACTION == vs2015 then
		platforms { "Win32", "x64" }
		system "windows"
	elseif _ACTION == gmake then
		platforms { "linux" }
		-- system "windows"
	end

	-- filters { "kind:*Lib" }
	-- 	defines { "_LIB" }

	------------------------------------------------------------------
	-- "Core" library project
	------------------------------------------------------------------
	project (core_name)
		language "C++"
		kind "StaticLib"

		targetname (core_name)
		targetextension ".lib"
		location (working_dir .. source_dir .. core_name .. "/")

		objdir (working_dir .. temp_dir .. core_name .. "/%{cfg.buildcfg}")
		targetdir (working_dir .. core_lib_dir .. "Core/%{cfg.buildcfg}")
		
		files {
			working_dir .. source_dir .. core_name .. "/**.h",
			working_dir .. source_dir .. core_name .. "/**.cpp"
		}

		links {
			"OpenGL32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}

		configuration "Debug"
			defines { "GLEW_STATIC" } 
			defines { "WIN32", "_LIB", "_CONSOLE" }
			defines { "DEBUG", "_DEBUG", "_DEBUG_", "Debug" }
			flags { "Unicode" }
			flags { "Symbols" }
			if (premake_ver == 5) then optimize "Debug" end

		configuration "Release"
			flags { "Unicode" }
			defines { "GLEW_STATIC" }
			defines { "WIN32", "_LIB", "_CONSOLE" }
			defines { "NDEBUG", "NDebug" }
			flags { "Optimize" }
			if (premake_ver == 5) then optimize "Full" end
	
	------------------------------------------------------------------
	-- "Demo" executable project
	------------------------------------------------------------------
	project (game_name)
		language "C++"
		kind "ConsoleApp"

		if(premake_ver == 5) then
			dependson { "Core" }
		end

		targetname (game_name)
		targetextension ".exe"
		location (working_dir .. source_dir .. game_name .. "/")
	
		objdir (working_dir .. temp_dir .. game_name .. "/%{cfg.buildcfg}")
		targetdir (working_dir .. build_dir .. "Demo/%{cfg.buildcfg}")

		files {
			working_dir .. source_dir .. game_name .. "/**.h",
			working_dir .. source_dir .. game_name .."/**.cpp"
		}

		includedirs { working_dir .. source_dir .. "Core/" }

		libdirs { working_dir .. core_lib_dir .. "Core/%{cfg.buildcfg}" }
		links { core_name }
		links {
			"OpenGL32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}

		defines { "WIN32", "_CONSOLE" } 
		debugdir("$(OutDir)")

		configuration "Debug"
			defines { "GLEW_STATIC" } 
			defines { "DEBUG", "_DEBUG", "_DEBUG_", "Debug" }
			flags { "Unicode" }
			flags { "Symbols" }
			if (premake_ver == 5) then optimize "Debug" end

		configuration "Release"
			flags { "Unicode" }
			defines { "GLEW_STATIC" }
			defines { "NDEBUG", "NDebug" }
			flags { "Optimize" }
			if (premake_ver == 5) then optimize "Full" end

	-- ------------------------------------------------------------------
	-- -- "EditorDLL" library project
	-- ------------------------------------------------------------------
	-- project (editorDLL_name)
	
	-- 	language "C++"
	-- 	kind "ConsoleApp"

	-- 	if(premake_ver == 5) then
	-- 		dependson { "Core" }
	-- 	end

	-- 	targetname (editorDLL_name)
	-- 	targetextension ".dll"
	-- 	location (editorDLL_path)
		
	-- 	objdir (working_dir .. temp_dir .. editorDLL_name .. "/%{cfg.buildcfg}")
	-- 	targetdir (working_dir .. build_dir .. editorDLL_name .. "/%{cfg.buildcfg}")

	-- 	files {
	-- 		working_dir .. source_dir .. editorDLL_name .. "/**.h",
	-- 		working_dir .. source_dir .. editorDLL_name .."/**.cpp"
	-- 	}

	-- 	includedirs { working_dir .. source_dir .. "Core/" }

	-- 	libdirs { working_dir .. core_lib_dir .. "Core/%{cfg.buildcfg}" }
	-- 	links {
	-- 		core_name
	-- 	}

	-- 	links {
	-- 	"OpenGL32",
	-- 	"glew32s",
	-- 	"glfw3",
	-- 	"tinyxml2"
	-- }

	-- 	defines { "WIN32", "_LIB" }
		
	-- 	-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
	-- 	-- warnings "Default"

	-- 	-- defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }

	-- 	-- configuration "Debug"
	-- 	-- 	defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }

	-- 	-- configuration "Release"
	-- 	-- 	defines { "WIN32", "_LIB" }

	-- ------------------------------------------------------------------
	-- -- "Editor" executable project
	-- ------------------------------------------------------------------
	-- project (editor_name)
	-- 	language "C#"
	-- 	kind "WindowedApp"

	-- 	if(premake_ver == 5) then
	-- 		dependson { core_name }
	-- 	end

	-- 	targetname (editor_name)
	-- 	targetextension ".exe"
	-- 	location (editor_path)
	
	-- 	objdir (working_dir .. temp_dir .. editor_name .. "/%{cfg.buildcfg}")
	-- 	targetdir (working_dir .. build_dir .. "/Demo/%{cfg.buildcfg}")

	-- 	files {
	-- 		editor_path .. "/**.h",
	-- 		editor_path .."/**.cpp"
	-- 	}

	-- 	includedirs { working_dir .. "Liman/Core/" }

	-- 	libdirs { working_dir .. core_lib_dir .. "Core/%{cfg.buildcfg}" }
	-- 	links {
	-- 		"editorDLL"
	-- 	}

	-- 	defines { "WIN32" }

	-- 	-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
	-- 	-- warnings "Default"

	-- 	-- configuration "Debug"
	-- 	-- 	defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }
	-- 	-- 	libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
	-- 	-- 	links {  }

	-- 	-- configuration "Release"
	-- 	-- 	libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
	-- 	-- 	links {  }