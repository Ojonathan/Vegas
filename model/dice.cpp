#include "dice.h"

//contructor
Dice::Dice(Color color){
    this-> value = 0;
    this->color = color;
    this->big = false;
}

//getters
int Dice::get_value() const{
    return value;
}

Color Dice::get_color()const{
    return color;
}

bool Dice::is_big() const{
    return big;
}

//setters
void Dice::set_value(int value){
    this->value = value;
}

void Dice::set_color(Color color){
    this->color = color;
}

void Dice::set_big(bool _big){
    big = _big;
}

std::ostream & operator<<(std::ostream & out, const Dice & c){
    out << "value " << c.value << " , color : " << c.color;
    return out;
}
