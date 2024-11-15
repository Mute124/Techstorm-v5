#pragma once
#include "project.h"
#include "EReturnCode.h"
#ifdef _DEBUG
#include <crtdbg.h>
#endif
#include <iostream>
#include <unordered_map>
#include <thread>
#include <string>
#include <memory>

namespace Techstorm::Application {
	using GameThreadInfo = std::unordered_map<std::string, bool>;

	GameThreadInfo CalculateGameThreadInfo(GameSettings& gameSettings);

	int RunUpdateThread();
	int RunPhysicsThread();
	int RunWorkerThread();
}
