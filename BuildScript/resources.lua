require("C://Users/Code/Desktop/justbear/Liman/BuildScript/scripts/utils.lua")

-- os.mkdir(working_dir .. "Build/" .. game_name .. "/Debug/")
os.mkdir(working_dir .. "Build/" .. game_name .. "/Release/")
os.mkdir(working_dir .. build_dir .. game_name .. "/Release/Resources")
os.copydir(working_dir .. assets_dir, working_dir ..build_dir .. game_name .. "/Release/Resources/")