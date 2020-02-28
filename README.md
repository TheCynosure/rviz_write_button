# RViz hitl SLAM interaction tool

RViz plugin to publish a message over /write\_button so that we can write the poses from lidar slam to a file.

## Dependencies
Install [ROS](http://wiki.ros.org/ROS/Installation)

## Build
1. Add the project path to `ROS_PACKAGE_PATH`
1. Run `make`

## Run
1. Run rviz as usual:
    ```
    rosrun rviz rviz
    ```
1. Add the plugin to RViz using the "+" button on the toolbar, and select "WriteButton". If you do not see the tool listed, ensure that this repo is in your `ROS_PACKAGE_PATH`.
1. To use the tool, click on the "Write to file" button.
1. A message is published to the topic `/write_button`, of type `write_button/WriteMsgMsg`, which is also defined by this package.
