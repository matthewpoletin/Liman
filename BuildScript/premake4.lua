-- cd Desktop/justbear/Liman/BuildScript/
-- build-vs2015.bat
dofile("utils.lua")

------------------------------------------------------------------
------------------------------------------------------------------
---------------     premake script        ------------------------
------------------------------------------------------------------
------------------------------------------------------------------

os.chdir(os.getcwd() .. "/../../")
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
------------------------------------------------------------------
if (_ACTION == "clean") then
	cleaning = true else cleaning = false
end
------------------------------------------------------------------
if (cleaning or os.is("macosx")) then premake_ver = 4  else premake_ver = 5 end
------------------------------------------------------------------
if(os.is("macosx")) then ide_os = "macosx"
elseif(os.is("windows")) then ide_os = "windows"
end
------------------------------------------------------------------
-- if (cleaning) then
-- 	os.rmdir(working_dir .. "Temp")
-- 	os.rmdir(working_dir .. "Lib")
-- 	os.rmdir(working_dir .. "Build")
-- end
------------------------------------------------------------------
if (cleaning ~= true) then
	os.mkdir(working_dir .. build_dir .. game_name .. "/Debug/")
	os.mkdir(working_dir .. build_dir .. game_name .. "/Release/")
	os.mkdir(working_dir .. build_dir .. game_name .. "/Release/Resources")
	os.copydir(working_dir .. assets_dir, working_dir ..build_dir .. game_name .. "/Release/Resources/")
end
------------------------------------------------------------------
	if (_ACTION == "vs2015") then
	lib_ide_path = libraries_path .. "/vs2015"
elseif (_ACTION == "vs2013") then
	lib_ide_path = libraries_path .. "/vs2013"
elseif (_ACTION == "xcode4") then
	lib_ide_path = libraries_path .. "xcode"
else
	lib_ide_path = libraries_path
