#pragma once

#include <condition_variable>

class Runnable {
 public:
  virtual void Init() = 0;
  virtual void Periodic() = 0;
};