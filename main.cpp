#include "Process.h"
#include "Task.h"
#include "UsableResource.h"
#include "ConsumableResource.h"
#include <iostream>

int main() {
    const auto compilationProcess = std::unique_ptr<Process>(
new Process("Compilation Process", "Compilation Process description",
    { "CentralProcessingUnit", "Memory"}, 15));
    compilationProcess->addResource(
        std::unique_ptr<UsableResource>(new UsableResource("CentralProcessingUnit", 4)));
    compilationProcess->addResource(std::unique_ptr<ConsumableResource>(new ConsumableResource("Memory", 4096)));

}