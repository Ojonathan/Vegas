#ifndef COLOR_H
#define COLOR_H

/**
 * @brief     Couleur possible pour un joueur.
 * @details   La table de correspondance de couleurs est la suivant.
 * @author  Ordoñez Jonathan
 * @date    Octobre 2016
 */
enum class Color{
    green,          /*!< Couleur vert rgb(0, 204, 0) */
    violet,         /*!< Couleur violet rgb(178, 102, 205) */
    yellow,         /*!< Couleur jaune rgb(255, 255, 51) */
    white,          /*!< Couleur blanc rgb(255,255,255) */
    black,          /*!< Couleur noir rgb(82, 82, 82) */
    blue,           /*!< Couleur bleu rgb(0, 128, 255) */
    red,            /*!< Couleur rouge rgb(0, 128, 255) */
    grey            /*!< Couleur gris rgb(202, 201, 201) */
};

inline std::ostream & operator<<(std::ostream & out, Color color) {
    switch(color) {
        case Color::green: return out << "green";
        case Color::violet: return out << "violet";
        case Color::yellow: return out << "yellow";
        case Color::white: return out << "white";
        case Color::black: return out << "black";
        case Color::blue: return out << "blue";
        case Color::red: return out << "red";
        case Color::grey: return out << "grey";
    }
}
#endif // COLOR_H
