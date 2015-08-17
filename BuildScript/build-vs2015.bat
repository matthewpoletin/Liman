CLS
premake4 clean
REM premake5 xcode4 --file=premake4.lua --os=macos
REM premake5 codeblocks --file=premake4.lua --os=linux
premake5 vs2015 --file=premake4.lua --os=windows