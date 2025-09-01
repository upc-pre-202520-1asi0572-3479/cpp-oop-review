#include "Executable.h"
#include <stdexcept>
#include <algorithm>
#include <iostream>
/**
 * @file Executable.cpp
 * @brief Implementation of the Executable class methods.
 * This file contains the definitions of the methods declared in Executable.h.
 */

/**
 * @brief Constructor for the Executable class.
 * @param name                  Unique identifier for the executable.
 * @param description           Description of the executable's purpose.
 * @param requiredResourceNames Names of resources required by the executable.
 * @param durationInUnits       Duration of the executable in time units.
 */
Executable::Executable(const std::string &name, const std::string description,
                       const std::vector<std::string> &requiredResourceNames, const int durationInUnits)
        : name(name), description(std::move(description)),
requiredResourceNames(requiredResourceNames),
durationInUnits(durationInUnits), assignedResources(){
    if (name.empty()) throw std::invalid_argument("Executable name cannot be empty");
    if (durationInUnits <= 0) throw std::invalid_argument("Duration for '" + name + "' must be positive");
}

/**
 * @brief Retrieves the name of the executable.
 */
std::string Executable::getName() const {
    return name;
}

/**
 * @brief Retrieves the names of resources required by the executable.
 * @return A constant reference to the vector of required resource names.
 */
const std::vector<std::string> &Executable::getRequiredResourceNames() const {
    return requiredResourceNames;
}

/**
 * @brief Retrieves the duration of the executable in time units.
 * @return The duration in time units.
 */
int Executable::getDurationInUnits() const {
    return durationInUnits;
}

/**
 * @brief Assigns resources from the provided resource pool to the executable.
 * @param resourcePool A vector of unique pointers to available resources.
 *
 * @throw std::runtime_error if any required resource is not available.
 */
void Executable::assignResources(const std::vector<std::unique_ptr<Resource> > &resourcePool) {
    assignedResources.clear();
    if (requiredResourceNames.empty()) return;

    for (const auto &resourceName: requiredResourceNames) {
        bool found = false;
        for (auto &resource: resourcePool) {
            if (resource->getName() == resourceName && resource->isAvailableForUse()) {
                resource->allocate();
                assignedResources.push_back(resource.get());
                found = true;
                break;
            }
        }
        if (!found) {
            // Release already assigned resources before throwing
            releaseResources();
            throw std::runtime_error("Resource '" + resourceName + "' is not available for executable '" + name + "'");
        }
    }
}

/**
 * @brief Releases all currently assigned resources from the executable.
 */
void Executable::releaseResources() {
    for (auto *resource: assignedResources) {
        try {
            resource->release();
        } catch (std::exception &e) {
            std::cerr << "Warning: Failed to release resource '" << resource->getName()
                      << "' for executable '" << name << "': " << e.what() << "\n";
        }
    }
    assignedResources.clear();
}

/**
 * @brief Checks if the executable can be executed with the available resources.
 * @param resourcePool A vector of unique pointers to available resources.
 * @return True if the executable can be executed, false otherwise.
 */
bool Executable::canExecute(const std::vector<std::unique_ptr<Resource> > &resourcePool) const {
    if (requiredResourceNames.empty()) {
        std::cout << getName() << " does not have required resources\n";
        return true;
    }
    for (const auto &resourceName: requiredResourceNames) {
        if (std::none_of(resourcePool.begin(), resourcePool.end(),
            [&resourceName](const std::unique_ptr<Resource> &resource) {
                return resource->getName() == resourceName && resource->isAvailableForUse();
            })) {
            return false;
        }
    }
    return true;
}


