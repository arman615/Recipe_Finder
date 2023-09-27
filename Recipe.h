#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

class Recipe {
public:
    Recipe(const std::string& name, const std::vector<std::string>& ingredients, const std::string& instructions);

    const std::string& getName() const;
    const std::vector<std::string>& getIngredients() const;
    const std::string& getInstructions() const;

private:
    std::string name;
    std::vector<std::string> ingredients;
    std::string instructions;
};

#endif  // RECIPE_H
