#ifndef PROCESS_H
#define PROCESS_H

#include "Executable.h"

/**
 * @brief Concrete class representing a process that can execute tasks and manage resources.
 *
 * This class inherits from Executable and implements the execute method. It can hold a pool of resources
 * and a list of tasks (also Executable objects).
 * The process can execute its tasks while managing the resources it requires.
 *
 */
class Process final : public Executable {
private:
    std::vector<std::unique_ptr<Resource>> resourcePool; ///< Resources available to the process
    std::vector<std::unique_ptr<Executable>> tasks; ///< Tasks to be executed by the process
public:
    /**
     * @brief Constructor for the Process class.
     *
     * @param name Name of the process.
     * @param description Description of the process.
     * @param requiredResourceNames Names of resources required by the process.
     * @param durationInUnits Duration of the process in time units.
     */
    Process(const std::string& name, const std::string& description,
        const std::vector<std::string>& requiredResourceNames,
        int durationInUnits);
    /**
     * @brief Adds a resource to the process's resource pool.
     *
     * @param resource Unique pointer to the resource to be added.
     */
    void addResource(std::unique_ptr<Resource> resource);
    /**
     * @brief Adds a task to the process's task list.
     *
     * @param task Unique pointer to the task (Executable) to be added.
     */
    void addTask(std::unique_ptr<Executable> task);
    /**
     * @brief Executes the process by running its tasks and managing resources.
     *
     * This method overrides the execute method from the Executable class.
     * @throw std::runtime_error if the process cannot be executed due to resource constraints or failed tasks.
     */
    void execute() const override;
    /**
     * @brief Runs the process, managing its tasks and resources.
     *
     * This method is responsible for the overall execution flow of the process.
     * @throw std::runtime_error if the process cannot be run due to resource constraints.
     */
    void run();
};
#endif //PROCESS_H