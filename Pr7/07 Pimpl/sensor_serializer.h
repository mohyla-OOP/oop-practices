#pragma once
#pragma once
#include <cstdint>
#include <memory>
#include <span>
#include <vector>

template <typename T>
class SensorSerializer
{
 public:
  SensorSerializer();
  ~SensorSerializer();  // має бути в .cpp, де Impl є повним типом!

  std::vector<uint8_t> serialize(T value) const;
  T deserialize(std::span<const uint8_t> buffer) const;
  bool inRange(T value, T min, T max) const;

 private:
  struct Impl;                  // forward declaration
  std::unique_ptr<Impl> impl_;  // жодних деталей назовні
};

// Оголошення явних інстанціонувань — компілятор не генеруватиме код тут
extern template class SensorSerializer<float>;
extern template class SensorSerializer<double>;
extern template class SensorSerializer<uint32_t>;
extern template class SensorSerializer<int16_t>;