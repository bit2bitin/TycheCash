// Copyright (c) 2017-2018 The TycheCash developers  ; Originally forked from Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers 
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "Common/SignalHandler.h"

#include "Logging/LoggerGroup.h"
#include "Logging/ConsoleLogger.h"
#include "Logging/LoggerRef.h"

#include "MinerManager.h"

#include <System/Dispatcher.h>

int main(int argc, char** argv) {
  try {
    TycheCash::MiningConfig config;
    config.parse(argc, argv);

    if (config.help) {
      config.printHelp();
      return 0;
    }

    Logging::LoggerGroup loggerGroup;
    Logging::ConsoleLogger consoleLogger(static_cast<Logging::Level>(config.logLevel));
    loggerGroup.addLogger(consoleLogger);

    System::Dispatcher dispatcher;
    Miner::MinerManager app(dispatcher, config, loggerGroup);

    app.start();
  } catch (std::exception& e) {
    std::cerr << "Fatal: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
