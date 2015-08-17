#include "FileTools.h"

namespace liman {

	bool FileExists(std::string pathToFile)
	{
		FILE* file = fopen(pathToFile.c_str(), "r");
		if (file != NULL)
		{
			fclose(file);
			return true;
		}
		else
		{
			return false;
		}
	}

}