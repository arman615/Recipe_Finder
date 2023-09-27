#ifndef RECIPEFINDER_H
#define RECIPEFINDER_H

#include <vector>
#include "Recipe.h"

class RecipeFinder {
public:
    void addRecipe(const Recipe& recipe);
    std::vector<Recipe> searchRecipes(const std::vector<std::string>& queryIngredients) const;
    bool saveRecipesToFile(const std::string& filename) const;
    bool readRecipesFromFile(const std::string& filename);

private:
    bool isRecipeMatching(const Recipe& recipe, const std::vector<std::string>& queryIngredients) const;
    std::vector<Recipe> recipes;
};

#endif  // RECIPEFINDER_H
