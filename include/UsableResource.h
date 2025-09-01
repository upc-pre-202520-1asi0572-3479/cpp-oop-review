#ifndef USABLE_RESOURCE_H
#define USABLE_RESOURCE_H

#include "Resource.h"

/**
 * @brief Usable resource that is occupied during use, such as CPU.
 *
 * This class extends the Resource class to represent resources that can be used
 * by entities in a simulation. It includes methods to check availability, allocate,
 * release, and use the resource.
 */
class UsableResource final : public Resource {
private:
    int capacity; ///< Fixed capacity of the usable resource
public:
    /**
     * @brief Constructor to initialize the usable resource with a name and capacity.
     *
     * @param name Name of the resource.
     * @param capacity Fixed capacity of the resource.
     */
    UsableResource(const std::string& name, int capacity);
    /**
     * @brief Check if the resource is available for use.
     * @return True if the resource is available, false otherwise.
     */
    [[nodiscard]] bool isAvailableForUse() const override;
    /**
     * @brief Allocate the resource for use.
     * @throw std::runtime_error if the resource is already allocated.
     */
    void allocate() override;
    /**
     * @brief Release the resource after use.
     */
    void release() override;
    /**
     * @brief Use the resource.
     */
    void use() const override;
};
#endif //USABLE_RESOURCE_H