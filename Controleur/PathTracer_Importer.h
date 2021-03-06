#ifndef PATHTRACER_PATHTRACERIMPORTER
#define PATHTRACER_PATHTRACERIMPORTER


#include "PathTracer_Utils.h"
#include "PathTracer_Structs.h"


namespace PathTracerNS
{

	class PathTracerImporter
	{

	public:

		//	M�thodes

		PathTracerImporter();

		void Initialize (GlobalVars& globalVars);

		virtual void Import(uint image_width, uint image_height, bool loadSky) = 0;



		//	Attributs

		Float4*		 ptr__global__cameraDirection;
		Float4*		 ptr__global__cameraRight;
		Float4*		 ptr__global__cameraUp;
		Float4*		 ptr__global__cameraPosition;

		Triangle*	*ptr__global__triangulation;
		Light*		*ptr__global__lights;
		Material*	*ptr__global__materiaux;
		Texture*	*ptr__global__textures;
		Uchar4*		*ptr__global__texturesData;
		uint*		 ptr__global__triangulationSize;
		uint*		 ptr__global__lightsSize;
		uint*		 ptr__global__materiauxSize;
		uint*		 ptr__global__texturesSize;
		uint*		 ptr__global__texturesDataSize;

		uint*		 ptr__global__imageWidth;
		uint*		 ptr__global__imageHeight;
		uint*		 ptr__global__imageSize;

		Sky*		 ptr__global__sky;


	};
}

#endif