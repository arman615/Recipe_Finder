#include "RecipeFinder.h"
#include <iostream>
#include <fstream>

void RecipeFinder::addRecipe(const Recipe& recipe) {
    recipes.push_back(recipe);
}

std::vector<Recipe> RecipeFinder::searchRecipes(const std::vector<std::string>& queryIngredients) const {
    std::vector<Recipe> matchingRecipes;
    for (const Recipe& recipe : recipes) {
        if (isRecipeMatching(recipe, queryIngredients)) {
            matchingRecipes.push_back(recipe);
        }
    }
    return matchingRecipes;
}

bool RecipeFinder::saveRecipesToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing.\n";
        return false;
    }

    for (const Recipe& recipe : recipes) {
        file << "Name: " << recipe.getName() << "\n";
        file << "Ingredients: ";
        for (const std::string& ingredient : recipe.getIngredients()) {
            file << ingredient << ", ";
        }
        file << "\n";
        file << "Instructions: " << recipe.getInstructions() << "\n";
        file << "-------------------------\n";
    }

    file.close();
    return true;
}

bool RecipeFinder::readRecipesFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading.\n";
        return false;
    }

    recipes.clear();

    std::string line;
    std::string name;
    std::vector<std::string> ingredients;
    std::string instructions;
    while (std::getline(file, line)) {
        if (line.find("Name: ") == 0) {
            name = line.substr(6);
        } else if (line.find("Ingredients: ") == 0) {
            ingredients.clear();
            std::string ingredientsStr = line.substr(13);
            size_t pos = 0;
            while ((pos = ingredientsStr.find(", ")) != std::string::npos) {
                ingredients.push_back(ingredientsStr.substr(0, pos));
                ingredientsStr.erase(0, pos + 2);
            }
        } else if (line.find("Instructions: ") == 0) {
            instructions = line.substr(14);
            recipes.push_back(Recipe(name, ingredients, instructions));
        }
    }

    file.close();
    return true;
}

bool RecipeFinder::isRecipeMatching(const Recipe& recipe, const std::vector<std::string>& queryIngredients) const {
    for (const std::string& ingredient : queryIngredients) {
        bool found = false;
        for (const std::string& recipeIngredient : recipe.getIngredients()) {
            if (ingredient == recipeIngredient) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
