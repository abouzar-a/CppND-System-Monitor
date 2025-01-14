#include "processor.h"
#include "linux_parser.h"
#include <unistd.h>



// Return the aggregate CPU utilization
float Processor::Utilization() { 
  totalJiffiesStart = LinuxParser::Jiffies();
  activeJiffiesStart = LinuxParser::ActiveJiffies();
  
  usleep(100000); // ms convert
  
  totalJiffiesEnd = LinuxParser::Jiffies();
  activeJiffiesEnd = LinuxParser::ActiveJiffies();
  
  long totalDelta = totalJiffiesEnd - totalJiffiesStart;
  long activeDelta = activeJiffiesEnd - activeJiffiesStart;
  
  if (totalDelta == 0) {
    return 0.0;
  }
  
  return float(activeDelta) / float(totalDelta); 
}