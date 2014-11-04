#include <sys/types.h>
#include <dirent.h>

#include <iostream>
#include <fstream>
#include <memory>

#include "GPIOConst.h"
#include "PWMManager.h"

PWMManager::PWMManager()
{
  enablePWM();
}

PWMManager::~PWMManager()
{
}

PWMManager& PWMManager::instance()
{
  static PWMManager obj;
  return obj;
}

bool PWMManager::enablePWM()
{
  std::ofstream stream("/sys/devices/bone_capemgr.9/slots");
  if (stream.fail())
  {
    // TODO: Show a clear error message!
    // And in another PWM methods too...
    std::cerr << "Error" << std::endl;
    return false;
  }

  stream << "am33xx_pwm";

  stream.close();

  std::cout << "echo am33xx_pwm > /sys/devices/bone_capemgr.9/slots" << std::endl;
  return true;
}

bool PWMManager::exportPWM(unsigned int pwm)
{
  std::ofstream stream("/sys/devices/bone_capemgr.9/slots");
  stream << "bone_pwm_" << GPIO::GPIOConst::instance().getGpioKeyByPin(pwm);
  stream.close();

  std::cout << "echo " << "bone_pwm_" << GPIO::GPIOConst::instance().getGpioKeyByPin(pwm) << " > /sys/devices/bone_capemgr.9/slots" << std::endl;
  return true;
}

namespace
{
  // TODO: The slow operation, maybe we have to optimize it and cache a value somewhere...
  bool getPWMDirectory(unsigned int pwm, std::string *output)
  {
    std::string path("/sys/devices/ocp.3/");
    std::string baseName("pwm_test_");
    baseName += GPIO::GPIOConst::instance().getGpioKeyByPin(pwm);

    std::shared_ptr<DIR> dp(opendir("/sys/devices/ocp.3"), closedir);
    dirent *dirp;
    if (!dp)
    {
      std::cerr << "Cannot open the directory /sys/devices/ocp.3" << std::endl;
      return false;
    }

    while ((dirp = readdir(dp.get())) != nullptr)
    {
      if (std::string(dirp->d_name).substr(0, baseName.length()) == baseName)
      {
        std::cout << "Dir name: " << dirp->d_name << std::endl;
        *output = path + dirp->d_name;
        return true;
      }
    }

    return false;
  }
}

bool PWMManager::setPolarity(unsigned int pwm, int polarity)
{
  std::string fileName;
  if (!getPWMDirectory(pwm, &fileName))
    return false;

  std::ofstream stream((fileName + "/polarity").c_str());
  std::cout << "echo " << polarity << " > " << fileName << "/polarity" << std::endl;
  if (stream.fail())
    return false;

  stream << polarity;
  stream.close();

  return true;
}

bool PWMManager::setDuty(unsigned int pwm, int duty)
{
  std::string fileName;
  if (!getPWMDirectory(pwm, &fileName))
    return false;

  std::ofstream stream((fileName + "/duty").c_str());
  std::cout << "echo " << duty << " > " << fileName << "/duty" << std::endl;
  if (stream.fail())
    return false;

  stream << duty;
  stream.close();

  return true;
}

bool PWMManager::setPeriod(unsigned int pwm, int period)
{
  std::string fileName;
  if (!getPWMDirectory(pwm, &fileName))
    return false;

  std::ofstream stream((fileName + "/period").c_str());
  std::cout << "echo " << period << " > " << fileName << "/period" << std::endl;
  if (stream.fail())
    return false;

  stream << period;
  stream.close();

  return true;
}
