#include "ConsumableResource.h"
#include <stdexcept>
#include <iostream>
/**
 * @file ConsumableResource.cpp
 * @brief Implementation of the ConsumableResource class
 * This class represents a consumable resource with a finite capacity.
 * It provides methods to allocate, release, and use the resource.
 * The resource can be checked for availability based on its remaining capacity.
 * If the resource is depleted, a warning is logged when attempting to release it.
 */

/**
 * @brief Construct a new Consumable Resource:: Consumable Resource object
 * @param name The name of the resource
 * @param capacity The total capacity of the resource
 *
 * @throw std::invalid_argument if capacity is less than or equal to zero
 */
ConsumableResource::ConsumableResource(const std::string &name, const int capacity)
    : Resource(name, Type::Consumable), totalCapacity(capacity),
      remainingCapacity(capacity) {
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity for resource '" + name + "' must be greater than zero.");
    }
}

/**
 * @brief Check if the resource is available for use
 * @return true if the resource has remaining capacity, false otherwise
 */
bool ConsumableResource::isAvailableForUse() const {
    return remainingCapacity > 0;
}

/**
 * @brief Allocate the resource, reducing its remaining capacity by one unit
 * @throw std::runtime_error if the resource is out of capacity
 */
void ConsumableResource::allocate() {
    if (remainingCapacity <= 0) {
        throw std::runtime_error("Resource '" + name + "' is out of capacity.");
    }
    --remainingCapacity;
    isAvailable = (remainingCapacity > 0);
}

/**
 * @brief Release the resource, making it available again if it has remaining capacity
 * If the resource is depleted, a warning is logged.
 */
void ConsumableResource::release() {
    if (remainingCapacity == 0 && !isAvailable) {
        std::cerr << "Warning: Consumable resource '" + name + "' is depleted and cannot be reused until replenished."
                << std::endl;
    }
    isAvailable = (remainingCapacity > 0);
}

/**
 * @brief Use the resource, printing its current status
 */
void ConsumableResource::use() const {
    std::cout << "Using consumable resource '" + name + "' (remaining: " + std::to_string(remainingCapacity) << "/"
            << totalCapacity << " MB)\n";
}

/**
 * @brief Get the remaining capacity of the resource
 * @return The remaining capacity
 */
int ConsumableResource::getRemainingCapacity() const {
    return remainingCapacity;
}
