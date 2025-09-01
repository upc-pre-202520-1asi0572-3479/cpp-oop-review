#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include "Resource.h"
#include <string>
#include <vector>

/**
 * @class Executable
 * @brief Abstract base class representing an executable task that requires resources.
 *
 * The Executable class encapsulates the properties and behaviors of a task that can be executed
 * given the necessary resources. It includes methods for assigning and releasing resources,
 * checking execution feasibility, and executing the task.
 */
class Executable {
protected:
    std::string name; ///< Unique identifier for the executable.
    std::string description; ///< Description of the executable's purpose.
    std::vector<std::string> requiredResourceNames; ///< Names of resources required by the executable.
    int durationInUnits; ///< Duration of the executable in time units.
    std::vector<Resource*> assignedResources; ///< Pointers to currently assigned resources.
public:
    /**
     * @brief Constructor for the Executable class.
     * @param name Unique identifier for the executable.
     * @param description Description of the executable's purpose.
     * @param requiredResourceNames Names of resources required by the executable.
     * @param durationInUnits Duration of the executable in time units.
     */
    Executable(const std::string &name, const std::string &description,
        const std::vector<std::string> &requiredResourceNames, int durationInUnits);

    /**
     * @brief Virtual destructor for the Executable class.
     */
    virtual ~Executable();

    /**
     * @brief Retrieves the name of the executable.
     * @return The name of the executable.
     */
    [[nodiscard]] const std::string getName() const;

    /**
     * @brief Retrieves the description of the executable.
     * @return A constant reference to the description string.
     */
    [[nodiscard]] const std::vector<std::string>& getRequiredResourceNames() const;
    /**
     * @brief Retrieves the duration of the executable in time units.
     * @return The duration in time units.
     */
    [[nodiscard]] int getDurationInUnits() const;
    /**
     * @brief Assigns resources from the provided resource pool to the executable.
     * @param resourcePool A vector of unique pointers to available resources.
     */
    void assignResources(const std::vector<std::unique_ptr<Resource>>& resourcePool);
    /**
     * @brief Releases all currently assigned resources from the executable.
     */
    void releaseResources();
    /**
     * @brief Executes the task represented by the executable.
     * This is a pure virtual function that must be implemented by derived classes.
     */
    virtual void execute() const = 0;
    /**
     * @brief Checks if the executable can be executed with the available resources.
     * @param resourcePool A vector of unique pointers to available resources.
     * @return True if the executable can be executed, false otherwise.
     */
    [[nodiscard]] bool canExecute(const std::vector<std::unique_ptr<Resource>>& resourcePool) const;
};

#endif //EXECUTABLE_H
