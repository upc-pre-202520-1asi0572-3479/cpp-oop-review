#ifndef TASK_H
#define TASK_H

#include "Executable.h"

/**
 * @brief Represents a task that can be executed.
 *
 * This class is a concrete implementation of the Executable interface.
 * It encapsulates the details of a task, including its name, description,
 * required resources, and duration.
 */
class Task final : public Executable {
public:
    /**
     * @brief Constructs a Task object.
     * @param name The name of the task.
     * @param description A brief description of the task.
     * @param requiredResourceNames A list of names of resources required to execute the task.
     * @param durationInUnits The duration of the task in arbitrary time units.
     */
    Task(const std::string& name, const std::string& description,
        const std::vector<std::string>& requiredResourceNames, int durationInUnits);

    /**
     * @brief Executes the task using the assigned resources.
     * @throw std::runtime_error if the task cannot be executed due to insufficient resources.
     */
    void execute() const override;
};
#endif //TASK_H