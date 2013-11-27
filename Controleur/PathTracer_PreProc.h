
#ifndef PATHTRACER_PREPROC
#define PATHTRACER_PREPROC

//#define MAYA

/***********************************************************************************/
//							PARTIE SPECIFIQUE A LA MACHINE


#define PATHTRACER_FOLDER "C:\\Users\\Alexandre Djerbetian\\Documents\\Visual Studio 2012\\Projects\\OpenCL_PathTracer\\src\\"
#define PATHTRACER_SCENE_FOLDER "C:\\Users\\Alexandre Djerbetian\\Pictures\\Maya\\"
/***********************************************************************************/


#define MAX_REFLECTION_NUMBER 10
#define BVH_MAX_DEPTH 30
#define MAX_LIGHT_SIZE 30
#define ALIGN(X) __declspec(align(X))


#ifdef LRT_PRODUCT

#include "Tools/Defines.h"
#include "toolsLog.h"
#define CONSOLE tools::ConsoleOut()
#define ENDL tools::endl


#else

//	Cette variable permet d'enlever le conflit entre STR ou WSTR lorsque le projet est seul
//#define UNICODE

#include <assert.h>
#include <iostream>
#define RTASSERT(X) assert(X)
#define CONSOLE std::cout
#define ENDL std::endl

#endif


#endif
