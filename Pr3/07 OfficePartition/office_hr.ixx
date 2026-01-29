module;

export module office:hr;
import office;

// Структура зовні невидима
struct HR {
    static void raise(Employee& e, double delta) {
        promote(e, delta);
    }
};