#ifndef TOOLS_UTIL_TOOL_H_
#define TOOLS_UTIL_TOOL_H_

namespace tools{

long long GenerateId();
bool DoubleEqual(double lhs, double rhs);
double AngleInCircle(double x, double y);
double AngleFromStartByClockInCircle(double start_x,
                                     double start_y,
                                     double center_x,
                                     double center_y,
                                     double angle_x,
                                     double angle_y);

} //namespace tools

#endif //TOOLS_UTIL_TOOL_H_
