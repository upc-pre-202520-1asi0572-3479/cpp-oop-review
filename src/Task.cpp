#include "Task.h"
#include <iostream>
/**
 * @file Task.cpp
 * @brief Implementation of the Task class
 */

/**
 * @brief Construct a new Task:: Task object
 * @param name                  Task name
 * @param description           Task description
 * @param requiredResourceNames Names of resources required for the task
 * @param durationInUnits       Duration of the task in time units
 */
Task::Task(const std::string &name, const std::string &description,
           const std::vector<std::string> &requiredResourceNames, const int durationInUnits)
        : Executable(name, description, requiredResourceNames, durationInUnits) {}

/**
 * @brief Execute the task by utilizing its assigned resources
 * @throws std::runtime_error if resources are not properly assigned
 */
void Task::execute() const {
    if (assignedResources.size() != requiredResourceNames.size()) {
        throw std::runtime_error("Resources not properly assigned for task: '" + name + "'");
    }
    std::cout << "Executing Task: '" << name << "' (Duration: " << durationInUnits << " units)\n";
    for (const auto* resource: assignedResources) {
        resource->use();
    }
}

