#include "sensor_serializer.h"

#include <cstring>
#include <stdexcept>

// ---- Ось де живуть "секрети" ----
// Можна підключати важкі заголовки, треті сторони тощо —
// користувач бібліотеки їх не побачить і не перекомпілює

template <typename T>
struct SensorSerializer<T>::Impl
{
  // Наприклад, тут міг би бути стан: версія протоколу, ендіанність...
  uint8_t protocol_version = 1;

  std::vector<uint8_t> do_serialize(T value) const
  {
    // Заголовок: [version | size | payload...]
    std::vector<uint8_t> result;
    result.push_back(protocol_version);
    result.push_back(static_cast<uint8_t>(sizeof(T)));
    result.resize(result.size() + sizeof(T));
    std::memcpy(result.data() + 2, &value, sizeof(T));
    return result;
  }

  T do_deserialize(std::span<const uint8_t> buffer) const
  {
    if (buffer.size() < 2 + sizeof(T)) throw std::runtime_error("Buffer too small");
    if (buffer[1] != sizeof(T)) throw std::runtime_error("Type size mismatch");
    T value;
    std::memcpy(&value, buffer.data() + 2, sizeof(T));
    return value;
  }
};

// ---- Методи делегують до Impl ----

template <typename T>
SensorSerializer<T>::SensorSerializer() : impl_(std::make_unique<Impl>())
{
}

template <typename T>
SensorSerializer<T>::~SensorSerializer() = default;  // тут Impl — повний тип ✓

template <typename T>
std::vector<uint8_t> SensorSerializer<T>::serialize(T value) const
{
  return impl_->do_serialize(value);
}

template <typename T>
T SensorSerializer<T>::deserialize(std::span<const uint8_t> buffer) const
{
  return impl_->do_deserialize(buffer);
}

template <typename T>
bool SensorSerializer<T>::inRange(T value, T min, T max) const
{
  return value >= min && value <= max;
}

// ---- Явне інстанціонування — одне місце для всього ----
template class SensorSerializer<float>;
template class SensorSerializer<double>;
template class SensorSerializer<uint32_t>;
template class SensorSerializer<int16_t>;