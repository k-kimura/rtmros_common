#include <iostream>
#include <sys/time.h>
#include "ros/ros.h"
#include "hrpsys_ros_bridge/OpenHRP_StabilizerService_setSegwayParameter.h"

char *time_string()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  struct tm *tm_ = localtime(&tv.tv_sec);
  static char time[20];
  sprintf(time, "%02d:%02d:%02d.%06d", tm_->tm_hour, tm_->tm_min, tm_->tm_sec, (int)tv.tv_usec);
  return time;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "CallsetSegwayParameter");
  ros::NodeHandle n;

  ros::ServiceClient client = n.serviceClient<hrpsys_ros_bridge::OpenHRP_StabilizerService_setSegwayParameter>("StabilizerServiceROSBridge/setSegwayParameter");

  hrpsys_ros_bridge::OpenHRP_StabilizerService_setSegwayParameter srv;
  srv.request.i_param.segway_param = 0.0; // set value of segway_param

  std::cerr << "localtime before rosservice call: [" << time_string() << "]" << std::endl;
  if (client.call(srv))
    {
      std::cerr << "localtime after rosservice call: [" << time_string() << "]" << std::endl;
      // we can use srv.response (but in this case, it's void)
      ROS_INFO("Succeed");
    }
  else
    {
      ROS_ERROR("Failed");
      return 1;
    }
  return 0;
}
