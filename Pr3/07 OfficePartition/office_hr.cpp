module;

module office:hr;

import office;

void HR::raise(Employee& e, double delta) {
    promote(e, delta);   // дружня функція змінює salary коректно
}