#pragma once
#include "rlbot_generated.h"

#include "controller.h"
#include "matchsettings.h"
#include "statesetting.h"

#include <string>
#if defined(_WIN32) || defined(__CYGWIN__)
#if defined(_WIN64) || defined(__x86_64__)
#define DLLNAME "RLBot_Core_Interface.dll"
#else
#if defined(_WIN32) || defined(__i686__)
#define DLLNAME "RLBot_Core_Interface_32.dll"
#endif
#endif
#endif


#if defined(__linux__)
#define DLLNAME "libRLBotInterface.so" 
#endif

namespace rlbot {
struct ByteBuffer {
  void *ptr;
  int32_t size;
};

class Interface {
private:
  static bool isLoaded;

public:
  static void LoadInterface(std::string dll);
  static bool IsInitialized();
  static bool IsInterfaceLoaded();
  static void Free(void *ptr);

  static ByteBuffer UpdateLiveDataPacketFlatbuffer();
  static ByteBuffer UpdateFieldInfoFlatbuffer();
  static ByteBuffer GetBallPrediction();
  static ByteBuffer GetMatchSettings();

  static int SetBotInput(Controller input, int index);
  static int RenderGroup(void *data, flatbuffers::uoffset_t size);
  static int SendQuickChat(rlbot::flat::QuickChatSelection message,
                           int botIndex, bool teamOnly);
  static int SetGameState(GameState state);
  static int StartMatch(MatchSettings settings);
};
} // namespace rlbot
