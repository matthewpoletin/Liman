/**
 * @file Resource.h
 * @author matthewpoletin
 */

#pragma once

#include <string>

namespace liman {

	class Resource {
	public:
		// Name of resource
		std::string m_name;

		/**
		 * Resource constructor
		 * @param name Resource name
		 */
		explicit Resource(const std::string &name);
	};

}