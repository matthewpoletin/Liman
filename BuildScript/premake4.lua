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
 build_dir = "Build/"
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
print (editorDLL_path)
print(editor_path)
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
	os.copyfile(working_dir .. source_dir .. "Dependencies/Libraries/glew32.dll", working_dir .."Build/" .. game_name .. "/Debug/glew32.dll")
	os.mkdir(working_dir .. "Build/" .. game_name .. "/Release/")
	os.copyfile(working_dir .. source_dir .. "Liman/Dependencies/Libraries/glew32.dll", working_dir .."Build/" .. game_name .. "/Release/glew32.dll")
	os.mkdir(working_dir .. build_dir .. game_name .. "/Release/Resources")
	os.copydir(working_dir .. assets_dir, working_dir ..build_dir .. game_name .. "/Release/Resources/")
end
-- ------------------------------------------------------------------
-- -- Liman solution
-- ------------------------------------------------------------------
solution(sol_name)

	if(premake_ver == 5) then
		startproject(game_name)
	end
	location(working_dir .. "Liman/")
	includedirs { working_dir .. "Liman/Dependencies/Include/" }
	-- flags { "ExtraWarnings", "FatalWarnings", "FloatFast" }
	flags { "Unicode" }

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

		targetname (core_name)
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

		targetname (game_name)
		targetextension ".exe"
		location (working_dir .."Liman/" .. game_path .. "/")
	
		objdir (working_dir .. "Temp/Demo/")
		targetdir (working_dir .. "Build/Demo/%{cfg.buildcfg}")

		files {
			working_dir .. "Liman/".. game_path .. "/**.h",
			working_dir .. "Liman/" .. game_path .."/**.cpp"
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
			"glfw3"
		}

		-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
		-- warnings "Default"

		configuration "Debug"
			defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { "tinyxml2d" }

		configuration "Release"
			defines { "WIN32", "_LIB" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { "tinyxml2r" }

	------------------------------------------------------------------
	-- "EditorDLL" library project
	------------------------------------------------------------------
	project (editorDLL_name)
	
		language "C++"
		kind "ConsoleApp"

		if(premake_ver == 5) then
			dependson { "Core" }
		end

		targetname (editorDLL_name)
		targetextension ".dll"
		location (editorDLL_path)
		
		objdir (working_dir .. "Temp/" .. editorDLL_name)
		targetdir (working_dir .. "Build/" .. editorDLL_name .. "/%{cfg.buildcfg}")

		files {
			working_dir .. "Liman/".. editorDLL_name .. "/**.h",
			working_dir .. "Liman/" .. editorDLL_name .."/**.cpp"
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
			"glfw3"
		}

		-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
		-- warnings "Default"

		configuration "Debug"
			defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { "tinyxml2d" }

		configuration "Release"
			defines { "WIN32", "_LIB" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { "tinyxml2r" }

	------------------------------------------------------------------
	-- "Editor" executable project
	------------------------------------------------------------------
	project (editor_name)
		language "C#"
		kind "WindowedApp"

		if(premake_ver == 5) then
			dependson { core_name }
		end

		targetname (editor_name)
		targetextension ".exe"
		location (editor_path)
	
		objdir (working_dir .. "Temp/Demo/")
		targetdir (working_dir .. "Build/Demo/%{cfg.buildcfg}")

		files {
			editor_path .. "/**.h",
			editor_path .."/**.cpp"
		}

		includedirs { working_dir .. "Liman/Core/" }

		if (_ACTION == "vs2015") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2015" }
		elseif (_ACTION == "vs2013") then
			libdirs { source_dir .. "Dependencies/Libraries/vs2013" }
		end
		links {
			"editorDLL",
			"OpenGL32",
			"glew32s",
			"glfw3"
		}

		-- if(os.get() == "windows") then defines{ "SUBSYSTEM=WINDOWS"} end
		-- warnings "Default"

		configuration "Debug"
			defines { "WIN32", "_LIB", "GLEW_STATIC", "_CRT_SECURE_NO_WARNINGS" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { "tinyxml2d" }

		configuration "Release"
			defines { "WIN32", "_LIB" }
			libdirs { working_dir .. "Liman/Dependencies/Libraries/%{cfg.buildcfg}" }
			links { "tinyxml2r" }
