#include <iostream>
#include <vector>
#include "Recipe.h"
#include "RecipeFinder.h"

void viewRecipe(const Recipe& recipe);

Recipe createRecipe() {
    std::string name, ingredient, instruction;
    std::vector<std::string> ingredients;
    std::cout << "Enter Recipe Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter Ingredients (Enter 'done' when finished):\n";
    while (true) {
        std::getline(std::cin, ingredient);
        if (ingredient == "done") {
            break;
        }
        ingredients.push_back(ingredient);
    }

    std::cout << "Enter Instructions:\n";
    std::getline(std::cin, instruction);

    return Recipe(name, ingredients, instruction);
}

int main() {
    RecipeFinder recipeFinder;

    Recipe recipe1("Pasta", { "pasta", "tomato sauce", "cheese" }, "1. Cook pasta. 2. Add tomato sauce. 3. Sprinkle cheese.");
    Recipe recipe2("Salad", { "hazar", "tomato", "cucumber", "olives" }, "1. Mix all ingredients. 2. Add dressing.");

    recipeFinder.addRecipe(recipe1);
    recipeFinder.addRecipe(recipe2);

    recipeFinder.saveRecipesToFile("recipes.txt");

    recipeFinder = RecipeFinder();

    if (!recipeFinder.readRecipesFromFile("recipes.txt")) {
        return 1;
    }

    std::vector<std::string> queryIngredients = { "pasta", "tomato sauce" };
    std::vector<Recipe> matchingRecipes = recipeFinder.searchRecipes(queryIngredients);

    if (matchingRecipes.empty()) {
        std::cout << "No recipes found with the given ingredients.\n";
    } else {
        std::cout << "Matching recipes:\n";
        for (const Recipe& recipe : matchingRecipes) {
            viewRecipe(recipe);
        }
    }

    Recipe newRecipe = createRecipe();
    recipeFinder.addRecipe(newRecipe);

    recipeFinder.saveRecipesToFile("recipes.txt");

    return 0;
}

void viewRecipe(const Recipe& recipe) {
    std::cout << "Recipe Name: " << recipe.getName() << std::endl;
    std::cout << "Ingredients: ";
    for (const std::string& ingredient : recipe.getIngredients()) {
        std::cout << ingredient << ", ";
    }
    std::cout << std::endl;
    std::cout << "Instructions: " << recipe.getInstructions() << std::endl;
    std::cout << "-------------------------\n";
}
