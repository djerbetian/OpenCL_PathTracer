#include "RayTracer.h"
#include "../Controleur/PathTracer.h"
#include "PathTracer_MayaImporter.h"

#include <maya/MItDag.h>
#include <maya/MFnMesh.h>
#include <maya/MIOStream.h>
#include <maya/MPointArray.h>
#include <maya/MDagPath.h>
#include <maya/MFnCamera.h>
#include <maya/MImage.h>
#include <maya/MMatrix.h>
#include <maya/MFnTransform.h>
#include <maya/MEulerRotation.h>

#include "../Tone Mapping/ToneMapping.h"

const MString RayTracer::cameraName = "raytracingCamera";
const MString RayTracer::destinationFile = "C:\\Users\\Alexandre Djerbetian\\Pictures\\Maya\\raytrace.bmp";
const MString RayTracer::fileExtension = "bmp";


MString toString(const MPoint& M)
{
	MString s;
	s += "[ ";
	s += + M.x;
	s += " ,  ";
	s += + M.y;
	s += " , ";
	s += + M.z;
	s += " ]";
	return s;
}

void* RayTracer::creator() 
{ 
	return new RayTracer; 
}


MStatus RayTracer::doIt(const MArgList& argList) 
{
	PathTracerNS::PathTracer_SetImporter(new PathTracerNS::PathTracerMayaImporter());
	PathTracerNS::PathTracer_Main();

	//ToneMappingTest(0,NULL);

	return MS::kSuccess;
}

