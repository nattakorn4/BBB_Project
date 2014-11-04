#pragma once

class PWMManager
{
  PWMManager();
  ~PWMManager();
  bool enablePWM();
public:
  static PWMManager& instance();

  bool exportPWM(unsigned int pwm);
  // TODO: Maybe create an enum for polarity?
  bool setPolarity(unsigned int pwm, int polarity);
  // https://en.wikipedia.org/wiki/Duty_cycle
  bool setDuty(unsigned int pwm, int duty);
  bool setPeriod(unsigned int pwm, int period);
};
