#ifndef PATHTRACER_PATHTRACERLUMENRTIMPORTER
#define PATHTRACER_PATHTRACERLUMENRTIMPORTER

#include "../Controleur/PathTracer_Importer.h"
#include <maya/MString.h>
#include <maya/MDagPath.h>
#include <maya/MPoint.h>
#include <maya/MColor.h>
#include <maya/MVector.h>
#include <maya/MFnLight.h>
#include <maya/MFnPointLight.h>
#include <maya/MFnDirectionalLight.h>
#include <maya/MFnSpotLight.h>

namespace PathTracerNS
{

	inline Float4	permute_xyz_to_zxy	(const MPoint &m)	{return Float4((float) (m.z/m.w), (float) (m.x/m.w), (float) (m.y/m.w), 1.f);};
	inline Float4	permute_xyz_to_xzy	(const MPoint &m)	{return Float4((float) (m.x/m.w), (float) (m.z/m.w), (float) (m.y/m.w), 1.f);};

	inline Float4 ToFloat4 (const MPoint& v)	{return Float4((float) (v.x/v.w), (float) (v.y/v.w), (float) (v.z/v.w), 1.f);};
	inline Float4 ToFloat4 (const MVector& v)	{return Float4((float) v.x, (float) v.y, (float) v.z, 1.f);};
	inline Float4 ToFloat4 (const MColor& v)	{return Float4((float) v.r, (float) v.g, (float) v.b, v.a);};

	class PathTracerMayaImporter : public PathTracerImporter
	{
	public :

		PathTracerMayaImporter():PathTracerImporter() {}


		virtual void Import				();

		void ImportScene				();
		void ImportLights				();
		void LoadSky					();

		void SetCam						();
		bool GetCam						(const MString &cameraName, MDagPath &camera);

		void Light_Create				(Light& l, const MMatrix& M, const MFnPointLight& fnLight);
		void Light_Create				(Light& l, const MMatrix& M, const MFnDirectionalLight& fnLight);
		void Light_Create				(Light& l, const MMatrix& M, const MFnSpotLight& fnLight);
		void Material_Create			(Material *This);
		void Triangle_Create			(Triangle *This,
			Float4 const *s1, Float4 const *s2, Float4 const *s3,
			Float2 const *p1, Float2 const *p2, Float2 const *p3,
			Float4 const *n1, Float4 const *n2, Float4 const *n3,
			Float4 const *t1, Float4 const *t2, Float4 const *t3,
			Float4 const *bt1, Float4 const *bt2, Float4 const *bt3,
			uint matIndex );

		inline double		Triangle_MaxSquaredDistanceTo	(Triangle const	*This, Triangle const *t) { return max(max(Vector_SquaredDistanceTo(&This->S1, &t->S1), Vector_SquaredDistanceTo(&This->S2, &t->S2)), Vector_SquaredDistanceTo(&This->S3, &t->S3));};

	};



}


#endif