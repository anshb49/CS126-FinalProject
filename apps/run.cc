// Copyright (c) 2020 [Your Name]. All rights reserved.
#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>
#include <gflags/gflags.h>
#include "my_app.h"

using cinder::app::App;
using cinder::app::RendererGl;

namespace myapp {

const int kSamples = 8;
const int kWidth = 800;
const int kHeight = 800;

DEFINE_string(name, "Random Player", "the name of the player");
DEFINE_uint32(level, 1, "the level of the game");

void ParseArgs(vector<string>* args) {
  gflags::SetUsageMessage(
      "Play a game of Escape. Pass --helpshort for options.");
  int argc = static_cast<int>(args->size());
  vector<char*> argvs;
  for (string& str : *args) {
    argvs.push_back(&str[0]);
  }

  char** argv = argvs.data();
  gflags::ParseCommandLineFlags(&argc, &argv, true);
}

void SetUp(App::Settings* settings) {
  vector<string> args = settings->getCommandLineArgs();
  ParseArgs(&args);
  settings->setWindowSize(kWidth, kHeight);
  settings->setTitle("ESCAPE");
  std::srand(std::time(0));
}

}  // namespace myapp


// This is a macro that runs the application.
CINDER_APP(myapp::MyApp,
           RendererGl(RendererGl::Options().msaa(myapp::kSamples)),
           myapp::SetUp)
