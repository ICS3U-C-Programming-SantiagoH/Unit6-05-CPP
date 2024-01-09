// Copyright (c) 2023 Remy Skelton All rights reserved.
//
// Created by: Remy Skelton
// Date: Dec 17, 2023
// This program will calculate the average of
// nums with user input

#include <iostream>
#include <list>
#include <stdexcept>
#include <string>

// Function to calculate the average of a list of integers
double calcAverage(const std::list<int>& listOfMarks) {
    double sum = 0;

    // Loop through the list and calculate the sum
    for (int mark : listOfMarks) {
        sum += mark;
    }

    // Calculate the average
    double average = sum / listOfMarks.size();

    // Return the calculated average
    return average;
}

int main() {
    // Create a list to store user input marks and other variables
    std::list<int> listOfMarks;
    int userMarkInt;
    double average;
    std::string userMarkStr;

    // Display program information to the user
    std::cout << "This program calculates the average of the numbers you insert." << std::endl;

    // For proper catching of errors
    while (true) {
        // Get marks as a string
        std::cout << "Enter a mark between 0 and 100 (use negative to stop): ";
        std::cin >> userMarkStr;

        try {
            // Convert userMarkStr to an integer
            userMarkInt = std::stoi(userMarkStr);

            // Check if the entered mark is greater than 100
            if (userMarkInt > 100) {
                std::cout << userMarkInt << " is greater than 100." << std::endl;
            } else if (userMarkInt < 0) {
                // break when user wants
                break;
            } else {
                // add integer to the list
                listOfMarks.push_back(userMarkInt);
            }
        } catch (std::exception) {
            // Catch and handle exceptions related to invalid input
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
        }
    }

    // Check if the user entered at least one number
    if (listOfMarks.size() == 0) {
        std::cout << "Please enter a number." << std::endl;
    } else {
        // Calculate and display the average of the marks
        average = calcAverage(listOfMarks);
        std::cout << "\nAverage of marks: " << average << std::endl;
    }
}
