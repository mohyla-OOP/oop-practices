#pragma once
#include <stdexcept>
#include <string>
#include <format>
#include <ostream>   // std::ostream
#include <chrono>
#include <ctime>
using namespace std::chrono;

// 1) Сильний перелік місяців із базою 1..12
enum class Month /*: int*/ {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

// Утиліти перетворення
constexpr int to_int(Month m) noexcept {
    return static_cast<int>(m);
}

inline Month month_from_int(int value) {
    if (value < 1 || value > 12) {
        throw std::out_of_range("Month must be in [1..12]");
    }
    return static_cast<Month>(value);
}

// 2) Календарні утиліти
constexpr bool is_leap(int y) noexcept {
    // Правило Григоріанського календаря
    return (y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0));
}

constexpr int days_in_month(int y, Month m) {
    switch (m) {
    case Month::jan: case Month::mar: case Month::may: case Month::jul:
    case Month::aug: case Month::oct: case Month::dec:
        return 31;
    case Month::apr: case Month::jun: case Month::sep: case Month::nov:
        return 30;
    case Month::feb:
        return is_leap(y) ? 29 : 28;
    }
    // До цього місця не маємо доходити, але повернемо щось безпечне
    return 31;
}

// 3) Клас Date з інваріантами
class Date {
public:
    // Базовий конструктор з Month
    Date(int y, Month m, int d) : _y(y), _m(m), _d(d) {
        // Інваріанти
        if (to_int(_m) < 1 || to_int(_m) > 12) {
            throw std::out_of_range("Month must be in [1..12]");
        }
        int dim = days_in_month(_y, _m);
        if (_d < 1 || _d > dim) {
            throw std::out_of_range("Day out of range for the given month/year");
        }
    }

    // Адаптер для сумісності зі старим кодом (місяць як int)
    Date(int y, int m, int d) : Date(y, month_from_int(m), d) {}

    Date() {

        auto now = system_clock::now();
        std::time_t t = system_clock::to_time_t(now);
        std::tm localTime = *std::localtime(&t);

        _d = localTime.tm_mday;
        _m = static_cast<Month>(localTime.tm_mon + 1);  // tm_mon рахує від 0
        _y = localTime.tm_year + 1900; // tm_year рахує від 1900
    }


    // Доступ до полів
    int   year()  const noexcept { return _y; }
    Month month() const noexcept { return _m; }
    int   day()   const noexcept { return _d; }
    
    // Форматування: "YYYY-MM-DD"
    //std::string to_string() const {
    //    char buf[16];
    //    std::snprintf(buf, sizeof(buf), "%04d-%02d-%02d", _y, to_int(_m), _d);
    //    return std::string(buf);
    
    // Форматування: "YYYY-MM-DD"
    std::string to_string() const {
        return std::format("{:04}-{:02}-{:02}", _y, to_int(_m), _d);
    }

    // Зручність: наступний день
    Date next_day() const {
        Date t = *this;
        t.add_days(1);
        return t;
    }

    // Зручність: попередній день
    Date prev_day() const {
        Date t = *this;
        t.add_days(-1);
        return t;
    }

    // Арифметика за днями (простий, навчальний алгоритм крокування)
    Date& add_days(int delta) {
        if (delta == 0) return *this;

        if (delta > 0) {
            while (delta > 0) {
                int dim = days_in_month(_y, _m);
                int left_in_month = dim - _d;
                if (delta <= left_in_month) {
                    _d += delta;
                    return *this;
                }
                // Перейти на 1-й день наступного місяця
                delta -= (left_in_month + 1);
                _d = 1;
                if (_m == Month::dec) { _m = Month::jan; ++_y; }
                else { _m = static_cast<Month>(to_int(_m) + 1); }
            }
        }
        else {
            delta = -delta;
            while (delta > 0) {
                if (delta < _d) {
                    _d -= delta;
                    return *this;
                }
                // Перейти на кінець попереднього місяця
                delta -= _d;
                if (_m == Month::jan) { _m = Month::dec; --_y; }
                else { _m = static_cast<Month>(to_int(_m) - 1); }
                _d = days_in_month(_y, _m);
            }
        }
        return *this;
    }

    // Порівняння (C++17-сумісно)
    friend bool operator==(const Date& a, const Date& b) noexcept {
        return a._y == b._y && a._m == b._m && a._d == b._d;
    }
    friend bool operator!=(const Date& a, const Date& b) noexcept { return !(a == b); }

    friend bool operator<(const Date& a, const Date& b) noexcept {
        if (a._y != b._y) return a._y < b._y;
        int am = to_int(a._m), bm = to_int(b._m);
        if (am != bm) return am < bm;
        return a._d < b._d;
    }
    friend bool operator>(const Date& a, const Date& b) noexcept { return b < a; }
    friend bool operator<=(const Date& a, const Date& b) noexcept { return !(b < a); }
    friend bool operator>=(const Date& a, const Date& b) noexcept { return !(a < b); }

private:
    int   _y;
    Month _m;
    int   _d;
};

// 4) Прості I/O утиліти

// Вивід у потік як "YYYY-MM-DD"
inline std::ostream& operator<<(std::ostream& os, const Date& d) {
    return os << d.to_string();
}

// Парсинг "YYYY-MM-DD" з базовою перевіркою.
// Для 3-ї лекції — без складної валідації формату.
//inline Date parse_yyy_ymm_dd(const std::string& s) {
//    int y = 0, m = 0, d = 0;
//    if (std::sscanf(s.c_str(), "%d-%d-%d", &y, &m, &d) != 3) {
//        throw std::invali_dargument("Invalid date format, expected YYYY-MM-DD");
//    }
//    return Date(y, m, d); // інваріанти перевіряються в конструкторі
//}

Date parse_yyy_ymm_dd(const std::string& s) {
    if (s.size() != 10 || s[4] != '-' || s[7] != '-') {
        throw std::invalid_argument("Expected YYYY-MM-DD format");
    }

    int y = std::stoi(s.substr(0, 4));
    int m = std::stoi(s.substr(5, 2));
    int d = std::stoi(s.substr(8, 2));

    return Date(y, m, d);   // інваріанти всередині конструктора
}
