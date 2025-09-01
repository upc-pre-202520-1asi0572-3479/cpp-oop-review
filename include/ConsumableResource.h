#ifndef CONSUMABLE_RESOURCE_H
#define CONSUMABLE_RESOURCE_H

#include "Resource.h"

/**
 * @brief Consumable resource that depletes with use, such as memory.
 *
 * This class represents a resource that has a finite capacity and can be consumed.
 * Once the resource is used, its remaining capacity decreases.
 * If the remaining capacity reaches zero, the resource is no longer available for use.
 */
class ConsumableResource final : public Resource {
private:
    int totalCapacity;
    int remainingCapacity;
public:
    /**
     * @brief Construct a new Consumable Resource object
     * @param name Name of the resource
     * @param capacity Capacity of the resource
     */
    ConsumableResource(const std::string &name, int capacity);

    /**
     * @brief Check if the resource is available for use
     * @return true if the resource has remaining capacity, false otherwise
     */
    [[nodiscard]] bool isAvailableForUse() const override;
    /** @brief Allocate the resource
     * This method does not change the remaining capacity.
     */
    void allocate() override;
    /** @brief Release the resource
     * This method does not change the remaining capacity.
     */
    void release() override;
    /** @brief Display the resource details, including remaining capacity.
     */
    void use() const override;
    /** @brief Retrieve the remaining capacity of the resource.
     * @return Remaining capacity of the resource in units (e.g., MB).
     */
    [[nodiscard]] int getRemainingCapacity() const;
};
#endif //CONSUMABLE_RESOURCE_H