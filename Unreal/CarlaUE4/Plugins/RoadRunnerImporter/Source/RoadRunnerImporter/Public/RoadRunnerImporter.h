// Copyright 2020 The MathWorks, Inc.

#pragma once

#include "RoadRunnerUtil.h"
#if RR_VERSION_UP_TO(4,16)
#error The RoadRunner import plugin only supports Unreal Engine version 4.17 and up.
#endif

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include <UnrealEd.h>


////////////////////////////////////////////////////////////////////////////////
// Imports FBX files with RoadRunner metadata
//	- Parses metadata XML lookaside file to set material properties and other attributes.
//	- Material instances are created from the base materials located in the
//      RoadRunnerMaterials plugin.
//  - Sets up signal components after importing.
class FRoadRunnerImporterModule : public IModuleInterface
{
public:
	// Asset processing delegates
	static void RoadRunnerPostProcessing(UFactory* inFactory, UObject* inCreateObject);

	// IModuleInterface implementation
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	static const int PluginVersion = 5;
	static const int32 TransparentRenderQueue = 1000;
};
