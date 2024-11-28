#pragma once
#include "../engine/Project.h"
#include <raylib.h>

#define PROJECT_TYPENAME Project

/// <summary>
/// Write your project code here or do what you want with it. However,
/// you MUST implement the IProject interface somehow and set the project reference!
/// See <see cref="Techstorm::IProject" /> for more information on this.
/// </summary>
/// <inheritdoc />
class Project final : public Techstorm::IProject {
public:

	using IProject::IProject;

	void preInit() override {
		// WARNING: This MUST be called before any operations that use the file registry. The only exceptions is if you are adding load functions and adding extensions
		// that need to be loaded on registration.
		IProject::preInit();

	}
};
