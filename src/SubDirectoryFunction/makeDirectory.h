#ifndef MAKEDIRECTORY_H
#define MAKEDIRECTORY_H

#ifdef _WIN32
	#ifdef GENERAL_FUNCTIONS_EXPORT
		#define GENERAL_FUNCTIONS_API __declspec(dllexport)
		#pragma message("-- GENERAL_FUNCTIONS_API define as __declspec(dllexport) ")
	#else
		#define GENERAL_FUNCTIONS_API __declspec(dllimport)
		#pragma message("-- GENERAL_FUNCTIONS_API define as __declspec(dllimport) ")
	#endif
#else
	#define GENERAL_FUNCTIONS_API
#endif

namespace generalFunctions {

    GENERAL_FUNCTIONS_API void makeDirectory();

}


#endif //MAKEDIRECTORY_H