end
print(lib_ide_path)
------------------------------------------------------------------
-- Liman solution
------------------------------------------------------------------
solution(sol_name)

	if(premake_ver == 5) then
		startproject(game_name)
	end
	location(working_dir .. "Liman/")
	includedirs { includes_path }

	if (ide_os == "windows") then
		platforms { "x32", "x64" }
		if (premake_ver == 5) then system "windows" end
		defines { "WINDOWS" }
	elseif (ide_os == "linux") then
	elseif (ide_os == "macosx") then
		-- platforms { "osX", "ios" }
		-- system "macosx"
		defines { "MACOSX" }
	end

	configurations { "Debug", "Release" }

	configuration "Debug"
		libdirs { libraries_path, lib_ide_path, lib_ide_path .. "/Debug" }
		defines { "DEBUG", "_DEBUG", "_DEBUG_", "Debug" }

	configuration "Release"
		libdirs { libraries_path, lib_ide_path, lib_ide_path .. "/Release" }
		defines { "NDEBUG", "NDebug" }

	------------------------------------------------------------------
	-- "Core" library project
	------------------------------------------------------------------
	project (core_name)
		language "C++"
		kind "StaticLib"

		targetname (core_name)
		if (ide_os == "windows") then targetextension ".lib" end
		location (working_dir .. source_dir .. core_name .. "/")

		files {
			working_dir .. source_dir .. core_name .. "/**.h",
			working_dir .. source_dir .. core_name .. "/**.cpp"
		}

		links {
			-- "OpenGL32",
			"OpenGL.framework",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}

		configuration "Debug"
			defines { "GLEW_STATIC" } 
			defines { "_LIB", "_CONSOLE" }
			flags { "Unicode" }
			flags { "Symbols" }
			objdir (working_dir .. temp_dir .. core_name .. "/Debug")
			targetdir (working_dir .. core_lib_dir .. "Core/Debug")
			if (premake_ver == 5) then optimize "Debug" end

		configuration "Release"
			flags { "Unicode" }
			defines { "GLEW_STATIC" }
			defines { "_LIB", "_CONSOLE" }
			flags { "Optimize" }
			objdir (working_dir .. temp_dir .. core_name .. "/Release")
			targetdir (working_dir .. core_lib_dir .. "Core/Release")
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
		if (ide_os == "windows") then targetextension ".exe" end
		location (working_dir .. source_dir .. game_name .. "/")

		files {
			working_dir .. source_dir .. game_name .. "/**.h",
			working_dir .. source_dir .. game_name .."/**.cpp"
		}

		includedirs { working_dir .. source_dir .. "Core/" }

		links { "Core" }
		if (ide_os == "macosx") then
		links {
			"glfw3.lib",
			"OpenGL.framework",
			"Cocoa.framework",
			"OpenGL.framework",
			"IOKit.framework",
			"CoreVideo.framework" 
		}
		elseif (ide_os == "windows") then
		links {
			"OpenGL32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}
		end

		defines { "_CONSOLE" }

		configuration "Debug"
			defines { "GLEW_STATIC" } 
			flags { "Unicode" }
			flags { "Symbols" }
			libdirs { working_dir .. core_lib_dir .. "Core/Debug" }
			debugdir(working_dir .. build_dir .. game_name .. "/Debug")
			objdir (working_dir .. temp_dir .. game_name .. "/Debug")
			targetdir (working_dir .. build_dir .. "Demo/Debug")
			if (premake_ver == 5) then optimize "Debug" end

		configuration "Release"
			flags { "Unicode" }
			defines { "GLEW_STATIC" }
			flags { "Optimize" }
			libdirs { working_dir .. core_lib_dir .. "Core/Release" }
			debugdir(working_dir .. build_dir .. game_name ..  "/Release")
			objdir (working_dir .. temp_dir .. game_name .. "/Release")
			targetdir (working_dir .. build_dir .. "Demo/Release")
			if (premake_ver == 5) then optimize "Full" end

	------------------------------------------------------------------
	-- "EditorDLL" library project
	------------------------------------------------------------------
	project (editorDLL_name)
	
		language "C++"
		kind "SharedLib"

		if(premake_ver == 5) then
			dependson { "Core" }
		end

		targetname (editorDLL_name)
		if(ide_os == "windows") then targetextension ".dll" end
		location (editorDLL_path)
		
		files {
			working_dir .. source_dir .. editorDLL_name .. "/**.h",
			working_dir .. source_dir .. editorDLL_name .."/**.cpp"
		}

		includedirs { working_dir .. source_dir .. "Core/" }

		libdirs { working_dir .. core_lib_dir .. "Core/Debug" }
		
		links { "Core" }
		if (ide_os == "macosx") then
		links {
			"glfw3.lib",
			"OpenGL.framework",
			"Cocoa.framework",
			"OpenGL.framework",
			"IOKit.framework",
			"CoreVideo.framework" 
		}
		elseif (ide_os == "windows") then
		links {
			"OpenGL32",
			"glew32s",
			"glfw3",
			"tinyxml2"
		}
		end

		defines { "_LIB" }

		configuration "Debug"
			defines { "GLEW_STATIC" } 
			flags { "Unicode" }
			flags { "Symbols" }
			libdirs { working_dir .. core_lib_dir .. "Core/Debug" }
			objdir (working_dir .. temp_dir .. editorDLL_name .. "/Debug")
			-- targetdir (working_dir .. build_dir .. editorDLL_name .. "/Debug")
			targetdir (working_dir .. build_dir .. editor_name .. "/Debug")
			if (premake_ver == 5) then optimize "Debug" end

		configuration "Release"
			flags { "Unicode" }
			flags { "Optimize" }
			defines { "GLEW_STATIC" }
			libdirs { working_dir .. core_lib_dir .. "Core/Release" }
			objdir (working_dir .. temp_dir .. editorDLL_name .. "/Release")
			targetdir (working_dir .. build_dir .. editorDLL_name .. "/Release")
			if (premake_ver == 5) then optimize "Full" end

	------------------------------------------------------------------
	-- "Editor" executable project
	------------------------------------------------------------------
	project (editor_name)
		language "C#"
		kind "WindowedApp"
		if (ide_os == "windows") then clr "Unsafe" end

		if(premake_ver == 5) then
			dependson { editorDLL_name }
		end

		targetname (editor_name)
		if (ide_os == "windows") then targetextension ".exe" end
		location (editor_path)
	

		files {
			editor_path .. "/**.resx",
			editor_path .."/**.cs",
			editor_path .."/**.config",
			editor_path .."/**.settings"
		}

		includedirs { working_dir .. "Liman/Core/" }

		links {
			"LimanEditorDLL"
		}

		links {
			"System",
			"System.Windows.Forms",
			"System.Xml",
			"System.Data",
			"WindowsBase"
			-- ,"System.IO.Packaging"
		}
		defines { "WINDOWED" }
		defines { "TRACE" }
		defines { "/unsafe" }


		configuration "Debug"
			defines { "GLEW_STATIC" } 
			flags { "Unicode" }
			flags { "Symbols" }
			libdirs { working_dir .. core_lib_dir .. "Core/Debug" }
			objdir (working_dir .. temp_dir .. editor_name .. "/Debug")
			targetdir (working_dir .. build_dir .. editor_name .. "/Debug")
			debugdir(working_dir .. build_dir .. game_name .. "/Debug")
			if (premake_ver == 5) then optimize "Debug" end

		configuration "Release"
			defines { "GLEW_STATIC" }
			flags { "Unicode" }
			flags { "Optimize" }
			libdirs { working_dir .. core_lib_dir .. "Core/Release" }
			objdir (working_dir .. temp_dir .. editor_name .. "/Release")
			targetdir (working_dir .. build_dir .. editor_name .. "/Release")
			debugdir(working_dir .. build_dir .. game_name ..  "/Release")
			if (premake_ver == 5) then optimize "Full" end