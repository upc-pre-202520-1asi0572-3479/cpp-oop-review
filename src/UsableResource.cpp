#include "UsableResource.h"
#include <iostream>
#include <stdexcept>

/**
 * @file UsableResource.cpp
 * @brief Represents a resource that can be used (e.g., CPU, Memory).
 *
 * This class extends the Resource class and provides functionality specific to usable resources.
 * It includes methods to check availability, allocate, release, and use the resource.
 */

/**
 * @brief Constructor for UsableResource.
 * @param name Name of the resource.
 * @param capacity Capacity of the resource (e.g., in GHz for CPU).
 *
 * @throw std::invalid_argument if capacity is non-positive.
 */
UsableResource::UsableResource(const std::string &name, const int capacity)
    : Resource(name, Type::Usable), capacity(capacity){
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource '" + name + "' must be positive.");
    }
}

/**
 * @brief Check if the resource is available for use.
 * @return True if the resource is available, false otherwise.
 */
bool UsableResource::isAvailableForUse() const {
    return isAvailable;
}

/**
 * @brief Allocate the resource for use.
 * @throws std::runtime_error if the resource is already allocated.
 */
void UsableResource::allocate() {
    if (!isAvailable) {
        throw std::runtime_error("Usable resource '" + name + "' is already allocated.");
    }
    isAvailable = false;
}

/**
 * @brief Release the resource after use.
 * If the resource is already available, a warning is printed.
 */
void UsableResource::release() {
    if (isAvailable) {
        std::cerr << "Warning: Usable resource '" << name << "' is already released." << std::endl;
    }
}

/**
 * @brief Use the resource.
 * This method simulates using the resource and prints its details.
 */
void UsableResource::use() const {
    std::cout << "  Using usable resource: '" << name << "' (capacity: " << capacity << " GHz)\n";
}




