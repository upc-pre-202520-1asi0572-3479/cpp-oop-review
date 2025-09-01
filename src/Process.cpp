#include "Process.h"
#include <iostream>
/**
 * @file Process.cpp
 * @brief Implementation of the Process class
 */

/**
 * @brief Construct a new Process:: Process object
 * @param name                  Name of the process
 * @param description           Description of the process
 * @param requiredResourceNames Names of resources required by the process
 * @param durationInUnits       Duration of the process in time units
 */
Process::Process(const std::string &name, const std::string &description,
                 const std::vector<std::string> &requiredResourceNames, const int durationInUnits)
        : Executable(name, description, requiredResourceNames, durationInUnits) {}

/**
 * @brief Add a resource to the process's resource pool
 * @param resource Unique pointer to the resource to be added
 */
void Process::addResource(std::unique_ptr<Resource> resource) {
    resourcePool.push_back(std::move(resource));
}

/**
 * @brief Add a task to the process's task list
 * @param task Unique pointer to the task to be added
 */
void Process::addTask(std::unique_ptr<Executable> task) {
    tasks.push_back(std::move(task));
}

/**
 * @brief Execute the process and its tasks
 */
void Process::execute() const {
    if (!requiredResourceNames.empty() && assignedResources.size() != requiredResourceNames.size()) {
        throw std::runtime_error("Required resource names mismatch for process: " + name);
    }
    std::cout << "Executing Process: " << name << " - " << description << std::endl;
    if (!assignedResources.empty()) {
        for (const auto* resource : assignedResources) {
            resource->use();
        }
    }

    for (const auto& task : tasks) {
        try {
            if (task->canExecute(resourcePool)) {
                task->assignResources(resourcePool);
                std::cout << " ";
                task->execute();
                task->releaseResources();
            } else {
                std::cout << task->getName() << " skipped: required resources not available." << std::endl;
            }
        } catch (const std::exception &e) {
            std::cerr << "Error executing task " << task->getName() << ": " << e.what() << std::endl;
        }
    }
}

/**
 * @brief Run the process, managing resource assignment and execution
 */
void Process::run() {
    try {
        if (requiredResourceNames.empty() || canExecute(resourcePool)) {
            if (!requiredResourceNames.empty()) {
                assignResources(resourcePool);
            }
            execute();
            releaseResources();
            std::cout << "Process '" << name << "' completed successfully.\n";
        } else {
            throw std::runtime_error("Required resource names mismatch for process: " + name);
        }
    } catch (const std::exception &e) {
        std::cerr << "Error executing process '" << name << "': " << e.what() << std::endl;
    }
}



