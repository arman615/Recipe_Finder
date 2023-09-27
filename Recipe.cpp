#include "Recipe.h"

Recipe::Recipe(const std::string& name, const std::vector<std::string>& ingredients, const std::string& instructions)
    : name(name), ingredients(ingredients), instructions(instructions) {}

const std::string& Recipe::getName() const {
    return name;
}

const std::vector<std::string>& Recipe::getIngredients() const {
    return ingredients;
}

const std::string& Recipe::getInstructions() const {
    return instructions;
}
