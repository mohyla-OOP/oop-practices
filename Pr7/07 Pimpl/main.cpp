#include <iostream>

#include "sensor_serializer.h"

int main()
{
  SensorSerializer<float> tempSensor;

  auto bytes = tempSensor.serialize(36.6f);
  float temp = tempSensor.deserialize(bytes);
  std::cout << "Temp: " << temp << "°C\n";

  SensorSerializer<uint32_t> counter;
  std::cout << "Valid: " << counter.inRange(500u, 0u, 1000u) << "\n";
}