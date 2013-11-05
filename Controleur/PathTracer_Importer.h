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

		void Initialize (
			Float4*		 global__cameraDirection,
			Float4*		 global__cameraScreenX,
			Float4*		 global__cameraScreenY,
			Float4*		 global__cameraPosition,
			Triangle*	*global__triangulation,
			Light*		*global__lights,
			Material*	*global__materiaux,
			Texture*	*global__textures,
			Uchar4*		*global__textureData,
			uint*		 global__triangulationSize,
			uint*		 global__lightsSize,
			uint*		 global__materiauxSize,
			uint*		 global__texturesSize,
			uint*		 global__textureDataSize,
			uint*		 global__imageWidth,
			uint*		 global__imageHeight,
			uint*		 global__imageSize,
			SunLight*	 global__sun,
			Sky*		 global__sky
			);

		virtual void Import() = 0;



		//	Attributs

		Float4*		 ptr__global__cameraDirection;
		Float4*		 ptr__global__cameraScreenX;
		Float4*		 ptr__global__cameraScreenY;
		Float4*		 ptr__global__cameraPosition;

		Triangle*	*ptr__global__triangulation;
		Light*		*ptr__global__lights;
		Material*	*ptr__global__materiaux;
		Texture*	*ptr__global__textures;
		Uchar4*		*ptr__global__textureData;
		uint*		 ptr__global__triangulationSize;
		uint*		 ptr__global__lightsSize;
		uint*		 ptr__global__materiauxSize;
		uint*		 ptr__global__texturesSize;
		uint*		 ptr__global__textureDataSize;

		uint*		 ptr__global__imageWidth;
		uint*		 ptr__global__imageHeight;
		uint*		 ptr__global__imageSize;

		SunLight*	 ptr__global__sun;
		Sky*		 ptr__global__sky;


	};
}

#endif